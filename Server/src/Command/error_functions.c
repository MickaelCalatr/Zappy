/*
** error_functions.c for error_functions in /home/david_k/rendu/Zappy
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed May 13 16:58:23 2015 paul david
** Last update Sun Jul  5 03:57:43 2015 paul david
*/

#include "ZappyServer.h"

void	arg_error(char *str, t_args *arguments)
{
  write(2, str, strlen(str));
  if (arguments->names != NULL)
    free(arguments->names);
  free(arguments);
  exit(EXIT_FAILURE);
}

void	mal_arg_fail(t_args *arguments)
{
  free(arguments);
  exit(EXIT_FAILURE);
}
