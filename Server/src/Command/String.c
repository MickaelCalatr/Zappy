/*
** String.c for String in /home/david_k/cpp_rendu/piscine_cpp_d03/ex00
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Fri Jan  9 09:38:34 2015 paul david
** Last update Mon Jun 22 15:16:20 2015 paul david
*/

#include "String.h"

static void assign_s(t_string *this, t_string const *str)
{
  if (this->str != NULL)
    free(this->str);
  this->str = strdup(str->str);
}

static void assign_c(t_string *this, char const *s)
{
  if (this->str != NULL)
    free(this->str);
  this->str = strdup(s);
}

static void append_s(t_string *this, t_string const *ap)
{
  char	*tmp;

  if (this->str == NULL && ap->str != NULL)
    this->str = strdup(ap->str);
  else if (this->str != NULL && ap->str != NULL)
    {
      tmp = my_strcat(this->str, ap->str);
      free(this->str);
      this->str = tmp;
    }
}

static void append_c(t_string *this, char const *ap)
{
  char *tmp;

  if (this->str == NULL && ap != NULL)
    this->str =strdup(ap);
  else if (this->str!= NULL && ap != NULL)
    {
      tmp = my_strcat(this->str, ap);
      free(this->str);
      this->str = tmp;
    }
}

void	string_init_first(t_string *this)
{
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
  this->append_c = &append_c;
  this->append_s = &append_s;
}
