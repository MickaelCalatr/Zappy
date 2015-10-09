/*
** write_client.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Mon May 11 15:44:33 2015 Caltraba Mickael
** Last update Sun Jul  5 12:56:26 2015 Caltraba Mickael
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

extern bool g_quit;

static int	nb_cmd(t_client *client)
{
  int		nb;
  int		i;

  i = -1;
  nb = 0;
  while (client->buff[++i] != '\0')
    {
      if (client->buff[++i] == '\n')
	++nb;
    }
  return (nb);
}

bool	deco_client(t_server *server, t_client *client, int client_fd)
{
  char	rep[17];
  int	i;

  i = -1;
  memset(rep, 0, 17);
  if (client->graphic == false && client->team != -1
      && client->trant.objects[0].quantity <= 0)
    reponse_to_client(client_fd, "mort\n", server, 6);
  sprintf(rep, "pdi #%d\n", client->id);
  send_to_graphic(server, rep, 17);
  printf("%sPlayer %d disconnected%s\n", text[GREEN], client->id,
	 text[NOCOLOR]);
  while (server->id_users[++i] != client->id);
  server->id_users[i] = -1;
  server->fd_type[client_fd] = FD_FREE;
  server->exec[client_fd] = NULL;
  if (client->team != -1)
    server->team[client->team] -= 1;
  server->client_log -= 1;
  (close(client_fd) == -1) ? my_error("Can't close server socket", ERRNO) : 0;
  (client->graphic == false) ? trantorien_destroy(&client->trant) : 0;
  free(server->user[client_fd]);
  server->user[client_fd] = NULL;
  return (false);
}

bool		write_on_client(int client_fd, t_server *server)
{
  t_client	*client;
  char		buff[SIZE];
  int		i;

  client = server->user[client_fd];
  while ((i = find_separator(client->buff_r, client->ret_r)) != false)
    {
      memset(buff, 0, SIZE);
      memmove(buff, client->buff_r, i);
      if (dprintf(client_fd, "%s\n", buff) <= 0)
	{
	  fprintf(stderr, "%sError : can't write on client %d%s\n",
		  text[RED], client->id, text[NOCOLOR]);
	  return (false);
	}
      printf("%s\t#Sending message [%s] to player %d%s\n", text[BLUE],
      	     buff, client->id, text[NOCOLOR]);
      memset(client->buff_r, 0, i);
      client->ret_r -= ++i;
      memmove(client->buff_r, &client->buff_r[i], client->ret_r);
      memset(&client->buff_r[client->ret_r], 0, SIZE - client->ret_r);
    }
  memset(client->buff_r, 0, SIZE);
  return (true);
}

bool		read_on_client(int client_fd, t_server *server)
{
  t_client	*client;
  char		buff[SIZE];
  int		ret;

  client = server->user[client_fd];
  if (nb_cmd(client) < 10)
    {
      memset(buff, 0, SIZE);
      if ((ret = read(client_fd, buff, SIZE - client->ret)) <= 0)
	return (deco_client(server, client, client_fd));
      buff[ret] = '\0';
      strcat(client->buff, buff);
      buff[ret - 1] = '\0';
      client->ret += ret;
      printf("%s\t#Receive message [%s] to player %d%s\n", text[CYAN], buff,
	     client->id, text[NOCOLOR]);
    }
  return (true);
}
