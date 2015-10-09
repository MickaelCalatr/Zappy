/*
** handler_connection.c for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/src
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Mon May 11 15:06:44 2015 Caltraba Mickael
** Last update Sun Jul  5 19:36:50 2015 paul david
*/

#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include "server.h"

bool		g_quit = true;
int		g_signal = 0;

void		shut_down(int signal)
{
  g_quit = false;
  g_signal = signal;
}

static void	set_timeout(struct timeval *tv, int sec, int usec)
{
  tv->tv_sec = sec;
  tv->tv_usec = usec;
}

static bool	init_select(fd_set *fd_read, fd_set *fd_write,
			    int *fd_max, t_server *server)
{
  int		i;

  i = 0;
  *fd_max = 0;
  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  while (i < server->client_max)
    {
      if (server->fd_type[i] != FD_FREE)
        {
	  if (server->user[i]->ret_r > 0)
	    FD_SET(i, fd_write);
	  FD_SET(i, fd_read);
          *fd_max = i;
	  if (server->user[i]->buff[0] != '\0')
	    if (find_cmd(server->user[i], server) == false)
	      {
		deco_client(server, server->user[i], server->user[i]->fd);
		return (false);
	      }
        }
      ++i;
    }
  return (true);
}

static bool	read_data_processing(fd_set *fd_read, fd_set *fd_write,
				     t_server *server)
{
  int		i;

  i = 0;
  while (i < server->client_max)
    {
      if (FD_ISSET(i, fd_read))
	{
	  if (server->exec[i] != NULL)
	    if (server->exec[i](i, server) == false)
	      {
		return (false);
	      }
	}
      if (FD_ISSET(i, fd_write))
	write_on_client(i, server);
      ++i;
    }
  if (server->client_log > 3)
    return (true);
  return (false);
}

bool			handler_connection(t_server *server)
{
  struct timeval	tv;
  fd_set		fd_read;
  fd_set		fd_write;
  int			fd_max;

  while (g_quit == true)
    {
      if (init_select(&fd_read, &fd_write, &fd_max, server) != false)
	{
	  set_timeout(&tv, 0, 10000);
	  if (select(fd_max + 1, &fd_read, &fd_write, NULL, &tv) == -1)
	    return (my_error("Error : can't perform select", ERRNO));
	  if (read_data_processing(&fd_read, &fd_write, server) == true)
	    find_food(server);
	}
    }
  return (true);
}
