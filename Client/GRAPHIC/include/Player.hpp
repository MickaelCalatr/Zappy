//
// Player.hpp for zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/GRAPHIC/include
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Tue Jun 30 17:41:28 2015 Alexandre Tanyeres
// Last update Sun Jul  5 16:55:31 2015 Alexandre Tanyeres
//

#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

class Player
{
public:
  Player(std::pair<int, int> pos, std::string team, int num, int ore, int lvl, int nour, int line, int der, int sib, int mend, int phi, int thy, bool mes);
  ~Player();
  //player
  void			doPpo(std::pair<int, int>, int);
  void                  doPlv(int);
  void                  doPin();
  void                  doPbc();
  void                  doPic();
  void                  doPie();
  void                  doPfk();
  void                  doPdr();
  void                  doPgt();
  void                  setPos(std::pair<int, int> pos) {this->_pos = pos;}
  void                  setLevel(int i) {this->_lvl = i;}
  void                  setOrientation(int i) {this->_orientation = i;}
  void                  setTeam(const std::string &team) {this->_team = team;}
  void                  setNumero(int num) {this->_numero = num;}
  void                  setNourriture(int nou) {this->_nourriture = nou;}
  void                  setLinemate(int lin) {this->_linemate = lin;}
  void                  setDeraumere(int der) {this->_deraumere = der;}
  void                  setSibur(int sib) {this->_sibur = sib;}
  void                  setMendiane(int men) {this->_mendiane = men;}
  void                  setPhiras(int phi) {this->_phiras = phi;}
  void                  setThystame(int thy) {this->_thystame = thy;}
  void                  setMessage(bool mes) {this->_message = mes;}
  const int             &getNumero() const {return (this->_numero);}
  std::pair<int, int>   getPos() const {return (this->_pos);}
  std::string		getTeam() const {return (this->_team);}
  int			getOrient() const {return this->_orientation;}

  int			getNourriture() const {return (this->_nourriture);}
  int			getLinemate() const {return (this->_linemate);}
  int			getDeraumere() const {return (this->_deraumere);}
  int			getSibur() const {return (this->_sibur);}
  int			getMendiane() const {return (this->_mendiane);}
  int			getPhiras() const {return (this->_phiras);}
  int			getThystame() const {return (this->_thystame);}
  bool                  getMessage() {return this->_message;}
  int                   getLvl() {return this->_lvl;}
  float                 getClock() {return this->_clock.getElapsedTime().asSeconds();}
private:
  std::pair<int, int>   _pos;
  std::string		_team;
  int			_numero;
  int			_orientation;
  int			_lvl;
  int                   _nourriture;
  int                   _linemate;
  int                   _deraumere;
  int                   _sibur;
  int                   _mendiane;
  int                   _phiras;
  int                   _thystame;
  bool			_message;
  sf::Clock		_clock;
};
