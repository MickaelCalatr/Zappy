//
// Eggs.hpp for zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/GRAPHIC/include
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Wed Jul  1 15:29:54 2015 Alexandre Tanyeres
// Last update Sun Jul  5 06:29:32 2015 Alexandre Tanyeres
//

#include <iostream>

class Eggs
{
public:
  Eggs(std::pair<int, int> pos, std::string team, int &id);
  ~Eggs();
  void                  doEnw();
  void                  doEht();
  void                  doEbo();
  void                  doEdi();
  int			getId() const {return (this->_id);}
  std::pair<int, int>	getPos() const {return (this->_pos);}
  std::string		getTeam() const {return (this->_team);}
private:
  std::pair<int, int>	_pos;
  std::string	       	_team;
  int			_id;
};
