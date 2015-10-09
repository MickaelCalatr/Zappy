//
// IA.hpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Wed Jun 24 11:11:18 2015 Caltraba Mickael
// Last update Fri Jul  3 14:58:40 2015 Caltraba Mickael
//

#ifndef _IA_HPP_
# define _IA_HPP_

#include <map>
#include <list>
#include <iostream>
#include "Select.hpp"
#include "Socket.hpp"

#include <unistd.h>

void            my_handler(int);

class IA
{
public:
  IA(const std::string &);
  ~IA();
  
  bool		run();
  void		send(const std::string &);

  void		broadcast();
  void		poseInvent();
  bool		viewAction();
  void		checkLvl();
  bool		setAction(std::string &);
  void		popAction(std::string &);

  void		parseAction(std::string &);
  void		parseInventaire(std::string &);
  void		parseMessage(std::string &);
  bool		parseLine(std::string &, int, int);
  void		goToIA(int);
  bool		goToCase(const std::string &, int, int);

  bool					initialize(const std::string &, int);
  std::map<const std::string, int>	initLvl(int, int, int, int, int, int,
						int) const ;
  bool					initOption(std::string &);
private:
  Socket	_socket;
  Select	_select;
  int		_nb;

  int		_lvl;
  int		_up;
  int		_buff;
  int		_food;
  bool		_inc;
  bool		_goInc;
  bool		_bro;
  bool		_listen;
  bool		_block;

  std::pair<int, int>		_pos;
  const std::string		_team;
  std::list<std::string>	_action;

  std::map<int, std::map<const std::string, int> >	_required;
  std::map<const std::string, int>			_acquired;
};

#endif
