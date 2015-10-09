/*
** ressources.c for ressources in /home/david_k/PSU_2014_zappy/Ressources
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 18 17:52:11 2015 paul david
** Last update Sat Jul  4 18:27:35 2015 paul david
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ressources.h"

t_cress g_char_ress[] =
  {
    {nourriture, "nourriture"},
    {linemate, "linemate"},
    {deraumere, "deraumere"},
    {sibur, "sibur"},
    {mendiane, "mendiane"},
    {phiras, "phiras"},
    {thystame, "thystame"},
    {thystame, NULL}
  };

static char	*getinventory(t_ressources *this)
{
  char		*s;
  char		tmp[456];
  int		i;
  int		t;

  i = 0;
  while (g_char_ress[i].type != this->type)
    i++;
  t = sprintf(tmp, "%s %d", g_char_ress[i].tochar, this->quantity);
  s = malloc(sizeof(char) * (t + 1));
  sprintf(s, "%s %d", g_char_ress[i].tochar, this->quantity);
  return (s);
}

static char	*getname(t_ressources *this)
{
  int	i;

  i = 0;
  while (g_char_ress[i].type != this->type)
    i++;
  return (g_char_ress[i].tochar);
}

void	ressources_init(t_ressources *this, int quantity, r_type type)
{
  this->type = type;
  this->quantity = quantity;
  this->getinventory = &getinventory;
  this->getname = &getname;
}

void	ressources_destroy(t_ressources *this)
{
  memset(this, 0, sizeof(t_ressources));
}
