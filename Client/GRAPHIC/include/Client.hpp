//
// Client.hpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client/include
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 22:12:48 2015 Caltraba Mickael
// Last update Tue Jun 23 14:25:20 2015 Caltraba Mickael
//

#ifndef _CLIENT_HPP_
# define _CLIENT_HPP_

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

#include "Socket.hpp"
#include "Select.hpp"
//#include "Parser.hpp"

// #include <signal.h>
// #include <stdlib.h>

void		my_handler(int);

class Client
{
public:
  Client();
  ~Client();

  bool		initialize(const std::string &, int);
  bool		run();
    
private:
  Socket	_socket;
  Select	_select;
  //Parser	_parser;
};

#endif
