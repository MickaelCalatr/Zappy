//
// main.cpp for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Mon Jun 22 15:14:32 2015 Caltraba Mickael
// Last update Fri Jul  3 17:13:15 2015 Caltraba Mickael
//

#include "Client.hpp"
#include "ZappyUI.hpp"

int	main(int ac, char **av)
{
  try {
    if (ac != 3)
      throw std::invalid_argument("to few arguments.");
    Client			client;
    std::string::size_type	sz;

    if (client.initialize(av[1], std::stoi(av[2], &sz)))
      client.run();
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
