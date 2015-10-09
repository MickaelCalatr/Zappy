/*
** String_third.c for String_third in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 22 14:27:21 2015 paul david
** Last update Tue Jun 30 18:33:30 2015 paul david
*/

#include "String.h"

static char	*c_str(t_string *this)
{
  return (this->str);
}

static int	empty(t_string *this)
{
  if (this->str == NULL)
    return (1);
  if (this->str[0] == '\0')
    return (1);
  return (-1);
}

static int	find_s(t_string *this, const t_string *str, size_t pos)
{
  char		*new;

  if (pos > strlen(this->str) || this->str == NULL || str->str == NULL)
    return (-1);
  if (strlen(this->str + pos) < strlen(str->str))
    return (-1);
  if ((new = strstr((this->str) + pos, str->str)) == NULL)
    return (-1);
  return ((strlen(this->str) - strlen(new)) - pos);
}

static int	find_c(t_string *this, char const *str, size_t pos)
{
  char		*new;

  if (pos > strlen(this->str) || this->str == NULL || str == NULL)
    return (-1);
  if (strlen(this->str + pos) < strlen(str))
    return (-1);
  if ((new = strstr((this->str) + pos, str)) == NULL)
    return (-1);
  return ((strlen(this->str) - strlen(new)) - pos);
}

void	string_init_third(t_string *this)
{
  this->c_str = &c_str;
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
}
