/*
** map.c for map in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 22 15:26:12 2015 paul david
** Last update Sun Jul  5 04:33:04 2015 paul david
*/

#include "map.h"
#include "server.h"

extern bool g_quit;

void	init_map(t_map *this, int *limit)
{
  int	y;
  int	x;

  if ((this->map = malloc(sizeof(t_case *) * limit[1])) != NULL)
    {
      y = -1;
      while (++y != limit[1])
	if ((this->map[y] = malloc(sizeof(t_case) * limit[0])) != NULL)
	  {
	    x = -1;
	    while (++x != limit[0])
	      case_init(&this->map[y][x], x, y);
	  }
	else
	  {
	    y = limit[1];
	    g_quit = false;
	  }
      this->limit[0] = limit[0];
      this->limit[1] = limit[1];
    }
  else
    g_quit = false;
}
void	destroy_map(t_map *this)
{
  int	y;
  int	x;

  y = -1;
  if (this->map != NULL)
    {
      while (++y != this->limit[1])
	{
	  x = -1;
	  if (this->map[y] != NULL)
	    {
	      while (++x != this->limit[0])
		case_destroy(&this->map[y][x]);
	      free(this->map[y]);
	    }
	}
      free(this->map);
    }
  memset(this, 0, sizeof(t_map));
}
