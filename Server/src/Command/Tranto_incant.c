/*
** Tranto_incant.c for Tranto_incat in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed Jul  1 14:33:46 2015 paul david
** Last update Sun Jul  5 19:36:13 2015 paul david
*/

#include "Trantorien.h"
#include "server.h"

static int	incantation(t_trantorien *this, t_client **user, int nb,
			    t_map *map)
{
  int	p;
  int	i;

  p = 0 ;
  i = 3;
  while (++i < nb)
    if (user[i] != NULL && user[i]->graphic != true
	&& (this->xy[0] == user[i]->trant.xy[0]
	    && this->xy[1] == user[i]->trant.xy[1])
	&& this->vision == user[i]->trant.vision)
      p++;
  if (p < this->incant[this->vision - 1].nb)
    return (0);
  i = 0;
  if (this->objects[0].quantity <
      this->incant[this->vision - 1].objects[i].quantity)
    return 0;
  while (++i != 7)
    if (MAP(X, Y).objects[i].quantity
	< this->incant[this->vision - 1].objects[i].quantity)
      {
	return (0);
      }
  return (1);
}

static void	first_half_lvl(t_trantorien *this)
{
  this->incant[0].objects[0].quantity = 4;
  this->incant[0].objects[1].quantity = 1;
  this->incant[1].objects[0].quantity = 4;
  this->incant[1].objects[1].quantity = 1;
  this->incant[1].objects[2].quantity = 1;
  this->incant[1].objects[3].quantity = 1;
  this->incant[2].objects[0].quantity = 4;
  this->incant[2].objects[1].quantity = 2;
  this->incant[2].objects[3].quantity = 1;
  this->incant[2].objects[5].quantity = 1;
  this->incant[3].objects[0].quantity = 4;
  this->incant[3].objects[1].quantity = 1;
  this->incant[3].objects[2].quantity = 1;
  this->incant[3].objects[3].quantity = 2;
  this->incant[3].objects[5].quantity = 1;
}

static void	second_half_lvl(t_trantorien *this)
{
  this->incant[4].objects[0].quantity = 4;
  this->incant[4].objects[1].quantity = 1;
  this->incant[4].objects[2].quantity = 2;
  this->incant[4].objects[3].quantity = 1;
  this->incant[4].objects[4].quantity = 3;
  this->incant[5].objects[0].quantity = 4;
  this->incant[5].objects[1].quantity = 1;
  this->incant[5].objects[2].quantity = 2;
  this->incant[5].objects[3].quantity = 3;
  this->incant[5].objects[5].quantity = 1;
  this->incant[6].objects[0].quantity = 4;
  this->incant[6].objects[1].quantity = 2;
  this->incant[6].objects[2].quantity = 2;
  this->incant[6].objects[3].quantity = 2;
  this->incant[6].objects[4].quantity = 2;
  this->incant[6].objects[5].quantity = 2;
  this->incant[6].objects[6].quantity = 1;
}

void	init_incant(t_trantorien *this)
{
  int	i;
  int	j;
  int	nb;

  i = -1;
  this->incant = malloc(sizeof(t_lvl_up) * 7);
  nb = 1;
  while (++i != 7)
    {
      j = -1;
      this->incant[i].lvl = i + 1;
      if ((i + 1) % 2 == 0)
	nb++;
      this->incant[i].nb = nb;
      while (++j != 7)
	ressources_init(&this->incant[i].objects[j], 0, j);
    }
  first_half_lvl(this);
  second_half_lvl(this);
  this->incantation = &incantation;
}
