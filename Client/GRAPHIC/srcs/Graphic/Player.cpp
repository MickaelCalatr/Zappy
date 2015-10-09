//
// Player.cpp for zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/GRAPHIC/srcs/Graphic
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Tue Jun 30 18:23:23 2015 Alexandre Tanyeres
// Last update Sun Jul  5 16:45:25 2015 Alexandre Tanyeres
//

#include "Player.hpp"

Player::Player(std::pair<int, int> pos, std::string team, int num, int ore, int lvl, int nour, int line, int der, int sib, int mend, int phi, int thy, bool mes) : _pos(pos), _team(team), _numero(num), _orientation(ore), _lvl(lvl), _nourriture(nour), _linemate(line), _deraumere(der), _sibur(sib), _mendiane(mend), _phiras(phi), _thystame(thy), _message(mes)
{
}

Player::~Player()
{}

void                  Player::doPlv(int lvl)
{ this->_lvl = lvl; }

void                  Player::doPin()
{}

void                  Player::doPbc() {this->_clock.restart();}

void                  Player::doPic() {}

void                  Player::doPie() {}

void                  Player::doPfk() {}

void                  Player::doPdr() {}

void                  Player::doPgt() {}
