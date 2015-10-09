//
// main.cpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 15:14:32 2015 Caltraba Mickael
// Last update Sun Jul  5 15:54:31 2015 paul david
//

#include "IA.hpp"

char	*get_team(int ac, char **av)
{
  int	i = 1;
  while (i != ac)
    {
      if (std::string(av[i]) == "-n" && i + 1 < ac && av[i + 1][0] != '-')
	{
	  return(av[i + 1]);
	}
      i++;
    }
  throw std::invalid_argument("Client needs a team name");
  return (NULL);
}

std::string	get_host(int ac, char **av)
{
  int	i = 1;
  std::string	host("127.0.0.1");

  while (i != ac)
    {
      if (std::string(av[i]) == "-h" && i + 1 < ac && av[i + 1][0] != '-')
	{
	  host = av[i + 1];
	  return(host);
	}
      i++;
    }
  return (host);
}

int	get_port(int ac, char **av)
{
  int	i = 1;

  while (i != ac)
    {
      if (std::string(av[i]) == "-p" && i + 1 < ac && av[i + 1][0] != '-')
	{
	  std::stringstream ss;
	  int	port = 0;
	  
	  ss << av[i + 1];
	  ss >> port;
	  return (port);
	}
      i++;
    }
  throw std::invalid_argument("Client needs server's port");
  return 0;
}

int	main(int ac, char **av)
{
  try {
    if (ac < 4)
      throw std::invalid_argument("to few arguments.");
    IA				ia(get_team(ac, av));
    std::string::size_type	sz;

    signal(SIGINT, &my_handler);
    if (ia.initialize(get_host(ac, av), get_port(ac, av)))
      ia.run();
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
