//
// Buffer.cpp for Buffer in /home/bechad_p/rendu/PSU_2014_zappy/Client/GRAPHIC/srcs/Core
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Fri Jul  3 16:21:10 2015 Pierre Bechade
// Last update Sun Jul  5 22:34:54 2015 paul david
//

#include "Buffer.hpp"

Buffer::Buffer(Map &map) : _map(map)
{
  this->_fgraph["msz"] = &Map::doMsz;
  this->_fgraph["bct"] = &Map::doBct;
  this->_fgraph["tna"] = &Map::doTna;
  this->_fgraph["pnw"] = &Map::doPnw;
  this->_fgraph["ppo"] = &Map::doPpo;
  this->_fgraph["plv"] = &Map::doPlv;
  this->_fgraph["pin"] = &Map::doPin;
  this->_fgraph["pex"] = &Map::doPex;
  this->_fgraph["pbc"] = &Map::doPbc;
  this->_fgraph["pic"] = &Map::doPic;
  this->_fgraph["pie"] = &Map::doPie;
  this->_fgraph["pfk"] = &Map::doPfk;
  this->_fgraph["pdr"] = &Map::doPdr;
  this->_fgraph["pgt"] = &Map::doPgt;
  this->_fgraph["pdi"] = &Map::doPdi;
  this->_fgraph["enw"] = &Map::doEnw;
  this->_fgraph["eht"] = &Map::doEht;
  this->_fgraph["ebo"] = &Map::doEbo;
  this->_fgraph["edi"] = &Map::doEdi;
  this->_fgraph["sgt"] = &Map::doSgt;
  this->_fgraph["seg"] = &Map::doSeg;
  this->_fgraph["smg"] = &Map::doSmg;
  this->_fgraph["suc"] = &Map::doSuc;
  this->_fgraph["sbp"] = &Map::doSbp;
}

Buffer::~Buffer()
{
}

bool			Buffer::epur()
{
  std::string		tmp;
  std::istringstream	clean(this->_buff);

  while (clean >> tmp >> std::ws)
    {
      this->_argument.push_back(tmp);
    }
  if (this->_fgraph.find(this->_argument.front()) != this->_fgraph.end())
    {
      if ((this->_map.*this->_fgraph[this->_argument.front()])(this->_argument) == false)
	return false;
    }
  this->_argument.clear();
  return true;
}

void			Buffer::setBuffer(const std::string &buff)
{
  this->_buff = buff;
}
