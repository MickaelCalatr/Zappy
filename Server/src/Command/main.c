/*
** main.c for main in /home/david_k/rendu/Zappy
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed May  6 15:00:11 2015 paul david
** Last update Sat Jul  4 14:37:41 2015 paul david
*/

#include "ZappyServer.h"
#include "server.h"

extern bool	g_signal;

void	usage()
{
  write(2, "Usage : -p port -x widht -y hight", 33);
  write(2, " -n team's names -c AI nb -t time\n", 34);
}

int		main(int ac, char **av)
{
  t_args	*arguments;
  t_server	server;

  if (ac < 3)
    {
      usage();
      return (-1);
    }
  if ((arguments = pars_arg(ac, av)) == NULL)
    {
      write(2, "Need at least team's names\n", 27);
      return (EXIT_FAILURE);
    }
  server.args = arguments;
  if (start_server(&server) == false)
    shutdown_server((g_signal == 0) ? EXIT_FAILURE : g_signal, &server);
  else
    shutdown_server(EXIT_SUCCESS, &server);
  return (EXIT_SUCCESS);
}
