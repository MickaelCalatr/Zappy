/*
** Tranto_see.c for Tranto_see in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 25 14:58:20 2015 paul david
** Last update Sun Jul  5 13:00:43 2015 paul david
*/

#include "Trantorien.h"
#include "server.h"

static char	*see_north(t_trantorien *this, t_map *map, t_client **user,
			   int nb)
{
  int		y;
  int		x;
  int		tmpy;
  int		tmpx;
  t_string	s;

  y = 0;
  stringInit(&s, MAP(X, Y).ressources_list(&MAP(X, Y), user, nb));
  while (++y != this->vision + 1)
    {
      x = -y;
      tmpy = ((Y - y) < 0) ? this->xy_limit[1] + (Y - y) : (Y - y);
      while (x != y + 1)
        {
          tmpx = (X + x < 0) ? this->xy_limit[0] + (X + x)
            : (X + x >= this->xy_limit[0]) ?
            (X + x) - this->xy_limit[0] : (X + x);
          s.append_c(&s, ",");
          s.append_c(&s, MAP(tmpx, tmpy).ressources_list(&MAP(tmpx, tmpy)
							   , user, nb));
          x++;
        }
    }
  return ((char *)s.c_str(&s));
}

static char	*see_south(t_trantorien *this, t_map *map, t_client **user,
			   int nb)
{
  int		y;
  int		x;
  int		tmpy;
  int		tmpx;
  t_string	s;

  y = 0;
  stringInit(&s, MAP(X, Y).ressources_list(&MAP(X, Y), user, nb));
  while (++y != (this->vision + 1))
    {
      x = y;
      tmpy = (Y + y >= this->xy_limit[1]) ?
        (Y + y) - this->xy_limit[1] : (Y + y);
      while (x != -(y + 1))
        {
          tmpx = (X + x < 0) ? this->xy_limit[0] + (X + x)
            : (X + x >= this->xy_limit[0]) ?
            (X + x) - this->xy_limit[0] : (X + x);
          s.append_c(&s, ",");
          s.append_c(&s, MAP(tmpx, tmpy).ressources_list(&MAP(tmpx, tmpy),
							   user, nb));
          x--;
        }
    }
  return ((char *)s.c_str(&s));
}

static char	*see_west(t_trantorien *this, t_map *map, t_client **user,
			  int nb)
{
  int		y;
  int		x;
  int		tmpy;
  int		tmpx;
  t_string	s;

  x = 0;
  stringInit(&s, MAP(X, Y).ressources_list(&MAP(X, Y), user, nb));
  while (++x != this->vision + 1)
    {
      y = x;
      tmpx = (X - x < 0) ?
        this->xy_limit[0] + (X - x) : (X - x);
      while (y != -(x + 1))
        {
          tmpy = (Y + y < 0) ? this->xy_limit[1] + (Y + y)
            : (Y + y >= this->xy_limit[1]) ?
            (Y + y) - this->xy_limit[1] : (Y + y);
          s.append_c(&s, ",");
          s.append_c(&s, MAP(tmpx, tmpy).ressources_list(&MAP(tmpx, tmpy),
							   user, nb));
          y--;
        }
    }
  return ((char *)s.c_str(&s));
}

static char	*see_east(t_trantorien *this, t_map *map, t_client **user,
			  int nb)
{
  int		y;
  int		x;
  int		tmpy;
  int		tmpx;
  t_string	s;

  x = 0;
  stringInit(&s, MAP(X, Y).ressources_list(&MAP(X, Y), user, nb));
  while (++x != this->vision + 1)
    {
      y = -x;
      tmpx = (X + x >= this->xy_limit[0]) ?
	(X + x) - this->xy_limit[0] : (X + x);
      while (y != x + 1)
        {
          tmpy = (Y + y < 0) ? this->xy_limit[1] + (Y + y)
            : (Y + y >= this->xy_limit[1]) ?
            (Y + y) - this->xy_limit[1] : (Y + y);
          s.append_c(&s, ",");
          s.append_c(&s, MAP(tmpx, tmpy).ressources_list(&MAP(tmpx, tmpy),
							   user, nb));
          y++;
        }
    }
  return ((char *)s.c_str(&s));
}

void	init_see(t_trantorien *this)
{
  this->move[0].d_see = &see_north;
  this->move[1].d_see = &see_east;
  this->move[2].d_see = &see_south;
  this->move[3].d_see = &see_west;
}
