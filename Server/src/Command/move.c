/*
** move.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Fri Jun 26 16:36:43 2015 Caltraba Mickael
** Last update Sun Jul  5 01:46:02 2015 Caltraba Mickael
*/

#include <sys/time.h>
#include "server.h"

void		move(t_server *server, t_client *client)
{
  char		rep[50];

  sprintf(rep, "ppo #%d %d %d %d\n", client->id, client->trant.xy[0],
          client->trant.xy[1], client->trant.direction + 1);
  send_to_graphic(server, rep, 50);
}

bool			f_forward(t_client *client, t_server *server)
{
  struct timeval	now;
  char			rep[4];

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
      client->trant.forward(&client->trant);
      client->ret_r += sprintf(rep, "ok\n");
      concat_buff(client->buff_r, rep, 4);
      move(server, client);
      client->action = false;
      return (true);
    }
  return (-2);
}

bool		f_right(t_client *client, t_server *server)
{
  struct timeval	now;
  char			rep[4];

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
      client->trant.turn_right(&client->trant);
      client->ret_r += sprintf(rep, "ok\n");
      concat_buff(client->buff_r, rep, 4);
      move(server, client);
      client->action = false;
      return (true);
    }
  return (-2);
}

bool		f_left(t_client *client, t_server *server)
{
  struct timeval        now;
  char                  rep[4];

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
      client->trant.turn_left(&client->trant);
      client->ret_r += sprintf(rep, "ok\n");
      concat_buff(client->buff_r, rep, 4);
      move(server, client);
      client->action = false;
      return (true);
    }
  return (-2);
}
