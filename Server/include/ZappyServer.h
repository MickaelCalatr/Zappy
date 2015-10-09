/*
** ZappyServer.h for ZappyServer in /home/david_k/rendu/Zappy
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed May  6 15:30:06 2015 paul david
** Last update Sun Jul  5 13:41:20 2015 paul david
*/

#ifndef ZAPPYSERVER_H_
# define ZAPPYSERVER_H_

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct	s_args
{
  int	port;
  int	x;
  int	y;
  char	**names;
  int	clients;
  int	time;
  int	arg_c;
}		t_args;

typedef struct	s_parser
{
  char	*op;
  void	(*functions)(int *, char **, t_args *, int *);
}		t_parser;

int	is_numeric(char *str);
void	arg_error(char *str, t_args *arguments);
t_args	*pars_arg(int ac, char **av);
int	check_count(t_args *arguments);
void	get_port(int *pos, char **av, t_args *arguments, int * count);
void	get_x(int *pos, char **av, t_args *arguments, int * count);
void	get_y(int *pos, char **av, t_args *arguments, int * count);
void	get_name(int *pos, char **av, t_args *arguments, int * count);
void	get_nb(int *pos, char **av, t_args *arguments, int * count);
void	get_time(int *pos, char **av, t_args *arguments, int * count);
void	mal_arg_fail(t_args *);

#endif
