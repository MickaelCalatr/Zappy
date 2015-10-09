/*
** start_server.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Mon May 11 14:39:38 2015 Caltraba Mickael
** Last update Sun Jul  5 14:03:42 2015 paul david
*/

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

static int	nb_team(char **team)
{
  int		i;

  i = 0;
  while (team[i] != NULL)
    ++i;
  return (i);
}

static bool	init_server_struct(t_server *server)
{
  srand(time(0));
  if ((server->team = malloc(sizeof(int) *
			     nb_team(server->args->names))) == NULL)
    return (false);
  if ((server->user = malloc(sizeof(t_client) * 4)) == NULL)
    return (false);
  if ((server->id_users = malloc(sizeof(int) * 4)) == NULL)
    return (false);
  if ((server->exec = malloc(sizeof(fptr) * 4)) == NULL)
    return (false);
  if ((server->fd_type = malloc(sizeof(fd_type) * 4)) == NULL)
    return (false);
  memset(server->team, 0, sizeof(int) * nb_team(server->args->names));
  memset(server->id_users, -1, sizeof(int) * 4);
  server->client_log = 0;
  server->client_max = 4;
  memset(&server->map, 0, sizeof(t_map));
  return (init_users(server));
}

bool		start_server(t_server *server)
{
  int		size[2];

  size[0] = server->args->x;
  size[1] = server->args->y;
  signal_handler();
  if (init_server_struct(server) == false)
    return (false);
  if (init_server(server) == false)
    return (false);
  init_map(&server->map, size);
  server->fd_type[server->socket] = FD_SERVER;
  server->exec[server->socket] = &add_client;
  spawn_res(&server->map);
  if (handler_connection(server) == false)
    return (false);
  return (true);
}
