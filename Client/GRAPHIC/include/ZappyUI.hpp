//
// ZappyUI.hpp for Zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/include
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Thu Jun 25 17:09:05 2015 Alexandre Tanyeres
// Last update Sun Jul  5 04:56:25 2015 Alexandre Tanyeres
//

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Client.hpp"
#include "Buffer.hpp"

class ZappyUI
{
public:
  ZappyUI();
  ~ZappyUI();
  void			start(Map &);
  void			action(Map &);
protected:
  sf::RenderWindow	_window;
  std::pair<int, int>	_mapSize;
  std::pair<int, int>	_camPos;
  std::pair<int, int>	_caseSelect;
private:
  void			calcClic();
  void			drawMap();
  void			drawBord();
  void			drawATH(Map &);
  void			drawInfo(Map &);
  void			drawCase(Map &);
  void			plusX();
  void			lessX();
  void			plusY();
  void			lessY();
};
