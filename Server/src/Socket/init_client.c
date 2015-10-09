/*
** init_client.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Wed Jun 17 11:58:08 2015 Caltraba Mickael
** Last update Sun Jul  5 21:37:00 2015 paul david
*/

#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "server.h"

static bool		my_accept(int *fd_client, int fd_socket)
{
  struct sockaddr_in	sock_in;
  unsigned int		lenght;

  lenght = sizeof(sock_in);
  *fd_client = accept(fd_socket, (struct sockaddr *)&sock_in, &lenght);
  if (*fd_client == -1)
    return (false);
  return (true);
}

static int	find_player(t_server *server)
{
  int		i;

  i = -1;
  while (++i <= server->client_max)
    {
      if (server->id_users[i] == -1)
	{
	  server->id_users[i] = i + 1;
	  return (i + 1);
	}
    }
  return (-1);
}

static void	set_client(t_server *server, int i)
{
  int		pos[2];
  int		size[2];

  memset(server->user[i], 0, sizeof(t_client));
  pos[0] = rand() % server->args->x;
  pos[1] = rand() % server->args->y;
  size[0] = server->args->x;
  size[1] = server->args->y;
  server->user[i]->id = -1;
  server->user[i]->fd = i;
  server->user[i]->team = -1;
  server->user[i]->graphic = false;
  server->user[i]->ret = 0;
  server->user[i]->ret_r = 0;
  server->user[i]->action = false;
  server->exec[i] = NULL;
  server->fd_type[i] = FD_FREE;
  trantorien_init(&server->user[i]->trant, pos, size);
}

bool		add_client(int fd_socket, t_server *server)
{
  int		client_fd;

  if ((my_accept(&client_fd, fd_socket)) == false)
    return (false);
  if (server->client_log == server->client_max && (server->client_max += 1))
    if ((server->fd_type = realloc(server->fd_type, sizeof(fd_type)
				   * (server->client_max))) == NULL
	|| (server->exec = realloc(server->exec, sizeof(fptr)
				   * (server->client_max))) == NULL
	|| (server->user = realloc(server->user, sizeof(t_client)
				   * (server->client_max))) == NULL
	|| (server->id_users = realloc(server->id_users, sizeof(int)
				       * (server->client_max))) == NULL)
      return (false);
  if ((server->user[client_fd] = malloc(sizeof(t_client))) == NULL)
    return (false);
  set_client(server, client_fd);
  server->fd_type[client_fd] = FD_CLIENT;
  server->id_users[client_fd] = -1;
  server->exec[client_fd] = &read_on_client;
  server->user[client_fd]->id = find_player(server);
  printf("%s\nPlayer %d connected%s\n", text[GREEN],
	 server->user[client_fd]->id, text[NOCOLOR]);
  server->client_log += 1;
  return (reponse_to_client(client_fd, "BIENVENUE\n", server, 10));
}

bool		init_users(t_server *server)
{
  int		i;
  int		j;

  i = -1;
  while (++i < 4)
    {
      if ((server->user[i] = malloc(sizeof(t_client))) == NULL)
        {
          j = -1;
          while (++j < i)
	    {
	      free(server->user[j]);
	      trantorien_destroy(&server->user[j]->trant);
	    }
          free(server->user);
	  return (false);
        }
      server->client_log += 1;
      memset(server->user[i], 0, sizeof(t_client));
      set_client(server, i);
    }
  return (true);
}
