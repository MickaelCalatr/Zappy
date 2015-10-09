/*
** cmd_graphic.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Tue Jun 23 15:32:41 2015 Caltraba Mickael
** Last update Sun Jul  5 00:56:48 2015 Caltraba Mickael
*/

#include "server.h"

extern bool	g_quit;

void		send_to_graphic(t_server *server, char *buff, int len)
{
  t_client      *client;
  int           i;

  i = 4;
  while (i != server->client_max)
    {
      client = server->user[i];
      if (client && client->id != -1 && client->graphic == true)
	reponse_to_client(client->fd, buff, server, len);
      ++i;
    }
}

static bool	send_team(t_server *server, t_client *client)
{
  char		*team;
  int		size;
  int		len;
  int		i;

  i = 0;
  while (server->args->names[i] != NULL)
    {
      size = 6 + strlen(server->args->names[i]);
      if ((team = calloc(sizeof(char), size)) == NULL)
	return (false);
      team = strcat(team, "tna ");
      team = strcat(team, server->args->names[i]);
      len = strlen(team);
      team[len] = '\n';
      team[len + 1] = '\0';
      reponse_to_client(client->fd, team, server, len);
      ++i;
      free(team);
    }
  return (true);
}

static void	send_time(t_server *server, t_client *client)
{
  char		time[16];

  memset(time, 0, 16);
  sprintf(time, "sgt %d\n", server->args->time);
  reponse_to_client(client->fd, time, server, 16);
}

bool		f_graphic(t_server *server, t_client *client)
{
  char		size[27];

  client->graphic = true;
  memset(size, 0, 27);
  trantorien_destroy(&client->trant);
  sprintf(size, "msz %d %d\n", server->args->x,
	  server->args->y);
  reponse_to_client(client->fd, size, server, 27);
  send_time(server, client);
  send_map(server);
  if (send_team(server, client) == false)
    g_quit = false;
  send_players(server);
  return (true);
}
