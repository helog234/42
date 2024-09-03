/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:56:48 by hgandar           #+#    #+#             */
/*   Updated: 2024/09/03 15:00:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# include <iostream>
# include <vector>
# include <map>
# include "Socket.hpp"
# include <netinet/in.h>
# include <sys/socket.h>
# include <fstream>
# include <sstream>
# include <utility>
# include <string>
# include <poll.h>

struct LocationConfig
{
	std::string root = "/html";
	std::vector<std::string> index;
	std::map<int, std::string> errorPages;
	bool allowListing;

	LocationConfig(std::string r = "", bool listing = false) : root(r), allowListing(listing) {}
};

class server
{
	private:
		Socket _serverSocket(int domain, int service, int protocol, int port, u_long interface);
		Socket	_clientSocket(int domain, int service, int protocol, int port, u_long interface);
		void loadConfig(const std::string& configFilePath);
		std::vector<std::string> parseIndex(const std::string& value);
		std::pair<int, std::string> parseError(const std::string& value);
		//std::vector<int> parsePorts(std::string ports);
		std::string _name;
		//std::vector<int> _ports;
		int	_port;
		int _maxSize;
		std::map<std::string, LocationConfig> _locations;
		
	public:
		server(std::string fdConfig);
		server(const server &other);
		server& operator=(const server &other);
		~server();

		int getPort();
		void loadConfig(const std::string& configFilePath);
		void handleRequest(const HttpRequest& request, HttpResponse& response);
};

#endif
