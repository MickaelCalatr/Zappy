//
// Select.hpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client/include
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 16:43:51 2015 Caltraba Mickael
// Last update Tue Jun 23 14:25:46 2015 Caltraba Mickael
//

#ifndef _SELECT_HPP_
# define _SELECT_HPP_

#include <string>
#include <queue>
#include <sstream>
#include <cstring>
#include <iostream>

#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <signal.h>                                                          
#include <stdlib.h>
  
# define SIZE	4096

class Select
{
public:
  Select();
  ~Select();

  void	initialize(int, int, int);

  void			setTime(struct timeval *);
  bool			setSelect();
  void			setFd();

  bool			readIn();
  bool			readInFd();

  bool			writeInFd();
  void			sendToBuff(const std::string &);

  struct timeval				&getTv();
  std::pair<int, std::string>			getBuff();
  bool	myError(const std::string &) const;

private:
  struct timeval	_tv;
  fd_set		_fdRead;
  fd_set		_fdWrite;
  int			_sockFd;
  int			_sec;
  int			_usec;
  std::queue<std::pair<int, std::string> >	_buff_r;
  std::queue<std::pair<int, std::string> >	_buff_w;
};

#endif
