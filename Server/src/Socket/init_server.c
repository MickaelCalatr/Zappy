/*
** init_server.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Mon May 11 14:58:51 2015 Caltraba Mickael
** Last update Fri Jul  3 09:24:24 2015 Caltraba Mickael
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <netdb.h>
#include "server.h"

static bool		init_listen(t_server *server)
{
  if (listen(server->socket, 42) == -1)
    return (my_error("Error : can't listen", ERRNO));
  return (true);
}

static bool		init_bind(t_server *server)
{
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(server->args->port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(server->socket,
           (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    return (my_error("Error : can't bind", ERRNO));
  return (true);
}

static bool		init_socket(t_server *server)
{
  struct protoent	*sock;
  int			yes;

  yes = 1;
  printf("Listening on port : %d\n", server->args->port);
  if (server->args->port <= 0 || server->args->port > USHRT_MAX)
    return (my_error("Error : Invalid port number", NOERRNO));
  sock = getprotobyname("TCP");
  if (sock == NULL)
    return (my_error("Error : getprotobyname failed", ERRNO));
  server->socket = socket(AF_INET, SOCK_STREAM, sock->p_proto);
  if (server->socket == -1)
    return (my_error("Can't create socket", ERRNO));
  if (setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR,
		 &yes, sizeof(int)) == -1)
    return (my_error("SetsockOpt", ERRNO));
  return (true);
}

bool			init_server(t_server *server)
{
  server->socket = 0;
  if (init_socket(server) == false)
    return (false);
  if (init_bind(server) == false)
    return (false);
  if (init_listen(server) == false)
    return (false);
  server->fd_type[server->socket] = FD_SERVER;
  server->exec[server->socket] = &add_client;
  return (true);
}
