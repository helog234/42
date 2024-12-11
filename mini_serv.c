#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

typedef struct s_client
{
	int id;
	char *buffer;
} t_client;

t_client clients[FD_SETSIZE];
fd_set master_set, read_set;
int max_fd;
int server_fd;
int client_counter = 0;

void errormsg(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", strlen("Fatal error"));
	write(2, "\n", 1);
	exit(1);
}

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_to_all(int sender_fd, char *msg)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &master_set) && fd != sender_fd && fd != server_fd)
			send(fd, msg, strlen(msg), 0);
	}
	
}

void rm_client(int client_fd)
{
	//envoyer le message de départ
	char msg[64];
	sprintf(msg, "server: client %d just left\n", clients[client_fd].id);
	send_to_all(client_fd, msg);

	//fermer le fd
	close(client_fd);
	//enlever le fd du master set
	FD_CLR(client_fd, &master_set);

	//libérer buffer
	if (clients[client_fd].buffer)
	{
		free(clients[client_fd].buffer);
		clients[client_fd].buffer = NULL;
	}
}

void accept_new_client()
{
	//créer un struct pour le client
	//et accepter connexion
	struct sockaddr_in clientaddr;
	socklen_t addrlen = sizeof(clientaddr);
	int client_fd = accept(server_fd, (struct sockaddr *)&clientaddr, &addrlen);

	if (client_fd < 0)
		errormsg("Error accepting new client.");
	
	//initialiser le struct client
	clients[client_fd].id = client_counter++;
	clients[client_fd].buffer = NULL;

	//ajouter le client au master set
	// FD_SET() adds the file descriptor fd to the set pointed to by fdset.
	//adapter la taille de max fd
	FD_SET(client_fd, &master_set);
	if (client_fd > max_fd)
		max_fd = client_fd;
	
	//envoyer le message d'arriver auc autres clients
	char msg[64];
	sprintf(msg, "server: client %d just arrived\n", clients[client_fd].id);
	send_to_all(client_fd, msg);
}

void handle_client_msg(int client_fd)
{
	char recv_buffer[1024];
	int bytes_recv = recv(client_fd, recv_buffer, sizeof(recv_buffer) -1, 0);
	if (bytes_recv <= 0)
		rm_client(client_fd);
	else
	{
		recv_buffer[bytes_recv] = '\0';
		//ajouter les bytes recues au buffer client
		clients[client_fd].buffer = str_join(clients[client_fd].buffer, recv_buffer);
		if (clients[client_fd].buffer == NULL)
			errormsg(NULL);
		char *msg;
		while (extract_message(&clients[client_fd].buffer, &msg))
		{
			char prefix[32];
			sprintf(prefix, "client %d: ", clients[client_fd].id);
			int total_len = strlen(prefix) + strlen(msg) + 1;
			char *send_buffer = malloc(total_len);
			if (send_buffer == NULL)
				errormsg(NULL);
			strcpy(send_buffer, prefix);
			strcat(send_buffer, msg);

			send_to_all(client_fd, send_buffer);

			free(send_buffer);
			free(msg);
		}
	}
}


int	main(int argc, char *argv[])
{
	if (argc != 2)
		errormsg("Wrong number of arguments");
	
	int port = atoi(argv[1]);
	if (port <= 0)
		errormsg(NULL);

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		errormsg(NULL);
	
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 

	if (bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		errormsg("Error binding");
	
	if (listen(server_fd, 128) < 0)
		errormsg("Error listening");
	
	// FD_ZERO() initializes the set pointed to by fdset to be empty.
	// FD_SET() adds the file descriptor fd to the set pointed to by fdset.
	FD_ZERO(&master_set);
	FD_SET(server_fd, &master_set);
	max_fd = server_fd;
	memset(&clients, 0, sizeof(clients));

	while (1)
	{
		read_set = master_set;
		if (select(max_fd + 1, &read_set, NULL, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++)
		{
			// FD_ISSET() returns true if the file descriptor fd is a
			// member of the set pointed to by fdset. (int FD_ISSET(int fd, fd_set *fdset))
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == server_fd)
					accept_new_client();
				else
					handle_client_msg(fd);
			}
		}
		
	}
	return (0);
}