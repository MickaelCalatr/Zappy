/*
** cmd_env.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Tue Jun 30 16:44:38 2015 Caltraba Mickael
** Last update Sun Jul  5 19:21:01 2015 paul david
*/

#include <sys/time.h>
#include "server.h"

bool			f_view(t_client *client, t_server *server)
{
  struct timeval	now;
  char			*line;

  gettimeofday(&now, NULL);
  if (client->action == false)
    {
      client->action = true;
      gettimeofday(&client->time, NULL);
      return (-2);
    }
  else if (client->action == true
           && ((now.tv_sec - client->time.tv_sec) * CONVERT)
           + (now.tv_usec - client->time.tv_usec)
           > (float)((7 * CONVERT) / server->args->time))
    {
      line = client->trant.see(&client->trant, &server->map, server->user,
			       server->client_max);
      client->ret_r += strlen(line);
      concat_buff(client->buff_r, line, strlen(line));
      free(line);
      client->action = false;
      return (true);
    }
  return (-2);
}

bool			f_inventory(t_client *client, t_server *server)
{
  struct timeval	now;
  char			*line;

  gettimeofday(&now, NULL);
  if (client->action == false)
    {
      client->action = true;
      gettimeofday(&client->time, NULL);
    }
  else if (client->action == true
           && ((now.tv_sec - client->time.tv_sec) * CONVERT)
           + (now.tv_usec - client->time.tv_usec)
           > (float)((1 * CONVERT) / server->args->time))
    {
      (void)server;
      line = client->trant.inventory(&client->trant);
      client->ret_r += strlen(line);
      concat_buff(client->buff_r, line, strlen(line));
      free(line);
      client->action = false;
      inventory_graphic(server, client);
      return (true);
    }
  return (-2);
}

bool			f_take(t_client *client, t_server *server)
{
  int			i;
  char			cmd[SIZE];
  char			rep[12];
  struct timeval	now;

  if (gettimeofday(&now, NULL) != -1 && client->action == false
      && gettimeofday(&client->time, NULL) != -1)
    client->action = true;
  else if (client->action == true && COMP(7) == 1)
    {
      i = find_separator(client->buff, client->ret);
      memset(cmd, 0, SIZE);
      memcpy(cmd, client->buff + 6, i - 6);
      (client->trant.take(&client->trant, &server->map, cmd) == 1) ?
	(client->ret_r += sprintf(rep, "ok\n")),
	concat_buff(client->buff_r, rep, strlen(rep)) :
	(client->ret_r += sprintf(rep, "ko\n")),
	concat_buff(client->buff_r, rep, strlen(rep));
      client->action = false;
      take_graphic(server, client, cmd);
      return (true);
    }
  return (-2);
}

bool			f_drop(t_client *client, t_server *server)
{
  int			i;
  char			cmd[SIZE];
  char			rep[12];
  struct timeval	now;

  if (gettimeofday(&now, NULL) != -1 && client->action == false
      && gettimeofday(&client->time, NULL) != -1)
    client->action = true;
  else if (client->action == true && COMP(7) == 1)
    {
      i = find_separator(client->buff, client->ret);
      memset(cmd, 0, SIZE);
      if (i > 5)
	memcpy(cmd, client->buff + 5, i - 5);
      (client->trant.drop(&client->trant, &server->map, cmd) == 1) ?
	(client->ret_r += sprintf(rep, "ok\n")),
	concat_buff(client->buff_r, rep, strlen(rep)),
	drop_graphic(server, client, cmd) :
	(client->ret_r += sprintf(rep, "ko\n")),
	concat_buff(client->buff_r, rep, strlen(rep));
      client->action = false;
      return (true);
    }
  return (-2);
}

bool			f_incant(t_client *client, t_server *server)
{
  struct timeval	now;
  char			rep[22];

  memset(rep, 0, 22);
  if (gettimeofday(&now, NULL) != -1 && client->action == false)
    {
      if (client->trant.incantation(&client->trant, server->user,
				    server->client_max, &server->map) == 0)
	{
	  client->ret_r += sprintf(rep, "ko\n");
	  concat_buff(client->buff_r, rep, strlen(rep));
	  return (true);
	}
      client->ret_r += sprintf(rep, "incantation en cours\n");
      concat_buff(client->buff_r, rep, strlen(rep));
      incant_graphic(server, client);
      client->action = true;
      gettimeofday(&client->time, NULL);
    }
  else if (client->action == true && COMP(300) == 1)
    return (incant(client, server));
  return (-2);
}
