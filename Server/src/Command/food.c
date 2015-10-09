/*
** food.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Fri Jul  3 19:59:53 2015 Caltraba Mickael
** Last update Sun Jul  5 12:28:10 2015 Caltraba Mickael
*/

#include <sys/time.h>
#include "server.h"

void			find_food(t_server *server)
{
  struct timeval	timer;
  t_client		*client;
  int			i;
  int			lap;
  unsigned int		mult;

  i = 3;
  while (++i < server->client_max)
    {
      gettimeofday(&timer, NULL);
      client = server->user[i];
      if (client != NULL && client->team != -1 && client->graphic == false)
	{
	  mult = ((timer.tv_sec - client->food.tv_sec) * CONVERT)
	    + (timer.tv_usec - client->food.tv_usec);
	  if (mult > (((float)(126 * CONVERT) / server->args->time)))
	    {
	      lap = mult / ((126 * CONVERT) / server->args->time);
	      client->trant.objects[0].quantity -= (lap == 0) ? 1 : lap;
	      gettimeofday(&client->food, NULL);
	    }
	  if (client->trant.objects[0].quantity <= 0 && (i = 3))
	    deco_client(server, client, client->fd);
	}
    }
}
