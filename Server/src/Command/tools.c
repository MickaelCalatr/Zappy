/*
** tools.c for tools in /home/david_k/rendu/Zappy
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed May 13 14:50:41 2015 paul david
** Last update Wed Jul  1 14:17:12 2015 paul david
*/

#include "ZappyServer.h"

int	is_numeric(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	++i;
      else
	return (0);
    }
  return (1);
}
