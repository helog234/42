/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:38:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/30 11:07:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP
# include <iostream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <fcntl.h>
# include <unistd.h>
# define MAX_CONNECTIONS 500

class Socket
{
	private:
		int _fdSocket;
		struct sockaddr_in _address;
		socklen_t _len;
		
	public:
		Socket(int domain, int service, int protocol, int port, u_long interface);
		Socket(const Socket &other);
		Socket& operator=(const Socket &other);
		~Socket();

		int getFdSocket();
		struct sockaddr_in getAddress();
		socklen_t getLen();

		void Bind();
		void Listen(int connections);
		int Accept();

		ssize_t Send(int client_socket, const char* buffer, size_t buffer_length, int flags);
		ssize_t Receive(int client_socket, char* buffer, size_t buffer_length, int flags);

		void SetNonBlocking(bool is_non_blocking);
		void Close();

		/* class ErrorSocket: public std::exception
		{
			virtual const char* what() const throw();
		};
		class ErrorSendingSocket: public std::exception
		{
			virtual const char* what() const throw();
		};
		class ErrorReceivingSocket: public std::exception
		{
			virtual const char* what() const throw();
		}; */
};

#endif