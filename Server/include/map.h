/*
** map.h for map in /home/david_k/rendu/PSU_2014_zappy/Server/include
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 22 15:19:50 2015 paul david
** Last update Fri Jun 26 16:01:16 2015 paul david
*/

#ifndef MAP_H_
# define MAP_H_

#include "case.h"

typedef struct	s_map
{
  t_case	**map;
  int		limit[2];
}		t_map;

void	init_map(t_map *, int *);
void	destroy_map(t_map *);

#endif /* MAP_H_ */
