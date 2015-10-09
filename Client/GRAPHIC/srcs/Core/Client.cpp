//#include "ZappyUI.hpp"
// Client.cpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client/srcs/Core
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 22:11:38 2015 Caltraba Mickael
// Last update Sun Jul  5 22:36:50 2015 paul david
//

#include "ZappyUI.hpp"
#include "Client.hpp"
#include "Buffer.hpp"

static bool	g_run = true;

Client::Client()
{
}
Client::~Client()
{
}


//_____PRICIPAL_FUNCTION____

bool		Client::initialize(const std::string &add, int port)
{
  signal(SIGINT, my_handler);
  if (!this->_socket.initialize(port, add))
    return (false);
  if (!this->_socket.clientConnect())
    return (false);
  this->_select.initialize(this->_socket.getFd(), 0, 10000);
  return (true);
}

bool			Client::run()
{
  int			set = 0;
  int			i = 0;
  Map			g_map;
  Buffer		buffer(g_map);
  ZappyUI		interf;
  std::string		tmp;
  std::string		ok;

  while (g_run)
    {
      this->_select.setFd();
      this->_select.setTime(&this->_select.getTv());
      if (!this->_select.setSelect())
	break;
      if (!this->_select.readIn())
	break;
      std::pair<int, std::string>	buff;
      buff = this->_select.getBuff();
      if (buff.first != -1)
	{
	  std::cout << buff.second;
	  if (i == 0 && (i = 1))
	    this->_select.sendToBuff("GRAPHIC");
	  std::istringstream iss(buff.second);
	  std::string line;
	  while (std::getline(iss, line))
	    {
	      ok = tmp + line;
	      buffer.setBuffer(line);
	      if (buffer.epur() == false)
	      	tmp = line;
	      else
	      	tmp = "";
	    }
	  set = 1;
	}
      if (set == 1)
	interf.start(g_map);
    }
  std::cout << "*** Exit Zappy ***" << std::endl;
  close(this->_socket.getFd());
  return (true);
}


//_____SIGNAL____

void		my_handler(int s)
{
  std::cout << "\rExit : Caught signal [" << s << "]." << std::endl;
  g_run = false;
}
