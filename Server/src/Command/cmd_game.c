/*
** cmd_game.c for zapyy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Tue Jun 30 18:19:56 2015 Caltraba Mickael
** Last update Sun Jul  5 03:42:54 2015 Caltraba Mickael
*/

#include "server.h"

extern bool	g_quit;

void		send_player(t_server *server, t_client *client)
{
  char		*buff;
  char		play[62];
  char		*name;
  int		len;

  if (client->team != -1)
    {
      name = strdup(server->args->names[client->team]);
      memset(play, 0, 62);
      sprintf(play, "pnw #%d %d %d %d %d ", client->id, client->trant.xy[0],
	      client->trant.xy[1], client->trant.direction + 1,
	      client->trant.vision);
      if ((buff = calloc(sizeof(char), (strlen(play) + strlen(name)
					+ 2))) != NULL)
	{
	  strcat(buff, play);
	  strcat(buff, name);
	  len = strlen(buff);
	  buff[len] = '\n';
	  buff[len + 1] = '\0';
	  send_to_graphic(server, buff, len);
	  free(name);
	  free(buff);
	}
    }
}

void		send_players(t_server *server)
{
  t_client	*client;
  int		i;

  i = 4;
  while (i != server->client_max)
    {
      client = server->user[i];
      if (client && client->id != -1 && client->graphic == false)
	send_player(server, client);
      ++i;
    }
}

void	send_case(t_server *server, int i, int j)
{
  char	cases[104];

  memset(cases, 0, 104);
  sprintf(cases, "bct %d %d %d %d %d %d %d %d %d\n",
	  i, j,
	  server->map.map[j][i].objects[0].quantity,
	  server->map.map[j][i].objects[1].quantity,
	  server->map.map[j][i].objects[2].quantity,
	  server->map.map[j][i].objects[3].quantity,
	  server->map.map[j][i].objects[4].quantity,
	  server->map.map[j][i].objects[5].quantity,
	  server->map.map[j][i].objects[6].quantity);
  send_to_graphic(server, cases, 104);
}

void	send_map(t_server *server)
{
  int	i;
  int	j;

  j = -1;
  while (++j < server->args->y)
    {
      i = 0;
      while (i < server->args->x)
	{
	  send_case(server, i, j);
	  ++i;
	}
    }
}

void	send_egg(t_server *server, t_client *client)
{
  (void)server;
  (void)client;
}
