/*
** Tranto_move.c for Tranto_move in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 25 14:53:05 2015 paul david
** Last update Sun Jul  5 01:56:54 2015 paul david
*/

#include "Trantorien.h"

static void	to_north(t_trantorien *this)
{
  Y -= 1;
  if (Y < 0)
    Y = this->xy_limit[1] - 1;
}

static void	to_south(t_trantorien *this)
{
  Y += 1;
  if (Y >= this->xy_limit[1])
    Y = 0;
}

static void	to_west(t_trantorien *this)
{
  this->xy[0] -= 1;
  if (this->xy[0] < 0)
    X = this->xy_limit[0] - 1;
}

static void	to_east(t_trantorien *this)
{
  this->xy[0] += 1;
  if (this->xy[0] >= this->xy_limit[0])
    this->xy[0] = 0;
}

void	init_move(t_trantorien *this)
{
  this->move[0].direction = North;
  this->move[0].move = &to_north;
  this->move[1].direction = East;
  this->move[1].move = &to_east;
  this->move[2].direction = South;
  this->move[2].move = &to_south;
  this->move[3].direction = West;
  this->move[3].move = &to_west;
}
