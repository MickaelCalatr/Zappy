/*
** find_cmd.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src/Network
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Sat Jun 20 01:09:16 2015 Caltraba Mickael
** Last update Sun Jul  5 21:34:00 2015 paul david
*/

#include <string.h>
#include "server.h"

static t_cmd	commands[12] = {
  {"avance", &f_forward},
  {"droite", &f_right},
  {"gauche", &f_left},
  {"voir", &f_view},
  {"inventaire", &f_inventory},
  {"prend", &f_take},
  {"pose", &f_drop},
  {"expulse", &f_exp},
  {"broadcast", &f_broad},
  {"incantation", &f_incant},
  {"connect_nbr", &f_nb_connect},
  {NULL, NULL}
};

bool		find_separator(char buff[], int size)
{
  int		i;

  i = 0;
  while (i != size)
    {
      if (strncmp(&buff[i], "\n", 1) == 0)
	return (i);
      ++i;
    }
  return (false);
}

static bool	find_name_teams(const char cmd[], t_server *server,
				t_client *client)
{
  int		i;
  char		rep[4];

  i = -1;
  memset(rep, 0 , 4);
  while (server->args->names[++i] && strcmp(server->args->names[i], cmd) != 0);
  if (server->args->names[i] && server->team[i] < server->args->clients)
    {
      client->team = i;
      ++server->team[i];
      spawn_food(&server->map);
      send_map(server);
      return (f_connect(server, client));
    }
  else if (!server->args->names[i])
    fprintf(stderr,  "%sPlayer %d : Team not found.%s\n", text[YELLOW],
	    client->id, text[NOCOLOR]);
  else if (server->args->names[i] && server->team[i] >= server->args->clients)
    fprintf(stderr, "%sError : Sorry ! Team is full.%s\n", text[YELLOW],
	    text[NOCOLOR]);
  reponse_to_client(client->fd, "ko\n", server, 4);
  return (false);
}

static bool	parse_cmd(const char cmd[], t_client *client, t_server *server)
{
  int		i;
  char		rep[4];

  i = 0;
  if (strcmp(cmd, "GRAPHIC") == 0)
    return (f_graphic(server, client));
  else if (client->team == -1)
    return (find_name_teams(cmd, server, client));
  while (commands[i].cmd)
    {
      if (strncmp(commands[i].cmd, cmd, strlen(commands[i].cmd)) == 0)
	return ((commands[i].func)(client, server));
      ++i;
    }
  fprintf(stderr,  "%sPlayer %d : Command not found.%s\n", text[YELLOW],
	  client->id, text[NOCOLOR]);
  client->ret_r += sprintf(rep, "ko\n");
  concat_buff(client->buff_r, rep, 4);
  return (true);
}

bool	find_cmd(t_client *client, t_server *server)
{
  int   i;
  int	ret;
  char  cmd[SIZE];

  while ((i = find_separator(client->buff, client->ret)) != false)
    {
      memset(cmd, 0, SIZE);
      memmove(cmd, client->buff, i);
      if ((ret = parse_cmd(cmd, client, server)) <= false)
	{
	  if (ret == false)
	    {
	      return (false);
	    }
	  return (true);
	}
      memset(client->buff, 0, i);
      client->ret -= ++i;
      memmove(client->buff, client->buff + i, client->ret);
      memset(&client->buff[client->ret], 0, SIZE - client->ret);
    }
  return (true);
}
