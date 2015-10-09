/*
** getParsing.c for getParsing in /home/david_k/PSU_2014_zappy
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 18 16:01:04 2015 paul david
** Last update Sun Jul  5 13:37:27 2015 paul david
*/

#include "ZappyServer.h"

void		get_time(int *pos, char **av, t_args *arguments, int *count)
{
  static char	unique = 0;

  if (unique == 1)
    arg_error("Can't have a flag twice\n", arguments);
  (*pos)++;
  if ((*pos) >= arguments->arg_c)
    arg_error("Need a arguments after the flag\n", arguments);
  if (is_numeric(av[*pos]) == 0)
    arg_error("Time delay must contain only numeric caracter\n", arguments);
  if ((arguments->time = atoi(av[*pos])) <= 0)
    arg_error("Time delay must be superior to 0\n", arguments);
  (*count)++;
  unique = 1;
  (*pos)++;
}

void		get_nb(int *pos, char **av, t_args *arguments, int *count)
{
  static char	unique = 0;

  if (unique == 1)
    arg_error("Can't have a flag twice\n", arguments);
  (*pos)++;
  if ((*pos) >= arguments->arg_c)
    arg_error("Need a arguments after the flag\n", arguments);
  if (is_numeric(av[*pos]) == 0)
    arg_error("Client number must contain only numeric caracter\n", arguments);
  if ((arguments->clients = atoi(av[*pos])) <= 0)
    arg_error("Client number must be superior to 0\n", arguments);
  (*count)++;
  unique = 1;
  (*pos)++;
}

void		get_name(int *pos, char **av, t_args *arguments, int *count)
{
  int		i;
  static char	unique = 0;

  (void)count;
  if (unique == 1)
    arg_error("Can't have a flag twice\n", arguments);
  i = 0;
  if ((arguments->names = malloc(sizeof(char *) * 2)) == NULL)
      mal_arg_fail(arguments);
  while (++*pos < arguments->arg_c && av[*pos][0] != '-')
    {
	if (i != 0 && (arguments->names =
			 realloc(arguments->names,
				 sizeof(char *) * (i + 2))) == NULL)
	    mal_arg_fail(arguments);
      arguments->names[i] = av[*pos];
      i++;
    }
  arguments->names[i] = NULL;
  if (i < 2)
    arg_error("Server need at least two team's name\n", arguments);
  unique = 1;
}

void		get_y(int *pos, char **av, t_args *arguments, int *count)
{
  static char	unique = 0;

  if (unique == 1)
    arg_error("Can't have a flag twice\n", arguments);
  (*pos)++;
  if ((*pos) >= arguments->arg_c)
    arg_error("Need a arguments after the flag\n", arguments);
  if (is_numeric(av[*pos]) == 0)
    arg_error("Size of Y must contain only numeric caracter\n", arguments);
  if ((arguments->y = atoi(av[*pos])) < 10)
    arg_error("Size of Y must be superior to 10\n", arguments);
  (*count)++;
  unique = 1;
  (*pos)++;
}

void		get_x(int *pos, char **av, t_args *arguments, int *count)
{
  static char	unique = 0;

  if (unique == 1)
    arg_error("Can't have a flag twice\n", arguments);
  (*pos)++;
  if ((*pos) >= arguments->arg_c)
    arg_error("Need a arguments after the flag\n", arguments);
  if (is_numeric(av[*pos]) == 0)
    arg_error("Size of X must contain only numeric caracter\n", arguments);
  if ((arguments->x = atoi(av[*pos])) < 10)
    arg_error("Size of X must be superior to 10\n", arguments);
  (*count)++;
  unique = 1;
  (*pos)++;
}
