//
// Case.cpp for zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/GRAPHIC/srcs/Graphic
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Tue Jun 30 15:29:42 2015 Alexandre Tanyeres
// Last update Sun Jul  5 05:09:07 2015 Alexandre Tanyeres
//

#include "Case.hpp"

Case::Case()
{
  this->_nourriture = 0;
  this-> _linemate = 0;
  this->_deraumere = 0;
  this->_sibur = 0;
  this->_mendiane = 0;
  this->_phiras = 0;
  this->_thystame = 0;
  this->_inc = false;
}

Case::~Case() {}

void                  Case::doBct(int nou, int lin, int der, int sib, int men, int phi, int thy)
{
  this->_nourriture = nou;
  this-> _linemate = lin;
  this->_deraumere = der;
  this->_sibur = sib;
  this->_mendiane = men;
  this->_phiras = phi;
  this->_thystame = thy;
}
