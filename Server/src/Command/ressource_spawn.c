/*
** ressource_spawn.c for ressource_spawn in /home/david_k/rendu/PSU_2014_zappy/Server/src/Command
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Jul  5 04:46:31 2015 paul david
** Last update Sun Jul  5 14:13:59 2015 paul david
*/

#include "server.h"
#include "Trantorien.h"

void spawn_ld(t_map *map)
{
  int	i;
  int	x;
  int	y;

  i = 15 * (map->limit[0] / 10);
  while (--i != -1)
    {
      x = rand() % map->limit[0];
      y = rand() % map->limit[1];
      MAP(x, y).objects[1].quantity++;
    }
  i = 12 * (map->limit[0] / 10);
  while (--i != -1)
    {
      x = rand() % map->limit[0];
      y = rand() % map->limit[1];
      MAP(x, y).objects[2].quantity++;
    }
}

void spawn_sm(t_map *map)
{
  int	i;
  int	x;
  int	y;

  i = 10 * (map->limit[0] / 10);
  while (--i != -1)
    {
      x = rand() % map->limit[0];
      y = rand() % map->limit[1];
      MAP(x, y).objects[3].quantity++;
    }
  i = 6 * (map->limit[0] / 10);
  while (--i != -1)
    {
      x = rand() % map->limit[0];
      y = rand() % map->limit[1];
      MAP(x, y).objects[4].quantity++;
    }
}

void spawn_pt(t_map *map)
{
  int	i;
  int	x;
  int	y;

  i = 3 * (map->limit[0] / 10);
  while (--i != -1)
    {
      x = rand() % map->limit[0];
      y = rand() % map->limit[1];
      MAP(x, y).objects[5].quantity++;
    }
  i = 1 * (map->limit[0] / 10);
  while (--i != -1)
    {
      x = rand() % map->limit[0];
      y = rand() % map->limit[1];
      MAP(x, y).objects[6].quantity++;
    }
}

void	spawn_food(t_map *map)
{
  int	i;
  int	x;
  int	y;

  i = 35;
  while (--i != -1)
    {
      x = rand() % map->limit[0];
      y = rand() % map->limit[1];
      MAP(x, y).objects[0].quantity++;
    }
}

void	spawn_res(t_map *map)
{
  spawn_ld(map);
  spawn_sm(map);
  spawn_pt(map);
}
