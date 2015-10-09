/*
** message.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Sun Jul  5 02:02:04 2015 Caltraba Mickael
** Last update Sun Jul  5 13:00:21 2015 Caltraba Mickael
*/

#include "server.h"

extern bool	g_quit;

void		broad_graphic(t_server *server, t_client *client,
			      const char buff[])
{
  char		*rep;

  if ((rep = calloc(sizeof(char), (strlen(buff) + 18))) == NULL)
    g_quit = false;
  else
    {
      sprintf(rep, "pbc #%d %s", client->id, buff);
      send_to_graphic(server, rep, strlen(rep));
      free(rep);
    }
}

static char	*incat(t_server *server, t_client *client, char *rp)
{
  int		i;
  int		nb;
  char		tmp[13];

  i = 3;
  nb = 53;
  while (++i != server->client_max)
    if (server->user[i] != NULL && server->user[i]->graphic == false
	&& (server->user[i]->trant.xy[0] == client->trant.xy[0]
	    && server->user[i]->trant.xy[1] == client->trant.xy[1])
	&& server->user[i]->trant.vision == client->trant.vision)
      {
	nb += 13;
	memset(tmp, 0, 13);
	g_quit = ((rp = realloc(rp, sizeof(char) * nb)) == NULL)
	  ? false : true;
	sprintf(tmp, " #%d", server->user[i]->id);
	strcat(rp, tmp);
      }
  strcat(rp, "\n");
  return (rp);
}

void		incant_graphic(t_server *server, t_client *client)
{
  char		*rp;

  if ((rp = calloc(sizeof(char), 53)) == NULL)
    g_quit = false;
  sprintf(rp, "pic %d %d %d #%d", client->trant.xy[0],
	  client->trant.xy[1], client->trant.vision, client->id);
  rp = incat(server, client, rp);
  send_to_graphic(server, rp, strlen(rp));
  free(rp);
}

void		end_incant(t_server *server, t_client *client, int yes)
{
  char		rep[38];

  memset(rep, 0, 38);
  sprintf(rep, "pie %d %d %d\n", client->trant.xy[0], client->trant.xy[1],
	  yes);
  send_to_graphic(server, rep, 38);
  memset(rep, 0, 38);
  sprintf(rep, "plv #%d %d\n", client->id, client->trant.vision);
  send_to_graphic(server, rep, 38);
  send_case(server, client->trant.xy[0], client->trant.xy[1]);
}
