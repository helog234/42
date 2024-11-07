#include "MngmtServers.hpp"

// fichier fdConfig imaginé sans retour à la ligne à part pour différents serveurs:
// server1: root:/html index:index.html,index.htm error:404,not_found.html
// error:500,error.html listing:true name:mywebserv listen:8888
// Limitations:client_max_body_size 8M; ??
// server2:root:/html index:index.html etc.

// note il faut qu'on trouve un moyen pour pouvoir passer
// la valeur de la taille des fichiers ()
//  • k or K: Kilobytes
//  • m or M: Megabytes
//  • g or G: Gigabytes

// constructeur du gestionnaire de serveurs
// il va découper le fichier en ligne (chacune représentant un serveur)
// et ajouter un serveur au veteur de ServerDatas
ManagementServer::ManagementServer(HttpConfig &config)
{
	std::string line;

	std::vector<HttpConfig::ServerConfig>::iterator it = config.getParsedServers().begin();

	while (it != config.getParsedServers().end())
	{
		addNewServer(*it);
		it++;
	}
}

ManagementServer::~ManagementServer()
{
	for (std::vector<ServerData>::iterator it = ServerDatas.begin();
		 it != ServerDatas.end(); it++)
	{
		close(it->ServerDataSocket->getFdSocket());
		delete it->ServerDataSocket;
		// delete la map location ?
	}
}

// suite du constructeur
//  cette fonction remplie en gros toute la struct du serveur
//  et active l'écoute passive du port
//  En détail:
// parse la ligne entre key et value pour récupérer les infos
// de config importantes
//  crée une Socket (classe), la définie comme non-bloquante
//  la lie avec le port d'écoute (bind) et écoute les requests (listen)
#include <sstream>

void ManagementServer::addNewServer(HttpConfig::ServerConfig server)
{
	ServerData newServer;
	socklen_t addrLen;

	try
	{
		newServer._name = server.serverName;
		newServer._port = server.port;
		newServer._maxSize = server.clientMaxBodySize;
		newServer._errorPages = server.errorPages;
		newServer._locations = server.locations;
		newServer._root = server.root;

		newServer.ServerDataSocket = new Socket(AF_INET, SOCK_STREAM, 0, newServer._port, INADDR_ANY);
		addrLen = sizeof(newServer.ServerDataSocket->getAddress());

		setNonBlocking(newServer.ServerDataSocket->getFdSocket());

		try
		{
			newServer.ServerDataSocket->Bind();
		}
		catch (const std::runtime_error &e)
		{
			std::ostringstream errorMsg;
			if (errno == EACCES)
			{
				errorMsg << "Permission denied. You may need root privileges to bind to port " << newServer._port;
				throw std::runtime_error(errorMsg.str());
			}
			else if (errno == EADDRINUSE)
			{
				errorMsg << "Address already in use. Port " << newServer._port << " may already be occupied.";
				throw std::runtime_error(errorMsg.str());
			}
			else
			{
				throw; // Rethrow the original exception if it's not one of the specific cases we're handling
			}
		}

		newServer.ServerDataSocket->Listen();

		int ip = getsockname(newServer.ServerDataSocket->getFdSocket(),
							 (struct sockaddr *)&newServer.ServerDataSocket->getAddress(),
							 &addrLen);
		if (ip == -1)
		{
			std::string errorStr = "Error getting host IP: ";
			errorStr += strerror(errno);
			throw std::runtime_error(errorStr);
		}

		ServerDatas.push_back(newServer);
		ServerDatas.back()._ipAddress = ip;
		std::cout << "Server is listening on port " << newServer._port << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed to set up server on port " << server.port << ": " << e.what() << std::endl;

		// Clean up resources if an error occurred
		if (newServer.ServerDataSocket)
		{
			delete newServer.ServerDataSocket;
		}

		// Optionally, you might want to rethrow the exception or handle it in some other way
		// throw;
	}
}
// La boucle principale d'écoute des différents serveur lancés
// prépare les FD des serveurs et des potentiels clients
// en modifiant la valeur max du nombre d'FD actif
// commence par 4 (1, 2 et 3 étant les fd réservés) + 1 pour
// le fd(socket) du serveur
// select() (similaire à poll) permet de faire le I/O multiplexing
// en récupéreant les fd préalablement préparés
// si des nouvelles connections sont repérées, elles sont
// acceptées puis gérées
void ManagementServer::handleRequest()
{
	fd_set readFds;
	std::vector<Client> clients;
	int maxFd = 0;

	while (true)
	{
		prepareFdSets(readFds, clients, maxFd);
        std::cout << "currents clients: " << clients.size() << std::endl;
		// Attendre 5 secondes (et 0microscd) pour un événement sur les
		// sockets surveillés avant de retourner.
		// timeout permet de contrôler la fréquence à laquelle
		// le serveur traite les entrées sans être bloqué indéfiniment
		// en attente d'activité
		struct timeval tv = {5, 0};
		int selectRes = select(maxFd + 1, &readFds, NULL, NULL, &tv);
		if (selectRes > 0)
		{
			acceptNewClients(clients, readFds);
			handleActiveClients(readFds, clients);
		}
		else if (selectRes == -1)
			throw std::runtime_error("Select error");
		else if (selectRes == 0)
		{
			std::cout << "Timeout occurred, performing routine checks." << std::endl;
			continue;
		}
		std::cout << "select() returned: " << selectRes << std::endl;
	}
}

// fonction permettant de préparer et initialiser les fd
//  Typically, the fd_set data type is implemented as a bit mask.
// However, we don’t need to know the details, since all manipulation
//  of file descriptor sets is done via four macros:
// FD_ZERO(), FD_SET(), FD_CLR(), and FD_ISSET().
// FD_ZERO() initializes the set pointed to by fdset to be empty.
// FD_SET() adds the file descriptor fd to the set pointed to by fdset.
void ManagementServer::prepareFdSets(fd_set &readFds,
									std::vector<Client> &clients, int &maxFd)
{

	FD_ZERO(&readFds);
	for (size_t i = 0; i < ServerDatas.size(); i++)
	{
		int serverFd = ServerDatas[i].ServerDataSocket->getFdSocket();
		FD_SET(serverFd, &readFds);
		if (serverFd > maxFd)
			maxFd = serverFd;
		//std::cout << "server Maxfd " << maxFd << std::endl;
	}
    for (size_t i = 0; i < clients.size(); ++i)
    {
        int clientFd = clients[i].getClientSocket();
        FD_SET(clientFd, &readFds);
        if (clientFd > maxFd)
            maxFd = clientFd;
    }
}

// Si une connexion est repérée, elle doit être acceptée avant de pourvoir
// être traiter. accept() créé un socket() chez le client,
// afin de pouvoir être non bloquant cette socket aussi doit être en non bloquant
// FD_ISSET() returns true if the file descFD_CLOEXECriptor fd is a
// member of the set pointed to by fdset. (int FD_ISSET(int fd, fd_set *fdset))
void ManagementServer::acceptNewClients(std::vector<Client> &clients, fd_set &readFds)
{
    for (size_t i = 0; i < ServerDatas.size(); i++)
    {
        if (FD_ISSET(ServerDatas[i].ServerDataSocket->getFdSocket(), &readFds))
        {
            std::cout << "Connection detected on server " << ServerDatas[i]._name << std::endl;
            struct sockaddr_in clientAddr;
            try
            {
                int clientFd = ServerDatas[i].ServerDataSocket->Accept(clientAddr);
                setNonBlocking(clientFd);
                Client newClient(clientFd, clientAddr);
                clients.push_back(newClient);
                std::cout << "New client connected on server " << ServerDatas[i]._name << ": " << clientFd << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error during client initialization: " << e.what() << std::endl;
            }
        }
    }
}



// Configure la socket en non bloquant
//  FD_CLOEXEC : Ce flag est utilisé pour indiquer que
// le descripteur de fichier doit être automatiquement fermé
// lors de l'exécution de la fonction exec(),
// qui est utilisée pour lancer une nouvelle image de programme.
// Cela empêche les nouveaux programmes exécutés de hériter ce descripteur de fichier.
//  F_SETFL: est une commande utilisée avec fcntl
// pour définir les flags du descripteur de fichier.
//  Permet la modification dynamique des propriétés de descripteurs de fichiers.
void ManagementServer::setNonBlocking(int fd)
{
    int flags;

    // Set O_NONBLOCK
    if ((flags = fcntl(fd, F_GETFL, 0)) == -1)
        throw std::runtime_error("Failed to get file flags");
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
        throw std::runtime_error("Failed to set non-blocking mode");

    // Set FD_CLOEXEC
    if ((flags = fcntl(fd, F_GETFD)) == -1)
        throw std::runtime_error("Failed to get fd flags");
    if (fcntl(fd, F_SETFD, flags | FD_CLOEXEC) == -1)
        throw std::runtime_error("Failed to set FD_CLOEXEC");
}


// Loop sur tout les fd actifs pour les gérer individuellement
// si une erreur arrive, le client est supprimé des clients actifs
void ManagementServer::handleActiveClients(fd_set &readFds, std::vector<Client> &clients)
{
    for (size_t i = 0; i < clients.size(); ++i)
    {
        int clientFd = clients[i].getClientSocket();
        if (FD_ISSET(clientFd, &readFds))
        {
            try
            {
                bool shouldRemoveClient = handleClient(clients[i]);
                if (shouldRemoveClient)
                {
                    FD_CLR(clientFd, &readFds);
                    clients.erase(clients.begin() + i);
                    --i; // Adjust index after removal
                    continue; // Move to next client
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Client error: " << e.what() << std::endl;
                FD_CLR(clientFd, &readFds);
                close(clientFd);
                clients.erase(clients.begin() + i);
                --i; // Adjust index after removal
            }
        }
    }
}



bool ManagementServer::handleClient(Client &client)
{
    int clientSocket = client.getClientSocket();
    struct sockaddr_in serverAddr;
    socklen_t serverAddrLen = sizeof(serverAddr);
    std::string rawData;
    Logger &logger = Logger::getInstance("server.log");

    //détermine sur quel serveur le client est connecté
    if (getsockname(clientSocket, (struct sockaddr *)&serverAddr, &serverAddrLen) == -1)
    {
        throw std::runtime_error("Error getting server socket information: " + std::string(strerror(errno)));
    }

    int serverPort = ntohs(serverAddr.sin_port);

    //trouver la conf du serveur correspondant à ce port
    ServerData currentServer;
    bool serverFound = false;
    
    for (std::vector<ServerData>::iterator it = ServerDatas.begin(); it != ServerDatas.end(); ++it)
    {
        if (it->_port == serverPort)
        {
            currentServer = *it;
            serverFound = true;
            break;
        }
    }
    if (!serverFound)
    {
        throw std::runtime_error("No server found for port " + std::to_string(serverPort));
    }
    size_t maxBodySize = 10 * 1024 * 1024; 
    try
    {
        rawData = readRawData(clientSocket, maxBodySize);
        logger.log("Rawdata result: " + rawData);
        if (rawData.empty())
        {
            // Le client a peut-être fermé la connexion
            close(clientSocket);
            return true; // Indique que le client doit être supprimé
        }

        client.readRequest(rawData);
        client.processRequest(currentServer, maxBodySize);
        client.sendResponse();
    }
    catch (const RequestTooLargeException &e)
    {
        // Générer une réponse 413
        HttpResponse response;
        response.generate413PayloadTooLarge(maxBodySize);
        std::string responseStr = response.toString();
        send(clientSocket, responseStr.c_str(), responseStr.size(), 0);
        close(clientSocket);
        return true; // Indique que le client doit être supprimé
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception while handling client: " << e.what() << std::endl;
        close(clientSocket);
        return true; // Indique que le client doit être supprimé
    }

    if (!client.isKeepAlive())
    {
        // Fermer la connexion
        close(client.getClientSocket());
        return true;
    }
    return false;
}



std::string ManagementServer::readRawData(int clientSocket, size_t maxBodySize)
{
    const size_t buffer_size = 1024;
    char buffer[buffer_size];
    std::string requestData;
    ssize_t bytesReceived;
    size_t headerEndPos = std::string::npos;
    size_t contentLength = 0;
    size_t totalBytesRead = 0;
    //Logger &logger = Logger::getInstance("server.log");

    // Lire les en-têtes
    while (true)
    {
        bytesReceived = recv(clientSocket, buffer, buffer_size - 1, 0);
        if (bytesReceived > 0)
        {
            buffer[bytesReceived] = '\0';
            requestData.append(buffer, bytesReceived);
            totalBytesRead += bytesReceived;

            // Vérifier si la taille dépasse la limite
            if (totalBytesRead > maxBodySize)
                throw RequestTooLargeException();

            // Rechercher la fin des en-têtes
            headerEndPos = requestData.find("\r\n\r\n");
            if (headerEndPos != std::string::npos)
                break;
        }
        else if (bytesReceived == 0) // Le client a fermé la connexion
            return "";
        else
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                continue;
            else
                throw std::runtime_error("Erreur lors de la lecture du socket : " + std::string(strerror(errno)));
        }
    }

    // Analyser les en-têtes pour trouver Content-Length
    std::string headers = requestData.substr(0, headerEndPos + 4); // Inclure \r\n\r\n
    //logger.log("Reading raw data header: " + headers);
    std::istringstream headerStream(headers);
    std::string line;
    while (std::getline(headerStream, line))
    {
        if (!line.empty() && line.back() == '\r') // Supprimer \r
            line.pop_back();

        if (line.empty())
            break; // Fin des en-têtes

        if (line.find("Content-Length:") != std::string::npos)
        {
            std::string value = line.substr(line.find(":") + 1);
            contentLength = std::stoi(value);

            // Vérifier si Content-Length dépasse la limite
            if (contentLength > maxBodySize)
                throw RequestTooLargeException();
        }
    }

    // Lire le corps en fonction de Content-Length
    size_t totalBytesToRead = headerEndPos + 4 + contentLength;
    while (requestData.size() < totalBytesToRead)
    {
        bytesReceived = recv(clientSocket, buffer, buffer_size - 1, 0);
        if (bytesReceived > 0)
        {
            buffer[bytesReceived] = '\0';
            requestData.append(buffer, bytesReceived);
            totalBytesRead += bytesReceived;

            // Vérifier si la taille dépasse la limite
            if (totalBytesRead > maxBodySize)
                throw RequestTooLargeException();
        }
        else if (bytesReceived == 0) // Le client a fermé la connexion
            break;
        else
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                continue;
            else
                throw std::runtime_error("Erreur lors de la lecture du socket : " + std::string(strerror(errno)));
        }
    }
    //logger.log("Reading raw data : " + requestData);
    //std::cout << "HERE!!!!! " << requestData << std::endl;
    return requestData;
}



int ManagementServer::getPort(std::vector<ServerData>::iterator it)
{
	return (it->_port);
}

int ManagementServer::getSize(std::vector<ServerData>::iterator it)
{
	return (it->_maxSize);
}

/* ServerData& ManagementServer::\
getServerInfo(std::vector<ServerData>::iterator it)
{
	return (*it);
}  */

void ManagementServer::setIpAddress(std::vector<ServerData>::iterator it, int ip)
{
	it->_ipAddress = ip;
}

