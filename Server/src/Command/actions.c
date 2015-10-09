/*
** actions.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Sun Jul  5 00:09:26 2015 Caltraba Mickael
** Last update Sun Jul  5 03:02:04 2015 Caltraba Mickael
*/

#include "server.h"

extern t_cress g_char_ress[];

void	inventory_graphic(t_server *server, t_client *client)
{
  char  rep[116];

  memset(rep, 0, 116);
  sprintf(rep, "pin #%d %d %d %d %d %d %d %d %d %d\n",
	  client->id, client->trant.xy[0], client->trant.xy[1],
	  client->trant.objects[0].quantity, client->trant.objects[1].quantity,
	  client->trant.objects[2].quantity, client->trant.objects[3].quantity,
	  client->trant.objects[4].quantity, client->trant.objects[5].quantity,
	  client->trant.objects[6].quantity);
  send_to_graphic(server, rep, 116);
}

void	drop_graphic(t_server *server, t_client *client, const char cmd[])
{
  char	rep[28];
  int	i;

  i = -1;
  while (g_char_ress[++i].tochar != NULL
	 && strcmp(g_char_ress[i].tochar, cmd) != 0);
  if (g_char_ress[++i].tochar != NULL)
    {
      memset(rep, 0, 28);
      sprintf(rep, "pdr #%d %d\n", client->id, i);
      send_to_graphic(server, rep, 50);
      inventory_graphic(server, client);
      send_case(server, client->trant.xy[0], client->trant.xy[1]);
    }
}

void	take_graphic(t_server *server, t_client *client, const char cmd[])
{
  char	rep[28];
  int	i;

  i = -1;
  while (g_char_ress[++i].tochar != NULL
	 && strcmp(g_char_ress[i].tochar, cmd) != 0);
  if (g_char_ress[++i].tochar != NULL)
    {
      memset(rep, 0, 28);
      sprintf(rep, "pgt #%d %d\n", client->id, i);
      send_to_graphic(server, rep, 50);
      inventory_graphic(server, client);
      send_case(server, client->trant.xy[0], client->trant.xy[1]);
    }
}

void			exp_graphic(t_server *server, t_client *client,
				    t_client *exp)
{
  static t_client	*old = NULL;
  char			rep[17];

  if (old == NULL || old != exp)
    {
      memset(rep, 0, 17);
      sprintf(rep, "pex #%d\n", exp->id);
      send_to_graphic(server, rep, 17);
      old = exp;
    }
  move(server, client);
}

bool		f_nb_connect(t_client *client, t_server *server)
{
  char		rep[10];

  memset(rep, 0, 10);
  client->ret_r += sprintf(rep, "%d\n",
			   server->args->clients - server->team[client->team]);
  concat_buff(client->buff_r, rep, strlen(rep));
  return (true);
}
