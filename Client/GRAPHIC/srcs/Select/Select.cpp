//
// Select.cpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client/srcs/Select
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 16:13:38 2015 Caltraba Mickael
// Last update Mon Jun 29 16:07:00 2015 Caltraba Mickael
//

#include "Select.hpp"

Select::Select()
{
}
Select::~Select()
{
  while (!this->_buff_r.empty())
    this->_buff_r.pop();
  while (!this->_buff_w.empty())
    this->_buff_w.pop();
}

void		Select::initialize(int sockFd, int sec, int usec)
{
  this->_sockFd = sockFd;
  this->_sec = sec;
  this->_usec = usec;
}
//_____PRINCIPAL_FUNCTION______

void		Select::setTime(struct timeval *tv)
{
  tv->tv_sec = this->_sec;
  tv->tv_usec = this->_usec;
}

bool		Select::setSelect()
{
  if (select(this->_sockFd + 1, &this->_fdRead, &this->_fdWrite, NULL,
	     &this->_tv) == -1)
    return (myError("Can't select"));
  return (true);
}

void		Select::setFd()
{
  FD_ZERO(&this->_fdRead);
  FD_ZERO(&this->_fdWrite);
  if (!this->_buff_w.empty() && this->_buff_w.front().first > 0)
    FD_SET(this->_sockFd, &this->_fdWrite);
  FD_SET(this->_sockFd, &this->_fdRead);
}


//_____READ_FUNCTION_____

bool		Select::readIn()
{
  if (FD_ISSET(this->_sockFd, &this->_fdRead))
    {
      if (!readInFd())
	return (myError("Server closed"));
    }
  if (FD_ISSET(this->_sockFd, &this->_fdWrite))
    return (writeInFd());
  return (true);
}

bool		Select::readInFd()
{
  std::pair<int, std::string>	cmd;
  char				buff[SIZE];

  std::memset(buff, 0, SIZE);
  
  if ((cmd.first = read(this->_sockFd, buff, SIZE)) <= 0)
    return (false);
  buff[cmd.first] = '\0';
  if (!this->_buff_r.empty())
    cmd.first += this->_buff_r.front().first;
  cmd.second = buff;
  if (cmd.second[0] != '\0')
    this->_buff_r.push(cmd);
  return (true);
}


//_____WRITE_FUNCTION____________

void		Select::sendToBuff(const std::string &msg)
{
  std::pair<int, std::string>	buff;

  if (!this->_buff_w.empty())
    buff.first = this->_buff_w.back().first + msg.size();
  else
    buff.first = msg.size();
  buff.second = msg;
  this->_buff_w.push(buff);
  std::cout << "Send : " << msg << std::endl;
}

bool		Select::writeInFd()
{
  while (!this->_buff_w.empty())
    {
      if (dprintf(this->_sockFd, "%s\n",
		  this->_buff_w.front().second.c_str()) <= 0)
	return (myError("Server closed"));
      this->_buff_w.pop();
    }
  return (true);
}


//_____UTILS_____

struct timeval					&Select::getTv()
{return (this->_tv);}
std::pair<int, std::string>	Select::getBuff()
{
  std::pair<int, std::string>	err;

  err.first = -1;
  if (this->_buff_r.empty())
    return (err);
  err = this->_buff_r.front();
  this->_buff_r.pop();
  return (err);
}
//_____ERROR_____

bool		Select::myError(const std::string &msg) const
{
  std::cerr << "Error : " << msg << " : " << strerror(errno) << std::endl;
  return (false);
}
