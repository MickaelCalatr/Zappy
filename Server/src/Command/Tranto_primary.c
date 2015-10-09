/*
** Tranto_primary.c for Tranto_primary in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed Jul  1 13:23:55 2015 paul david
** Last update Sun Jul  5 17:19:01 2015 paul david
*/

#include "Trantorien.h"
#include "server.h"

static char	*inventory(t_trantorien *this)
{
  t_string	str;
  int		i;
  char		*tmp;

  stringInit(&str, "{");
  tmp = this->objects[0].getinventory(&this->objects[0]);
  str.append_c(&str, tmp);
  free(tmp);
  i = 0;
  while (++i != 7)
    {
      str.append_c(&str, ",");
      tmp = this->objects[i].getinventory(&this->objects[i]);
      str.append_c(&str, tmp);
    }
  str.append_c(&str, "}\n");
  return (str.str);
}

static char	*see(t_trantorien *this, t_map *map, t_client **user, int nb)
{
  int		i;
  t_string	s;

  i = 0;
  while (this->direction != this->move[i].direction)
    i++;
  stringInit(&s, "{");
  s.append_c(&s, this->move[i].d_see(this, map, user, nb));
  s.append_c(&s, "}\n");
  return (s.c_str(&s));
}

static int	take(t_trantorien *this, t_map *map, char *res)
{
  int		i;

  i = 0;
  if (MAP(X, Y).take_ressources(&MAP(X, Y), res) == 1)
    {
      while (strcmp(g_char_ress[i].tochar, res) != 0)
        i++;
      this->objects[i].quantity++;
      MAP(rand() % map->limit[0],
	  rand() % map->limit[1]).objects[i].quantity++;
      return (1);
    }
  return (0);
}

static int	drop(t_trantorien *this, t_map *map, char *res)
{
  int		i;

  i = 0;
  while (g_char_ress[i].tochar != NULL
         && strcmp(g_char_ress[i].tochar, res) != 0)
    i++;
  if (g_char_ress[i].tochar != NULL
      && this->objects[i].quantity > 0)
    {
      this->objects[i].quantity--;
      MAP(X, Y).add_ressources(&MAP(X, Y), res);
      return (1);
    }
  return (0);
}

void	init_primary(t_trantorien *this)
{
  this->inventory = &inventory;
  this->see = &see;
  this->take = &take;
  this->drop = &drop;
}
