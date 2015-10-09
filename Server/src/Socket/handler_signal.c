/*
** handler_signal.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Mon May 11 14:42:13 2015 Caltraba Mickael
** Last update Sun Jul  5 13:22:44 2015 Caltraba Mickael
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"

static void	shutdown_users(t_server *server)
{
  int		i;

  i = -1;
  while (++i < 3)
    {
      if (server->user != NULL && server->user[i] != NULL)
	{
	  trantorien_destroy(&server->user[i]->trant);
	  free(server->user[i]);
	}
    }
  --i;
  while (++i < server->client_max)
    {
      if (server->user != NULL && server->user[i] != NULL)
	{
	  if (server->fd_type[i] != FD_FREE)
	    {
	      trantorien_destroy(&server->user[i]->trant);
	      free(server->user[i]);
	      if (close(server->fd_type[i]) == -1)
		my_error("Error : can't close", ERRNO);
	    }
	}
    }
}

static void	free_struct(t_server *server)
{
  if (server->args->names != NULL)
    free(server->args->names);
  if (server->args != NULL)
    free(server->args);
  if (server->team != NULL)
    free(server->team);
  destroy_map(&server->map);
}

void	shutdown_server(int signal_id, t_server *server)
{
  if (close(server->socket) == -1)
    my_error("Can't close server socket", ERRNO);
  free_struct(server);
  if (signal_id != EXIT_FAILURE && signal_id != EXIT_SUCCESS)
    fprintf(stderr, "\rServer received signal[%d]\n", signal_id);
  if (server == NULL)
    exit(EXIT_FAILURE);
  shutdown_users(server);
  if (server->user != NULL)
    free(server->user);
  if (server->id_users != NULL)
    free(server->id_users);
  if (server->exec != NULL)
    free(server->exec);
  if (server->fd_type != NULL)
    free(server->fd_type);
  if (signal_id != EXIT_SUCCESS)
    exit(EXIT_FAILURE);
  exit(EXIT_SUCCESS);
}

bool	signal_handler()
{
  if (signal(SIGINT, &shut_down) == SIG_ERR ||
      signal(SIGPIPE, &shut_down) == SIG_ERR)
    return (false);
  return (true);
}
