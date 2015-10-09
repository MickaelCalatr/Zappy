/*
** Tranto_movement.c for Tranto_movement in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 25 15:22:23 2015 paul david
** Last update Wed Jul  1 20:26:31 2015 paul david
*/

#include "Trantorien.h"

static void     forward(t_trantorien *this)
{
  int           i;

  i = 0;
  while (this->direction != this->move[i].direction)
    i++;
  if (this->direction == this->move[i].direction)
    this->move[i].move(this);
}

static void     turn_left(t_trantorien *this)
{
  this->direction -= 1;
  if ((int)this->direction < 0)
    this->direction = 3;
}

static void     turn_right(t_trantorien *this)
{
  this->direction += 1;
  if ((int)this->direction > 3)
    this->direction = 0;
}

void	init_movement(t_trantorien *this)
{
  this->forward = &forward;
  this->turn_left = &turn_left;
  this->turn_right = &turn_right;
}
