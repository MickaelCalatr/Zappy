/*
** String_second.c for String_second in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 22 14:25:23 2015 paul david
** Last update Mon Jun 22 15:14:17 2015 paul david
*/

#include "String.h"

static void	clear(t_string *this)
{
  if (this->str != NULL)
    memset(this->str, 0, strlen(this->str));
}

static int	size(t_string *this)
{
  if (this->str == NULL)
    return (-1);
  return (strlen(this->str));
}

static int	compare_s(t_string *this, const t_string *str)
{
  return (strcmp(this->str, str->str));
}

static int	compare_c(t_string *this, char const *str)
{
  return (strcmp(this->str, str));
}

void	string_init_second(t_string *this)
{
  this->clear = &clear;
  this->size = &size;
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
}
