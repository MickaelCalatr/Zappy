/*
** String_init.c for String_utility in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 22 14:19:28 2015 paul david
** Last update Wed Jul  1 20:03:43 2015 paul david
*/

#include "String.h"

static char	at(t_string *this, size_t pos)
{
  if (this->str == NULL)
    return (-1);
  if (pos > strlen(this->str))
    return (-1);
  return (this->str[pos]);
}

static size_t	copy(t_string *this, char *s, size_t n, size_t pos)
{
  size_t	i;

  i = 0;
  if (this->str == NULL || pos > strlen(this->str))
    return (0);
  while (i < n && this->str[pos] != '\0')
    {
      s[i] = this->str[pos];
      i++;
      pos++;
    }
  return (i);
}

char	*my_strcat(char *dest, char const *ap)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  new = malloc(sizeof(char) * (strlen(dest) + strlen(ap) + 1));
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i++;
    }
  while (ap[j] != '\0')
    {
      new[i] = ap[j];
      i++;
      j++;
    }
  new[i] = '\0';
  return (new);
}

void	stringInit(t_string *this, char const *s)
{
  this->str = strdup(s);
  this->at = &at;
  this->copy = &copy;
  string_init_first(this);
  string_init_second(this);
  string_init_third(this);
}

void	stringDestroy(t_string *this)
{
  if (this->str != NULL)
    free(this->str);
  memset(this, 0, sizeof(t_string));
}
