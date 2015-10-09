/*
** case.c for case in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 22 14:02:23 2015 paul david
** Last update Sun Jul  5 06:01:07 2015 paul david
*/

#include "case.h"
#include "server.h"

static int	is_empty(t_case *this)
{
  int		i;

  i = 0;
  while (i != 7)
    {
      if (this->objects[i].quantity != 0)
	return (1);
      i++;
    }
  return 0;
}

void	case_init(t_case *this, int x, int y)
{
  int	i;

  i = 0;
  while (i != 7)
    {
      ressources_init(&this->objects[i], 0, i);
      i++;
    }
  this->xy[0] = x;
  this->xy[1] = y;
  this->is_empty = &is_empty;
  case_primary(this);
}

void case_destroy(t_case *this)
{
  int	i;

  i = 0;
  while (i != 7)
    {
      ressources_destroy(&this->objects[i]);
      i++;
    }
  memset(this, 0, sizeof(t_case));
}
