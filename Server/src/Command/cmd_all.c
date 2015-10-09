/*
** cmd_all.c for  in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Sat Jul  4 23:03:49 2015 Caltraba Mickael
** Last update Sun Jul  5 13:33:18 2015 paul david
*/

#include <sys/time.h>
#include "server.h"

static char		*expulse(t_client *client, t_server *server)
{
  int                   i;
  int                   k;
  char                  rep[16];

  i = 3;
  k = 0;
  while (++i < server->client_max)
    if (server->user[i] != NULL && client != server->user[i]
	&& client->graphic == false
	&& (client->trant.xy[0] == server->user[i]->trant.xy[0]
	    && client->trant.xy[1] == server->user[i]->trant.xy[1]))
      {
	k++;
	server->user[i]->ret_r +=
	  sprintf(rep, "deplacement: %d\n",
		  server->user[i]->trant.expulse(&server->user[i]->trant,
						 client->trant.xy,
						 client->trant.direction));
	concat_buff(server->user[i]->buff_r, rep, strlen(rep));
	exp_graphic(server, server->user[i], client);
      }
  client->action = false;
  return ((k > 0) ? "ok\n" : "ko\n");
}

bool                    f_exp(t_client *client, t_server *server)
{
  struct timeval        now;
  char			*rep;

  if (gettimeofday(&now, NULL) != -1 && client->action == false)
    {
      client->action = true;
      gettimeofday(&client->time, NULL);
    }
  else if (client->action == true && COMP(7) == 1)
    {
      rep = expulse(client, server);
      client->ret_r += strlen(rep);
      concat_buff(client->buff_r, rep, strlen(rep));
      return (true);
    }
  return (-2);
}

static void		broad(t_client *client, t_server *server)
{
  int   i;
  char  cmd[SIZE];
  char  rep[SIZE];

  i = find_separator(client->buff, client->ret);
  memset(cmd, 0, SIZE);
  memcpy(cmd, client->buff + 10, i);
  client->ret_r += sprintf(rep, "ok\n");
  concat_buff(client->buff_r, rep, strlen(rep));
  broad_graphic(server, client, cmd);
  i = -1;
  while (++i != server->client_max)
    if (server->user[i] != NULL && server->user[i]->team != -1 &&
        client != server->user[i] && client->graphic == false)
      {
        server->user[i]->ret_r +=
          sprintf(rep, "message %d,%s",
                  server->user[i]->trant.broadcast(&server->user[i]->trant,
                                                   client->trant.xy), cmd);
        concat_buff(server->user[i]->buff_r, rep, strlen(rep));
      }
}

bool			incant(t_client *client, t_server *server)
{
  char			rep[22];
  int			i;

  i = 3;
  if (memset(rep, 0, 22) != NULL && client->trant.incantation
      (&client->trant, server->user, server->client_max, &server->map) == 0)
    {
      client->ret_r += sprintf(rep, "ko\n");
      concat_buff(client->buff_r, rep, strlen(rep));
      end_incant(server, client, 0);
      return (true);
    }
  while (++i != server->client_max)
    if (server->user[i] != NULL && server->user[i]->graphic == false
	&& (STRANT(i).xy[0] == CTRANT.xy[0] && STRANT(i).xy[1] == CTRANT.xy[1])
	&& STRANT(i).vision == CTRANT.vision && (client->action = false))
      {
	client->trant.vision++;
	client->ret_r += sprintf(rep, "niveau actuel : %d\n",
				 client->trant.vision);
	concat_buff(client->buff_r, rep, strlen(rep));
	end_incant(server, server->user[i], 1);
      }
  client->trant.empty_lvl(&client->trant, &server->map);
  return (true);
}

bool			f_broad(t_client *client, t_server *server)
{
  struct timeval	now;

  if (gettimeofday(&now, NULL) != -1 && client->action == false)
    {
      client->action = true;
      gettimeofday(&client->time, NULL);
    }
  else if (client->action == true && COMP(7) == 1)
    {
      broad(client, server);
      client->action = false;
      return (true);
    }
  return (-2);
}
