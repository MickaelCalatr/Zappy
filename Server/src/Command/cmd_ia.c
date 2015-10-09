/*
** cmd_ia.c for  in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Wed Jul  1 17:42:43 2015 Caltraba Mickael
** Last update Sun Jul  5 01:17:37 2015 Caltraba Mickael
*/

#include <sys/time.h>
#include "server.h"

bool	f_connect(t_server *server, t_client *client)
{
  char	size[60];

  client->ret_r += sprintf(size, "%d\n%d %d\n",
			   (server->args->clients -
			    server->team[client->team]),
			   server->args->x, server->args->y);
  concat_buff(client->buff_r, size, strlen(size));
  gettimeofday(&client->food, NULL);
  send_player(server, client);
  return (true);
}
