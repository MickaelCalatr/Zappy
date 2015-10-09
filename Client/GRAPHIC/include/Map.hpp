//
// Map.hpp for zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/GRAPHIC/include
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Tue Jun 30 17:36:25 2015 Alexandre Tanyeres
// Last update Sun Jul  5 21:58:56 2015 paul david
//

#include <vector>
#include <map>
#include "Player.hpp"
#include "Case.hpp"
#include "Eggs.hpp"

class Map
{
public:
  Map();
  ~Map();
  void                  CheckCase(std::pair<int, int> &pos);
  std::pair<int, int>	getSize() {return this->_sizeMap;}
  std::vector<Case*>	getCase() {return this->_case;}
  std::vector<Player>	getPlayer() {return this->_player;}
  std::vector<Eggs>	getEggs() {return this->_eggs;}
  std::vector<std::string>	getTeams() {return this->_teams;}
  int			getTime() {return this->time;}
  
  bool                  doMsz (const std::vector<std::string> &);
  bool                  doTna (const std::vector<std::string> &);
  bool                  doPnw (const std::vector<std::string> &);
  bool                  doPex (const std::vector<std::string> &);
  bool                  doPfk (const std::vector<std::string> &);
  bool                  doPdi (const std::vector<std::string> &);
  bool                  doSeg (const std::vector<std::string> &);
  bool                  doSmg (const std::vector<std::string> &);
  bool                  doSgt (const std::vector<std::string> &);
  bool                  doSuc (const std::vector<std::string> &);
  bool                  doSbp (const std::vector<std::string> &);
  //case
  bool                  doBct (const std::vector<std::string> &);
  //player
  bool                  doPpo (const std::vector<std::string> &);
  bool                  doPlv (const std::vector<std::string> &);
  bool                  doPin (const std::vector<std::string> &);
  bool                  doPbc (const std::vector<std::string> &);
  bool                  doPic (const std::vector<std::string> &);
  bool                  doPie (const std::vector<std::string> &);
  bool                  doPdr (const std::vector<std::string> &);
  bool                  doPgt (const std::vector<std::string> &);
  //oeuf
  bool                  doEnw (const std::vector<std::string> &);
  bool                  doEht (const std::vector<std::string> &);
  bool                  doEbo (const std::vector<std::string> &);
  bool                  doEdi (const std::vector<std::string> &);
private:
  std::pair<int, int>		_sizeMap;
  std::vector<Case*>		_case;
  std::vector<Player>		_player;
  std::vector<Eggs>		_eggs;
  std::vector<std::string>	_teams;
  int				time;
};
