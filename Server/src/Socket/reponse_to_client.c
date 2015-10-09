/*
** reponse_to_client.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Thu Jun 18 19:00:15 2015 Caltraba Mickael
** Last update Sat Jul  4 17:39:29 2015 Caltraba Mickael
*/

#include "server.h"

char	text[7][6] = {
  {"\033[32m"},
  {"\033[31m"},
  {"\033[34m"},
  {"\033[33m"},
  {"\033[0m\0"},
  {"\033[35m"},
  {"\033[36m"}
};

bool		reponse_to_client(int client_fd, char *msg, t_server *server,
				  int len)
{
  char		*tmp;

  tmp = strdup(msg);
  if (dprintf(client_fd, "%s", msg) <= 0)
    {
      printf("%sError : can't send message on player %d%s\n", text[RED],
	     server->user[client_fd]->id, text[NOCOLOR]);
      return (false);
    }
  (void)len;
  tmp[strlen(tmp) - 1] = '\0';
  printf("%s\t#Sending message [%s] to player %d%s\n", text[BLUE],
	 tmp, server->user[client_fd]->id , text[NOCOLOR]);
  free(tmp);
  return (true);
}
