/*
** error.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Mon May 11 16:02:31 2015 Caltraba Mickael
** Last update Fri Jun 19 18:15:27 2015 Caltraba Mickael
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "server.h"

bool	my_error(const char *msg, err_type type)
{
  fprintf(stderr, "\r%s%s%s\n", text[RED], msg, text[NOCOLOR]);
  if (type == ERRNO)
    {
      fprintf(stderr, "%sHere is Errno output :\n", text[RED]);
      fprintf(stderr, "\t%s%s\n", strerror(errno), text[NOCOLOR]);
    }
  return (false);
}
