/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:45:04 by hgandar           #+#    #+#             */
/*   Updated: 2024/09/03 16:02:50 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

//const int PORT = 8888;

server::server(std::string fdConfig)
{
	loadConfig(fdConfig);
	_serverSocket(AF_INET, SOCK_STREAM, 0, _port, INADDR_ANY);
}

server::server(const server &other)
{
	
}
server& server::operator=(const server &other)
{
	
}

server::~server()
{}

//fichier recu imaginé :
//root:/html
// index:index.html,index.htm
// error:404,not_found.html
// error:500,error.html
// listing:true
// name:mywebserv
// port:8888
//AJOUTER # Limitations:client_max_body_size 8M; ??
// ou location /images ??

void server::loadConfig(const std::string& configFilePath)
{
	std::string line;
	std::string key;
	std::string value;
	
	std::ifstream config(configFilePath.c_str());
	if (!config) throw std::runtime_error("Error opening configuration file.");
	
	while (std::getline(config, line))
	{
		std::istringstream lineStream(line);
		std::getline(lineStream, key, ':');
		std::getline(lineStream, value);
		if (key == "root")
			_locations["default"].root = value;
		else if (key == "index")
			_locations["default"].index = parseIndex(value);
		else if (key == "error")
			_locations["default"].errorPages.insert(parseError(value));
		else if (key == "listing")
			_locations["default"].allowListing = (value == "true");
		else if (key == "name")
			_name = key;
		else if (key == "port")
			_port = stoi(value);
		else if (key == "size")
			_maxSize = stoi(value);
	}
}

std::pair<int, std::string> server::parseError(const std::string& value)
{
	std::istringstream valueStream(value);
	std::string errorCodeStr, errorFile;
	
	getline(valueStream, errorCodeStr, ',');
	getline(valueStream, errorFile);
	int errorCode = stoi(errorCodeStr);
	return std::make_pair(errorCode, errorFile);
}

std::vector<std::string> server::parseIndex(const std::string& value)
{
	std::vector<std::string> indices;
	std::istringstream valueStream(value);
	std::string index;
	
	while (std::getline(valueStream, index, ','))
		indices.push_back(index);
	return indices;
}

void server::handleRequest(const HttpRequest& request, HttpResponse& response)
{
	fd_set readFds;
	fd_set writeFds;
	int	readyFds = 0;
	int	clientSocket
	
	while (true)
	{
		FD_ZERO(&readFds);
		FD_ZERO(&writeFds);
		FD_SET(readFds, &readFds);
		readyFds = select(readFds + 1, &readFds, &writeFds, NULL, 0);
		if (readyFds == -1)
			//faire stopper le programe (errExit("select"); n'est probablement pas autorise)
		if (FD_ISSET(readFds, &readFds))
		{
			socklen_t addrlen = sizeof(serverSocket.getAddress());
			_clientSocket.setFdSocket() = 
		}
		
	}
}
