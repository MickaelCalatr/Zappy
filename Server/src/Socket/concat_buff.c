/*
** concat_buff.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src/Network
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Sat Jun 20 03:49:08 2015 Caltraba Mickael
** Last update Sun Jul  5 12:24:51 2015 Caltraba Mickael
*/

#include <string.h>
#include "server.h"

void	concat_buff(char buff[], char *conc, int size)
{
  strncat(buff, conc, size);
}
