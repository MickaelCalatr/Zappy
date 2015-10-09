//
// ZappyUI.cpp for Zappy in /home/tanyer_a/rendu/Tek_2/PSU_2014_zappy/Client/srcs/Graphic
// 
// Made by Alexandre Tanyeres
// Login   <tanyer_a@epitech.net>
// 
// Started on  Thu Jun 25 17:08:58 2015 Alexandre Tanyeres
// Last update Sun Jul  5 16:55:16 2015 Alexandre Tanyeres
//

#include "ZappyUI.hpp"

ZappyUI::ZappyUI()
{
  this->_camPos = std::make_pair<int, int>(0, 0);
  this->_caseSelect = std::make_pair<int, int>(0, 0);
  this->_window.create(sf::VideoMode(1300, 1000), "Zappy", sf::Style::Close);
  this->_window.setPosition(sf::Vector2i(540, 0));
  this->_window.setFramerateLimit(30);
}

ZappyUI::~ZappyUI()
{
}

void			ZappyUI::drawATH(Map &g_map)
{
  sf::RectangleShape	infoBar(sf::Vector2f(300, 1000));
  infoBar.setFillColor(sf::Color(26, 115, 228));
  infoBar.setPosition(0, 0);
  sf::RectangleShape	font(sf::Vector2f(1000, 1000));
  font.setFillColor(sf::Color(161, 87, 168));
  font.setPosition(300, 0);
  sf::RectangleShape	bord1(sf::Vector2f(926, 926));
  bord1.setFillColor(sf::Color(206, 249, 5));
  bord1.setPosition(338, 38);
  sf::RectangleShape	bord2(sf::Vector2f(916, 916));
  bord2.setFillColor(sf::Color(161, 87, 168));
  bord2.setPosition(343, 43);
  sf::RectangleShape	mapFont(sf::Vector2f(906, 906));
  mapFont.setFillColor(sf::Color(255, 255, 255));
  mapFont.setPosition(348, 48);
  this->_window.draw(infoBar);
  this->_window.draw(font);
  this->_window.draw(bord1);
  this->_window.draw(bord2);
  this->_window.draw(mapFont);
  this->drawInfo(g_map);
}

void			ZappyUI::drawInfo(Map &g_map)
{
  sf::Font font;
  if (!font.loadFromFile("Client/GRAPHIC/feature/ttf/mixo.ttf"))
    return;
  sf::Text text;
  sf::CircleShape shape(10);

  text.setFont(font);
  text.setCharacterSize(30);
  text.setColor(sf::Color::White);
  text.setString("X :");
  text.setPosition(40, 50);
  this->_window.draw(text);
  text.setString(std::to_string(this->_caseSelect.first));
  text.setPosition(80, 50);  
  this->_window.draw(text);
  text.setString("Y :");
  text.setPosition(140, 50);
  this->_window.draw(text);
  text.setString(std::to_string(this->_caseSelect.second));
  text.setPosition(180, 50);
  this->_window.draw(text);

  shape.setFillColor(sf::Color(219, 40, 35));
  shape.setOutlineThickness(4);
  shape.setOutlineColor(sf::Color(251, 27, 3));
  shape.setPosition(30, 125);
  this->_window.draw(shape);
  shape.setFillColor(sf::Color(242, 0, 255));
  shape.setOutlineColor(sf::Color(218, 0, 255));
  shape.setPosition(90, 125);
  this->_window.draw(shape);
  shape.setFillColor(sf::Color(21, 160, 233));
  shape.setOutlineColor(sf::Color(21, 195, 233));
  shape.setPosition(150, 125);
  this->_window.draw(shape);
  shape.setFillColor(sf::Color(153, 255, 0));
  shape.setOutlineColor(sf::Color(153, 255, 0));
  shape.setPosition(30, 190);
  this->_window.draw(shape);
  shape.setFillColor(sf::Color(255, 151, 0));
  shape.setOutlineColor(sf::Color(255, 206, 0));
  shape.setPosition(90, 190);
  this->_window.draw(shape);
  shape.setFillColor(sf::Color(255, 255, 255));
  shape.setOutlineColor(sf::Color(255, 255, 255));
  shape.setPosition(150, 190);
  this->_window.draw(shape);
  shape.setFillColor(sf::Color(235, 243, 16));
  shape.setOutlineColor(sf::Color(235, 243, 16));
  shape.setPosition(210, 190);
  this->_window.draw(shape);

  if (g_map.getCase().empty())
    return ;

  text.setString(std::to_string(g_map.getCase()[this->_caseSelect.second][this->_caseSelect.first].getNourriture()));
  text.setPosition(60, 118);
  this->_window.draw(text);
  text.setString(std::to_string(g_map.getCase()[this->_caseSelect.second][this->_caseSelect.first].getLinemate()));
  text.setPosition(120, 118);
  this->_window.draw(text);
  text.setString(std::to_string(g_map.getCase()[this->_caseSelect.second][this->_caseSelect.first].getDeraumere()));
  text.setPosition(180, 118);
  this->_window.draw(text);
  text.setString(std::to_string(g_map.getCase()[this->_caseSelect.second][this->_caseSelect.first].getSibur()));
  text.setPosition(60, 183);
  this->_window.draw(text);
  text.setString(std::to_string(g_map.getCase()[this->_caseSelect.second][this->_caseSelect.first].getMendiane()));
  text.setPosition(120, 183);
  this->_window.draw(text);
  text.setString(std::to_string(g_map.getCase()[this->_caseSelect.second][this->_caseSelect.first].getPhiras()));
  text.setPosition(180, 183);
  this->_window.draw(text);
  text.setString(std::to_string(g_map.getCase()[this->_caseSelect.second][this->_caseSelect.first].getThystame()));
  text.setPosition(240, 183);
  this->_window.draw(text);

  unsigned int i = 0, i2 = 0;
  int		u = 0;
  while(i != g_map.getPlayer().size())
    {
      if (g_map.getPlayer()[i].getPos() == this->_caseSelect)
	{
	  sf::Texture texture;
	  sf::Sprite sprite;
	  
	  if (!texture.loadFromFile("Client/GRAPHIC/feature/sprite/head5.png"))
	    return;
	  sprite.setTexture(texture);
	  sprite.setPosition(25, 350 + (u * 100));
	  this->_window.draw(sprite);
	  text.setCharacterSize(13);
	  text.setString(std::to_string(g_map.getPlayer()[i].getNumero()) + "-" + g_map.getPlayer()[i].getTeam());
	  text.setPosition(100, 360 + (u * 100));
	  this->_window.draw(text);

	  	  text.setString(std::to_string(g_map.getPlayer()[i].getNumero()) + "-" + g_map.getPlayer()[i].getTeam());
	  text.setPosition(100, 360 + (u * 100));
	  this->_window.draw(text);
	  
	  text.setString(std::to_string(g_map.getPlayer()[i].getNumero()) + "-" + g_map.getPlayer()[i].getTeam() + " - lvl: " + std::to_string(g_map.getPlayer()[i].getLvl()));
	  text.setPosition(100, 360 + (u * 100));
	  this->_window.draw(text);
	  
	  text.setString("Nour: " + std::to_string(g_map.getPlayer()[i].getNourriture()) +
			 ", Line: " + std::to_string(g_map.getPlayer()[i].getLinemate()) +
			 ", Der: " + std::to_string(g_map.getPlayer()[i].getDeraumere()));
	  text.setPosition(100, 375 + (u * 100));
	  this->_window.draw(text);
	  
	  text.setString("Sib: " + std::to_string(g_map.getPlayer()[i].getSibur()) +
			 ", Men: " + std::to_string(g_map.getPlayer()[i].getMendiane()) +
			 ", Phi: " + std::to_string(g_map.getPlayer()[i].getPhiras()) +
			 ", Thy: " + std::to_string(g_map.getPlayer()[i].getThystame()));
	  text.setPosition(100, 390 + (u * 100));
	  this->_window.draw(text);
	  u++;
	}
      i++;
    }
  u = 0;
  while(i2 != g_map.getEggs().size())
    {
      if (g_map.getEggs()[i2].getPos() == this->_caseSelect)
	{
	  sf::Texture texture2;
	  sf::Sprite sprite2;
	  
	  if (!texture2.loadFromFile("Client/GRAPHIC/feature/sprite/eggic.png"))
	    return;
	  sprite2.setTexture(texture2);
	  sprite2.setPosition(25 + (u * 100), 250);
	  this->_window.draw(sprite2);
	  text.setCharacterSize(13);
	  text.setString(std::to_string(g_map.getEggs()[i2].getId()) + "-" + g_map.getEggs()[i2].getTeam());
	  text.setPosition(80 + (u * 100), 270);
	  this->_window.draw(text);
	  u++;
	}
      i2++;
      }
}

void			ZappyUI::drawMap()
{
  int			i = 0, j = 0;
  int			x = 352, y = 52;
  sf::RectangleShape	caseMap(sf::Vector2f(98, 98));

  caseMap.setFillColor(sf::Color(24, 230, 44));
  while (j < 9 && j <= this->_mapSize.second)
    {
      while (i < 9 && i <= this->_mapSize.first)
	{
	  caseMap.setPosition(x, y);
	  this->_window.draw(caseMap);
	  x = x + 100;
	  ++i;
	}
      i = 0;
      x = 352;
      ++j;
      y = y + 100;
    }
  this->drawBord();
}

void			ZappyUI::drawBord()
{
   sf::CircleShape triangle(20, 3);
  triangle.setFillColor(sf::Color(244, 54, 10));
  sf::RectangleShape	angle(sf::Vector2f(2, 2));
  angle.setFillColor(sf::Color(24, 230, 44));
  sf::RectangleShape	bordHaut(sf::Vector2f(2, 98));
  bordHaut.setFillColor(sf::Color(24, 230, 44));
  sf::RectangleShape	bordLarge(sf::Vector2f(98, 2));
  bordLarge.setFillColor(sf::Color(24, 230, 44));

  if (this->_camPos.first != 0)
    {
      for (int i = -1; i != 8; ++i)
	{
	  bordHaut.setPosition(348, 152 + (i * 100));
	  this->_window.draw(bordHaut);
	}
      triangle.setRotation(-90);
      triangle.setPosition(318, 520);
      this->_window.draw(triangle);
    }
  if (this->_camPos.second != 0)
    {
      for (int i = -1; i != 8; ++i)
	{
	  bordLarge.setPosition(452 + (i * 100), 48);
	  this->_window.draw(bordLarge);
	}
      triangle.setRotation(0);
      triangle.setPosition(780, 18);
      this->_window.draw(triangle);
    }
  if (this->_camPos.first + 8 != this->_mapSize.first - 1)
    {
      for (int i = -1; i != 8; ++i)
	{
	  bordHaut.setPosition(1252, 152 + (i * 100));
	  this->_window.draw(bordHaut);
	}
      triangle.setRotation(90);
      triangle.setPosition(1284, 480);
      this->_window.draw(triangle);
    }
  if (this->_camPos.second + 8 != this->_mapSize.second - 1)
    {
      for (int i = -1; i != 8; ++i)
	{
	  bordLarge.setPosition(452 + (i * 100),952);
	  this->_window.draw(bordLarge);
	}
      triangle.setRotation(180);
      triangle.setPosition(820, 984);
      this->_window.draw(triangle);
    }
  if (this->_camPos.first != 0 && this->_camPos.second != 0)
    {
      angle.setPosition(348, 48);
      this->_window.draw(angle);
    }
  if (this->_camPos.second != 0 && this->_camPos.first + 8 != this->_mapSize.first - 1)
    {
      angle.setPosition(1252, 48);
      this->_window.draw(angle);
    }
  if (this->_camPos.first + 8 != this->_mapSize.first && this->_camPos.second + 8 != this->_mapSize.second)
    {
      angle.setPosition(1252, 952);
      this->_window.draw(angle);
    }
  if (this->_camPos.first != 0 && this->_camPos.second + 8 != this->_mapSize.second - 1)
    {
      angle.setPosition(348, 952);
      this->_window.draw(angle);
    }
}


void			ZappyUI::drawCase(Map &g_map)
{
  std::vector<Case*> g_case = g_map.getCase();
  

  if (g_case.empty())
    return ;
  unsigned int	i = 0;
  unsigned int	i2 = 0;
  int		m = 0;
  int	x = this->_camPos.first, y = this->_camPos.second;
  int	sx = 360, sy = 115;
  sf::CircleShape shape(5); 
  while (y < g_map.getSize().second && y < (this->_camPos.second + 9))
    {
      while (x < g_map.getSize().first && x < (this->_camPos.first + 9))
        {
	  i = 0;
	  while(i != g_map.getPlayer().size())
	    {
	      if (g_map.getPlayer()[i].getPos() == std::make_pair(x, y))
	  	{
	  	  sf::Texture texture;
	  	  sf::Sprite sprite;
		  
	  	  if (!texture.loadFromFile("Client/GRAPHIC/feature/sprite/player" + std::to_string(g_map.getPlayer()[i].getOrient()) + ".png"))
		    return;
	  	  sprite.setTexture(texture);
		  sprite.setPosition((100 * (x - this->_camPos.first)) + sx + (20 * m), (100 * (y - this->_camPos.second)) + sy - 60);
	  	  this->_window.draw(sprite);
		  if ((g_map.getPlayer()[i].getClock() < 4 / g_map.getTime()))
		    {
		      if (!texture.loadFromFile("Client/GRAPHIC/feature/sprite/bubble.png"))
			return;
		      sprite.setTexture(texture);
		      sprite.setPosition((100 * (x - this->_camPos.first)) + (sx - 5), (100 * (y - this->_camPos.second)) + (sy - 70));
		      this->_window.draw(sprite);
		    }
		  m++;
	  	}
	      i++;
	    }
	  m = 0;
	  i2 = 0;
	  while(i2 != g_map.getEggs().size())
	    {
	      if (g_map.getEggs()[i2].getPos() == std::make_pair(x, y))
	  	{
	  	  sf::Texture texture1;
	  	  sf::Sprite sprite1;
		  
		  if (!texture1.loadFromFile("Client/GRAPHIC/feature/sprite/egg.png"))
		    return;
		  sprite1.setTexture(texture1);
		  sprite1.setPosition((100 * (x - this->_camPos.first)) + sx + 65, (100 * (y - this->_camPos.second)) + sy - 40 + (10 * m));
		  this->_window.draw(sprite1);
	  	}
	      i2++;
	    }
	  if (g_case[y][x].getInc() == true)
	    {
	      sf::Texture texture3;
	      sf::Sprite sprite3;

	      if (!texture3.loadFromFile("Client/GRAPHIC/feature/sprite/up.png"))
		return;
	      sprite3.setTexture(texture3);
	      sprite3.setPosition((100 * (x - this->_camPos.first)) + (sx - 10) + (20 * m), (100 * (y - this->_camPos.second)) + sy - 70);
	      this->_window.draw(sprite3);
	    }
	  shape.setFillColor(sf::Color(219, 40, 35));
	  if (g_case[y][x].getNourriture() > 1)
	    shape.setOutlineThickness(3);
	  shape.setOutlineColor(sf::Color(251, 27, 3));
	  shape.setPosition((100 * (x - this->_camPos.first)) + sx + 10, (100 * (y - this->_camPos.second)) + sy);
	  if (g_case[y][x].getNourriture() != 0)
	    this->_window.draw(shape);

	  shape.setOutlineThickness(0);
	  shape.setFillColor(sf::Color(242, 0, 255));
	  if (g_case[y][x].getLinemate() > 1)
	    shape.setOutlineThickness(3);
	  shape.setOutlineColor(sf::Color(218, 0, 255));
	  shape.setPosition((100 * (x - this->_camPos.first)) + sx + 35, (100 * (y - this->_camPos.second)) + sy);
	  if (g_case[y][x].getLinemate() != 0)
	    this->_window.draw(shape);

	  shape.setOutlineThickness(0);
	  shape.setFillColor(sf::Color(21, 160, 233));
	  if (g_case[y][x].getDeraumere() > 1)
	  shape.setOutlineThickness(3);
	  shape.setOutlineColor(sf::Color(21, 195, 233));
	  shape.setPosition((100 * (x - this->_camPos.first)) + sx + 60, (100 * (y - this->_camPos.second)) + sy);
	  if (g_case[y][x].getDeraumere() != 0)
	    this->_window.draw(shape);

	  shape.setOutlineThickness(0);
	  shape.setFillColor(sf::Color(153, 255, 0));
	  if (g_case[y][x].getSibur() > 1)
	    shape.setOutlineThickness(3);
	  shape.setOutlineColor(sf::Color(153, 255, 0));
	  shape.setPosition((100 * (x - this->_camPos.first)) + sx - 2, (100 * (y - this->_camPos.second)) + sy + 18);
	  if (g_case[y][x].getSibur() != 0)
	    this->_window.draw(shape);

	  shape.setOutlineThickness(0);
	  shape.setFillColor(sf::Color(255, 151, 0));
	  if (g_case[y][x].getMendiane() > 1)
	    shape.setOutlineThickness(3);
	  shape.setOutlineColor(sf::Color(255, 206, 0));
	  shape.setPosition((100 * (x - this->_camPos.first)) + sx + 23, (100 * (y - this->_camPos.second)) + sy + 18);
	  if (g_case[y][x].getMendiane() != 0)
	    this->_window.draw(shape);

	  shape.setOutlineThickness(0);
	  shape.setFillColor(sf::Color(255, 255, 255));
	  if (g_case[y][x].getPhiras() > 1)
	    shape.setOutlineThickness(3);
	  shape.setOutlineColor(sf::Color(255, 255, 255));
	  shape.setPosition((100 * (x - this->_camPos.first)) + sx + 48, (100 * (y - this->_camPos.second)) + sy + 18);
	  if (g_case[y][x].getPhiras() != 0)
	    this->_window.draw(shape);

	  shape.setOutlineThickness(0);
	  shape.setFillColor(sf::Color(235, 243, 16));
	  if (g_case[y][x].getThystame() > 1)
	    shape.setOutlineThickness(2);
	  shape.setOutlineColor(sf::Color(235, 243, 16));
	  shape.setPosition((100 * (x - this->_camPos.first)) + sx + 73, (100 * (y - this->_camPos.second)) + sy + 18);
	  if (g_case[y][x].getThystame() != 0)
	    this->_window.draw(shape);
	  x++;
        }
      x = this->_camPos.first;
      y++;
    }
}

void			ZappyUI::calcClic()
{

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      sf::Vector2i pos = sf::Mouse::getPosition(this->_window);
      int		x, y;
      x = pos.x;
      y = pos.y;
      if ((x > 352 && x < 1252) && (y > 52 && y < 952))
	{
	  int	f_x;
	  int	f_y;
	  x = x - 352;
	  y = y - 52;
	  f_x = (x / 100) - 1;
	  f_y = (y / 100) - 1;
	  if (x % 100 > 0)
	    f_x += 1;
	  if (y % 100 > 0)
	    f_y += 1;
	  this->_caseSelect.first = this->_camPos.first + f_x;
	  this->_caseSelect.second = this->_camPos.second + f_y;
	}
      else if ((pos.x >= 780 && pos.x <= 818) && (pos.y >= 30 && pos.y <= 46))
      	lessY();
      else if ((pos.x >= 318 && pos.x <= 350) && (pos.y >= 484 && pos.y <= 517))
      	lessX();
      else if ((pos.x >= 784 && pos.x <= 817) && (pos.y >= 956 && pos.y <= 979))
      	plusY();
      else if ((pos.x >= 1254 && pos.x <= 1280) && (pos.y >= 484 && pos.y <= 519))
      	plusX();
    }
}

void			ZappyUI::plusX()
{
  if (this->_camPos.first + 8 == this->_mapSize.first - 1)
    return;
  else
    this->_camPos.first = this->_camPos.first + 1;
}

void			ZappyUI::lessX()
{
  if (this->_camPos.first == 0)
    return;
  else
    this->_camPos.first = this->_camPos.first - 1;
}

void			ZappyUI::plusY()
{
  if (this->_camPos.second + 8 == this->_mapSize.second - 1)
    return;
  else
    this->_camPos.second = this->_camPos.second + 1;
}

void			ZappyUI::lessY()
{
  if (this->_camPos.second == 0)
    return;
  else
    this->_camPos.second = this->_camPos.second - 1;
}

#include <iostream>

void			ZappyUI::action(Map &g_map)
{
  this->_window.clear();
  this->drawATH(g_map);
  this->drawMap();
  this->drawCase(g_map);
  this->calcClic();
  this->_window.display();
}

void		ZappyUI::start(Map &g_map)
{
  sf::Event event;

  this->_mapSize = g_map.getSize();
  while (this->_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	this->_window.close();
    }
  this->action(g_map);
}
