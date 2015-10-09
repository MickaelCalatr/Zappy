/*
** ParsingFunctions_bis.c for ParsingFunctions in /home/david_k/PSU_2014_zappy
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 18 16:07:16 2015 paul david
** Last update Sun Jul  5 13:39:56 2015 Caltraba Mickael
*/

#include "ZappyServer.h"

t_parser	g_pars[] =
  {
    {"-p", &get_port},
    {"-x", &get_x},
    {"-y", &get_y},
    {"-n", &get_name},
    {"-c", &get_nb},
    {"-t", &get_time}
  };

void		init_arg(t_args	*arguments, int ac)
{
  arguments->arg_c = ac;
  arguments->names = NULL;
  arguments->x = 20;
  arguments->y = 20;
  arguments->clients = 1;
  arguments->time = 100;
  arguments->port = 4242;
}

void		get_port(int *pos, char **av, t_args *arguments, int *count)
{
  static char	unique = 0;

  if (unique == 1)
    arg_error("Can't have a flag twice\n", arguments);
  (*pos)++;
  if ((*pos) >= arguments->arg_c)
    arg_error("Need an arguments after the flags\n", arguments);
  if (is_numeric(av[*pos]) == 0)
    arg_error("Port must contain only numeric caracter\n", arguments);
  arguments->port = atoi(av[*pos]);
  (*count)++;
  unique = 1;
  (*pos)++;
}

int	check_count(t_args *arguments)
{
  if (arguments->names == NULL)
    {
      return (0);
    }
  return (1);
}

t_args		*pars_arg(int ac, char **av)
{
  int		pos;
  int		i;
  char		equal;
  int		count;
  t_args	*arguments;

  pos = 1;
  i = -1;
  equal = 0;
  count = 0;
  if ((arguments = malloc(sizeof(t_args))) == NULL)
    mal_arg_fail(arguments);
  init_arg(arguments, ac);
  while (pos < ac)
    {
      while (g_pars[++i].op != NULL && equal == 0)
        if (strcmp(g_pars[i].op, av[pos]) == 0)
          {
            g_pars[i].functions(&pos, av, arguments, &count);
            equal = 1;
          }
      i = -1;
      equal = 0;
    }
  return ((check_count(arguments) == 1) ? arguments : NULL);
}
