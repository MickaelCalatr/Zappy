/*
** Tranto_expulse.c for Tranto_expulse in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed Jul  1 18:12:59 2015 paul david
** Last update Sat Jul  4 13:50:00 2015 paul david
*/

#include "Trantorien.h"

int	broad_north(t_trantorien *this, int *pos)
{
  if (this->xy[0] == pos[0] && this->xy[1] == pos[1])
    return (0);
  else if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (1);
  else if (this->xy[0] > pos[0] && this->xy[1] > pos[1])
    return (8);
  else if (this->xy[0] < pos[0] && this->xy[1] > pos[1])
    return (2);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (5);
  else if (this->xy[0] < pos[0] && this->xy[1] < pos[1])
    return (4);
  else if (this->xy[0] > pos[0] && this->xy[1] < pos[1])
    return (6);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (7);
  else
    return (3);
}

int	broad_south(t_trantorien *this, int *pos)
{
  if (this->xy[0] == pos[0] && this->xy[1] == pos[1])
    return (0);
  else if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (5);
  else if (this->xy[0] > pos[0] && this->xy[1] > pos[1])
    return (4);
  else if (this->xy[0] < pos[0] && this->xy[1] > pos[1])
    return (6);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (1);
  else if (this->xy[0] < pos[0] && this->xy[1] < pos[1])
    return (8);
  else if (this->xy[0] > pos[0] && this->xy[1] < pos[1])
    return (2);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (3);
  else
    return (7);
}

int	broad_east(t_trantorien *this, int *pos)
{
  if (this->xy[0] == pos[0] && this->xy[1] == pos[1])
    return (0);
  else if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (7);
  else if (this->xy[0] > pos[0] && this->xy[1] > pos[1])
    return (8);
  else if (this->xy[0] < pos[0] && this->xy[1] > pos[1])
    return (6);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (3);
  else if (this->xy[0] > pos[0] && this->xy[1] < pos[1])
    return (2);
  else if (this->xy[0] < pos[0] && this->xy[1] < pos[1])
    return (4);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (1);
  else
    return (5);
}

int	broad_west(t_trantorien *this, int *pos)
{
  if (this->xy[0] == pos[0] && this->xy[1] == pos[1])
    return (0);
  else if (this->xy[0] == pos[0] && this->xy[1] > pos[1])
    return (7);
  else if (this->xy[0] > pos[0] && this->xy[1] > pos[1])
    return (4);
  else if (this->xy[0] < pos[0] && this->xy[1] > pos[1])
    return (2);
  else if (this->xy[0] == pos[0] && this->xy[1] < pos[1])
    return (3);
  else if (this->xy[0] > pos[0] && this->xy[1] < pos[1])
    return (6);
  else if (this->xy[0] < pos[0] && this->xy[1] < pos[1])
    return (8);
  else if (this->xy[1] == pos[1] && this->xy[0] > pos[0])
    return (5);
  else
    return (1);
}

void	init_broad(t_trantorien *this)
{
  this->move[0].broad = &broad_north;
  this->move[2].broad = &broad_south;
  this->move[1].broad = &broad_east;
  this->move[3].broad = &broad_west;
}
