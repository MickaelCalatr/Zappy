//
// Socket.hpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client/include
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 13:30:42 2015 Caltraba Mickael
// Last update Tue Jun 23 10:37:12 2015 Caltraba Mickael
//

#ifndef _SOCKET_HPP_
# define _SOCKET_HPP_

#include <iostream>

#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Socket
{
public:
  Socket();
  ~Socket();

  bool			initialize(int, const std::string &);
  bool			clientConnect() const;
  bool			initSock(const std::string &);

  int			getFd() const;
  bool			myError(const std::string &) const;

private:
  struct sockaddr_in	_sock;
  int			_port;
  int			_sockFd;
};

#endif
