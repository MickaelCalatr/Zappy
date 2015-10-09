//
// Map.cpp for zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/GRAPHIC/srcs/Graphic
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Tue Jun 30 18:03:34 2015 Alexandre Tanyeres
// Last update Sun Jul  5 22:43:59 2015 paul david
//

#include "Map.hpp"
#include <cstdlib>
#include <sstream>

Map::Map()
{
}

Map::~Map()
{
}

void		      Map::CheckCase(std::pair<int, int> &pos)
{
  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getPos() == pos)
	break;
    }
  for (std::vector<Eggs>::iterator it = this->_eggs.begin() ; it != this->_eggs.end(); ++it)
    {
      if ((*it).getPos() == pos)
	break;
    }
}

bool                  Map::doMsz(const std::vector<std::string> &param)
{
  int		      y = 0;
  std::stringstream	ss;

  if (param.size() != 3)
    return false;
  ss << param.at(1) ;
  ss >> this->_sizeMap.first;
  ss.str("");
  ss.clear();
  ss << param.back();
  ss >> this->_sizeMap.second;
  while (y != this->_sizeMap.second)
    {
      this->_case.push_back(new Case[this->_sizeMap.first]);
      y++;
    }
  return true;
}

bool                  Map::doTna(const std::vector<std::string> &param)
{
  if (param.size() != 2)
    return false;
  this->_teams.push_back(param.at(1));
  return true;
}

bool                  Map::doPnw(const std::vector<std::string> &param)
{
  int			x;
  int			y;
  int			Orientation;
  int			Level;
  int			numero;
  std::stringstream	ss;

  if (param.size() != 7)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> x;
  ss.str("");
  ss.clear();
  ss << param.at(3);
  ss >> y;
  ss.str("");
  ss.clear();
  ss << param.at(4);
  ss >> Orientation;
  ss.str("");
  ss.clear();
  ss << param.at(5);
  ss >> Level;

  std::cout << numero << std::endl;
  std::cout << "X " << x << "Y " << y << std::endl;
  Player player(std::make_pair(x, y), param.at(6), numero, Orientation, Level, 0, 0, 0, 0, 0, 0, 0, false);
  this->_player.push_back(player);
  return true;
}

bool                  Map::doPpo(const std::vector<std::string> &param)
{
  int			numero;
  int			x;
  int			y;
  int			orientation;
  std::stringstream	ss;

  if (param.size() != 5)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> x;
  ss.str("");
  ss.clear();
  ss << param.at(3);
  ss >> y;
  ss.str("");
  ss.clear();
  ss << param.at(4);
  ss >> orientation;
  ss.str("");
  ss.clear();
  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  (*it).setPos(std::make_pair(x, y));
	  (*it).setOrientation(orientation);
	  break;
	}
    }
  return true;
}

bool                  Map::doSeg(const std::vector<std::string> &param)
{
  (void) param;
  std::exit(0);
  return true;
  //ON FERME LA FENETRE
}

bool                  Map::doSmg(const std::vector<std::string> &param)
{
  (void)param;
  return true;
}

bool                  Map::doSgt(const std::vector<std::string> &param) 
{
  std::stringstream ss;
  int		    t = 1;

  if (param.size() != 2)
    return false;
  if (param.size() >= 2)
    {
      ss << param[1];
      ss >> t;
    }
  this->time = t;
  return (true);
}
bool                  Map::doSuc(const std::vector<std::string> &param)
{
  (void) param;
  return true;}
bool                  Map::doSbp(const std::vector<std::string> &param)
{
  (void) param;
  return true;
}

//case
bool                  Map::doBct(const std::vector<std::string> &param)
{
  int			x;
  int			y;
  std::stringstream	ss;

  if (param.size() != 10)
    return false;
  ss << param.at(1);
  ss >> x;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> y;
  ss.str("");
  ss.clear();

  int                   nourriture;
  int                   linemate;
  int                   deraumere;
  int                   sibur;
  int                   mendiane;
  int                   phiras;
  int                   thystame;

  ss << param.at(3);
  ss >> nourriture;
  ss.str("");
  ss.clear();
  ss << param.at(4);
  ss >> linemate;
  ss.str("");
  ss.clear();
  ss << param.at(5);
  ss >> deraumere;
  ss.str("");
  ss.clear();
  ss << param.at(6);
  ss >> sibur;
  ss.str("");
  ss.clear();
  ss << param.at(7);
  ss >> mendiane;
  ss.str("");
  ss.clear();
  ss << param.at(8);
  ss >> phiras;
  ss.str("");
  ss.clear();
  ss << param.at(9);
  ss >> thystame;
  ss.str("");
  ss.clear();

  this->_case[y][x].doBct(nourriture, linemate, deraumere, sibur, mendiane, phiras, thystame);
  return true;
}

//player
bool                  Map::doPlv(const std::vector<std::string> &param)
{
  int			numero;
  int			Level;
  std::stringstream	ss;

  if (param.size() != 3)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> Level;
  ss.str("");
  ss.clear();

  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  (*it).setLevel(Level);
	  break;
	}
    }
  return (true);
}

bool                  Map::doPin(const std::vector<std::string> &param)
{
  int			x;
  int			y;
  int			numero;
  std::stringstream	ss;

  if (param.size() != 11)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> x;
  ss.str("");
  ss.clear();
  ss << param.at(3);
  ss >> y;
  ss.str("");
  ss.clear();

  int                   nourriture;
  int                   linemate;
  int                   deraumere;
  int                   sibur;
  int                   mendiane;
  int                   phiras;
  int                   thystame;

  ss << param.at(4);
  ss >> nourriture;
  ss.str("");
  ss.clear();
  ss << param.at(5);
  ss >> linemate;
  ss.str("");
  ss.clear();
  ss << param.at(6);
  ss >> deraumere;
  ss.str("");
  ss.clear();
  ss << param.at(7);
  ss >> sibur;
  ss.str("");
  ss.clear();
  ss << param.at(8);
  ss >> mendiane;
  ss.str("");
  ss.clear();
  ss << param.at(9);
  ss >> phiras;
  ss.str("");
  ss.clear();
  ss << param.at(10);
  ss >> thystame;
  ss.str("");
  ss.clear();

  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  (*it).setPos(std::make_pair(x, y));
	  (*it).setNourriture(nourriture);
	  (*it).setLinemate(linemate);
	  (*it).setDeraumere(deraumere);
	  (*it).setMendiane(mendiane);
	  (*it).setSibur(sibur);
	  (*it).setPhiras(phiras);
	  (*it).setThystame(thystame);
	  break;
	}
    }
  return true;
}

bool                  Map::doPex(const std::vector<std::string> &param)
{
  (void) param;
  return true;
}

bool                  Map::doPbc(const std::vector<std::string> &param)
{
  int			numero;
  std::stringstream	ss;

  if (param.size() != 2)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();

  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  (*it).doPbc();
	  (*it).setMessage(true);
	  break;
	}
    }
  return true;
}

bool                  Map::doPic(const std::vector<std::string> &param)
{
  int			x;
  int			y;
  std::stringstream	ss;

  if (param.size() != 3)
    return false;
  ss << param.at(1);
  ss >> x;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> y;
  ss.str("");
  ss.clear();

  this->_case[y][x].setInc(true);
  return true;
}

bool                  Map::doPie(const std::vector<std::string> &param)
{
  int			x;
  int			y;
  std::stringstream	ss;

  if (param.size() != 3)
    return false;
  ss << param.at(1);
  ss >> x;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> y;
  ss.str("");
  ss.clear();

  this->_case[y][x].setInc(false);
  return true;
}

bool                  Map::doPfk(const std::vector<std::string> &param) {(void) param; return true;}

bool                  Map::doPdr(const std::vector<std::string> &param) 
{
  int			ressource;
  int			numero;
  std::stringstream	ss;

  if (param.size() != 3)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();
  ss << param.at(2);
  ss >> ressource;
  ss.str("");
  ss.clear();
  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  if (ressource == 0)
	    {
	      (*it).setNourriture((*it).getNourriture() + 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setNourriture(this->_case[(*it).getPos().second][(*it).getPos().first].getNourriture() - 1);
	    }
	  if (ressource == 1)
	    {
	      (*it).setLinemate((*it).getLinemate() + 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setLinemate(this->_case[(*it).getPos().second][(*it).getPos().first].getLinemate() - 1);
	    }
	  if (ressource == 2)
	    {
	      (*it).setDeraumere((*it).getDeraumere() + 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setDeraumere(this->_case[(*it).getPos().second][(*it).getPos().first].getDeraumere() - 1);
	    }
	  if (ressource == 3)
	    {
	      (*it).setSibur((*it).getSibur() + 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setSibur(this->_case[(*it).getPos().second][(*it).getPos().first].getSibur() - 1);
	    }
	  if (ressource == 4)
	    {
	      (*it).setSibur((*it).getSibur() + 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setMendiane(this->_case[(*it).getPos().second][(*it).getPos().first].getMendiane() - 1);
	    }
	  if (ressource == 5)
	    {
	      (*it).setMendiane((*it).getMendiane() + 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setPhiras(this->_case[(*it).getPos().second][(*it).getPos().first].getPhiras() - 1);
	    }
	  if (ressource == 6)
	    {
	      (*it).setThystame((*it).getThystame() + 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setThystame(this->_case[(*it).getPos().second][(*it).getPos().first].getThystame() - 1);
	    }
	  break;
	}
    }
  return true;
}

bool                  Map::doPgt(const std::vector<std::string> &param)
{
  int			ressource;
  int			numero;
  std::stringstream	ss;

  if (param.size() != 3)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.clear();
  ss << param.at(2);
  ss >> ressource;
  ss.clear();
  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  if (ressource == 0)
	    {
	      (*it).setNourriture((*it).getNourriture() - 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setNourriture(this->_case[(*it).getPos().second][(*it).getPos().first].getNourriture() + 1);
	    }
	  if (ressource == 1)
	    {
	      (*it).setLinemate((*it).getLinemate() - 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setLinemate(this->_case[(*it).getPos().second][(*it).getPos().first].getLinemate() + 1);
	    }
	  if (ressource == 2)
	    {
	      (*it).setDeraumere((*it).getDeraumere() - 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setDeraumere(this->_case[(*it).getPos().second][(*it).getPos().first].getDeraumere() + 1);
	    }
	  if (ressource == 3)
	    {
	      (*it).setSibur((*it).getSibur() - 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setSibur(this->_case[(*it).getPos().second][(*it).getPos().first].getSibur() + 1);
	    }
	  if (ressource == 4)
	    {
	      (*it).setSibur((*it).getSibur() - 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setMendiane(this->_case[(*it).getPos().second][(*it).getPos().first].getMendiane() + 1);
	    }
	  if (ressource == 5)
	    {
	      (*it).setMendiane((*it).getMendiane() - 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setPhiras(this->_case[(*it).getPos().second][(*it).getPos().first].getPhiras() + 1);
	    }
	  if (ressource == 6)
	    {
	      (*it).setThystame((*it).getThystame() - 1);
	      this->_case[(*it).getPos().second][(*it).getPos().first].setThystame(this->_case[(*it).getPos().second][(*it).getPos().first].getThystame() + 1);
	    }
	  break;
	}
    }
  return true;
}

bool                  Map::doPdi(const std::vector<std::string> &param) 
{
  int			numero;
  std::stringstream	ss;
  int			i = 0;

  if (param.size() != 2)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();

  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  this->_player.erase(it);
	  break;
	}
      i++;
    }
  return true;
}

//player oeuf
bool                  Map::doEnw(const std::vector<std::string> &param)
{
  int			numero;
  int			id;
  int			x;
  int			y;
  std::stringstream	ss;

  if (param.size() != 5)
    return false;
  ss << param.at(2).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();
  ss << param.at(1).c_str() + 1;
  ss >> id;
  ss.str("");
  ss.clear();
  ss << param.at(3);
  ss >> x;
  ss.str("");
  ss.clear();
  ss << param.at(4);
  ss >> y;
  ss.str("");
  ss.clear();

  for (std::vector<Player>::iterator it = this->_player.begin() ; it != this->_player.end(); ++it)
    {
      if ((*it).getNumero() == numero)
	{
	  Eggs	eg(std::make_pair(x, y), (*it).getTeam(), id);

	  this->_eggs.push_back(eg);
	  break;
	}
    }
  return true;
}
bool                  Map::doEht(const std::vector<std::string> &param) 
{
  std::stringstream	ss;
  int			numero;

  if (param.size() != 2)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();

  for (std::vector<Eggs>::iterator it = this->_eggs.begin() ; it != this->_eggs.end(); ++it)
    {
      if ((*it).getId() == numero)
	{
	  this->_eggs.erase(it);
	  break;
	}
    }
  return true;
}

bool                  Map::doEbo(const std::vector<std::string> &param) {(void) param; return true;}

bool                  Map::doEdi(const std::vector<std::string> &param) 
{
  std::stringstream	ss;
  int			numero;

  if (param.size() != 2)
    return false;
  ss << param.at(1).c_str() + 1;
  ss >> numero;
  ss.str("");
  ss.clear();

  for (std::vector<Eggs>::iterator it = this->_eggs.begin() ; it != this->_eggs.end(); ++it)
    {
      if ((*it).getId() == numero)
	{
	  this->_eggs.erase(it);
	  break;
	}
    }
  return true;
}
