//
// Buffer.hpp for Buffer in /home/bechad_p/rendu/PSU_2014_zappy/Client/GRAPHIC/include
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Fri Jul  3 16:23:08 2015 Pierre Bechade
// Last update Sun Jul  5 22:11:13 2015 paul david
//

#ifndef BUFFER_HPP_
# define BUFFER_HPP_

#include "Map.hpp"
#include <map>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

class Buffer
{
public:
  Buffer(Map &map);
  ~Buffer();
  bool  epur();
  void	setBuffer(const std::string &);
  typedef bool	(Map::*function)(const std::vector<std::string> &);
private:
  std::string				_buff;
  Map					&_map;
  std::map<std::string, function>	_fgraph;
  std::vector<std::string>		_argument;
};

#endif /* BUFFER_HPP_ */
