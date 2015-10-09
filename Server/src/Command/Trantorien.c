/*
** Trantorien.c for Trantorien in /home/david_k/PSU_2014_zappy/Trantorien
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 18 16:48:56 2015 paul david
** Last update Sun Jul  5 04:32:47 2015 paul david
*/

#include "Trantorien.h"
#include "server.h"
#include "String.h"

extern bool g_quit;

void	trantorien_init(t_trantorien *this, int *xy, int *xy_limit)
{
  int	i;

  i = 0;
  if ((this->move = malloc(sizeof(t_move) * 4)) != NULL)
    {
      init_move(this);
      init_see(this);
      init_expulse(this);
      init_broad(this);
      this->xy_limit[0] = xy_limit[0];
      this->xy_limit[1] = xy_limit[1];
      X = xy[0];
      Y = xy[1];
      this->vision = 1;
      this->direction = North;
      ressources_init(&this->objects[0], 10, i);
      while (++i != 7)
	ressources_init(&this->objects[i], 0, i);
      init_movement(this);
      init_primary(this);
      init_incant(this);
      init_all(this);
    }
  else
    g_quit = false;
}

void	trantorien_destroy(t_trantorien *this)
{
  int	i;

  i = 0;
  while (i != 7)
    {
      ressources_destroy(&this->objects[i]);
      i++;
    }
  if (this->move != NULL)
    free(this->move);
  if (this->incant != NULL)
    free(this->incant);
  memset(this, 0, sizeof(t_trantorien));
}
