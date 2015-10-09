/*
** Tranto_expulse.c for Tranto_expulse in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed Jul  1 18:12:59 2015 paul david
** Last update Fri Jul  3 14:34:38 2015 paul david
*/

#include "Trantorien.h"

int		exp_north(t_trantorien *this, int *pos, Direction direction)
{
  Direction	tmp;

  tmp = this->direction;
  this->direction = direction;
  this->forward(this);
  this->direction = tmp;
  if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (1);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (5);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (7);
  else
    return (3);
}

int		exp_south(t_trantorien *this, int *pos, Direction direction)
{
  Direction	tmp;

  tmp = this->direction;
  this->direction = direction;
  this->forward(this);
  this->direction = tmp;
  if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (5);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (1);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (3);
  else
    return (7);
}

int		exp_east(t_trantorien *this, int *pos, Direction direction)
{
  Direction	tmp;

  tmp = this->direction;
  this->direction = direction;
  this->forward(this);
  this->direction = tmp;
  if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (3);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (7);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (1);
  else
    return (5);
}

int		exp_west(t_trantorien *this, int *pos, Direction direction)
{
  Direction	tmp;

  tmp = this->direction;
  this->direction = direction;
  this->forward(this);
  this->direction = tmp;
  if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (7);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (3);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (5);
  else
    return (1);
}

void	init_expulse(t_trantorien *this)
{
  this->move[0].expulse = &exp_north;
  this->move[2].expulse = &exp_south;
  this->move[1].expulse = &exp_east;
  this->move[3].expulse = &exp_west;
}
