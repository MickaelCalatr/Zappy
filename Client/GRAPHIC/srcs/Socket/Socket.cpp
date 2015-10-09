//
// Socket.cpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client/Graphic/Socket
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 13:28:56 2015 Caltraba Mickael
// Last update Tue Jun 23 10:57:55 2015 Caltraba Mickael
//

#include "Socket.hpp"

Socket::Socket()
{
  this->_port = 0;
  this->_sockFd = 0;
}
Socket::~Socket()
{
}


//_____CONNEXION__________________________

bool			Socket::initialize(int port, const std::string &add)
{
  this->_port = port;
  if (!initSock(add))
    return (false);
  return (true);
}

bool			Socket::clientConnect() const
{
  if (connect(this->_sockFd,
	      (const struct sockaddr *)&this->_sock,
	      (socklen_t)sizeof(this->_sock)) == -1)
    {
      close(this->_sockFd);
      return (myError("connect"));
    }
  return (true);
}

bool			Socket::initSock(const std::string &add)
{
  struct protoent	*pe;
  
  if ((pe = getprotobyname("TCP")) == NULL)
    return (myError("getprotobyname"));
  if ((this->_sockFd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    return (myError("init socket"));
  this->_sock.sin_family = AF_INET;
  this->_sock.sin_port = htons(this->_port);
  this->_sock.sin_addr.s_addr = inet_addr(add.c_str());
  return (true);
}


//_____UTIL______

int			Socket::getFd() const {return (this->_sockFd);}

//_____ERROR____________________________

bool			Socket::myError(const std::string &msg) const
{
  std::cerr << "Error in " << msg << " : " << strerror(errno) << std::endl;
  return (false);
}
