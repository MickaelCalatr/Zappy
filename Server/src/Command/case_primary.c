/*
** case_primary.c for case_primary in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed Jul  1 13:50:25 2015 paul david
** Last update Sun Jul  5 13:04:53 2015 paul david
*/

#include "case.h"
#include "server.h"

static char	*player_list(t_case *this, t_client **user, int nb)
{
  int		i;
  t_string	str;
  char		*s;

  i = 3;
  stringInit(&str, "");
  while (++i != nb)
    {
      if (user[i] != NULL && user[i]->graphic != true &&
          (this->xy[0] == user[i]->trant.xy[0] &&
           this->xy[1] == user[i]->trant.xy[1]))
        {
	  str.append_c(&str, " ");
          str.append_c(&str, "joueur");
        }
    }
  s = str.c_str(&str);
  return (s);
}

static char	*ressources_list(t_case *this, t_client **user, int nb)
{
  int		i;
  int		j;
  char		*s;
  t_string	str;

  s = this->player_list(this, user, nb);
  stringInit(&str, s);
  free(s);
  i = -1;
  while (this->is_empty(this) != 0 && ++i != 7)
    {
      j = -1;
      while (this->objects[i].quantity != 0
             && ++j < this->objects[i].quantity)
	{
	  str.append_c(&str, " ");
	  str.append_c(&str, this->objects[i].getname(&this->objects[i]));
	}
    }
  s = str.c_str(&str);
  return (s);
}

static int	take_ressources(struct s_case *this, char *res)
{
  int		i;

  i = 0;
  while (g_char_ress[i].tochar != NULL &&
         strcmp(g_char_ress[i].tochar, res) != 0)
    i++;
  if (g_char_ress[i].tochar != NULL)
    if (this->objects[i].quantity > 0)
      {
        this->objects[i].quantity--;
        return (1);
      }
  return (0);
}

static int	add_ressources(struct s_case *this, char *res)
{
  int		i;

  i = 0;
  while (g_char_ress[i].tochar != NULL
         && strcmp(g_char_ress[i].tochar, res) != 0)
    i++;
  if (g_char_ress[i].tochar != NULL)
    {
      this->objects[i].quantity++;
      return (1);
    }
  return (0);
}

void	case_primary(t_case *this)
{
  this->ressources_list = &ressources_list;
  this->take_ressources = &take_ressources;
  this->add_ressources = &add_ressources;
  this->player_list = &player_list;
}
