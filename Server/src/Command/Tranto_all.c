/*
** Tranto_all.c for Tranto_all in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Jul  5 04:05:08 2015 paul david
** Last update Sun Jul  5 04:14:20 2015 paul david
*/

#include "Trantorien.h"
#include "server.h"

static void	empty_lvl(t_trantorien *this, t_map *map)
{
  int		i;

  i = 0;
  while (++i != 7)
    {
      MAP(X, Y).objects[i].quantity -=
        this->incant[this->vision - 1].objects[i].quantity;
    }
}

static int	broadcast(t_trantorien *this, int *pos)
{
  int		i;

  i = 0;
  while (this->direction != this->move[i].direction)
    i++;
  return (this->move[i].broad(this, pos));
}

static int	expulse(t_trantorien *this, int *pos, Direction direction)
{
  int		i;

  i = 0;
  while (this->direction != this->move[i].direction)
    i++;
  return (this->move[i].expulse(this, pos, direction));
}

void	init_all(t_trantorien *this)
{
  this->expulse = &expulse;
  this->broadcast = &broadcast;
  this->empty_lvl = &empty_lvl;
}
