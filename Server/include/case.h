/*
** case.h for case in /home/david_k/rendu/PSU_2014_zappy/Server/include
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 22 13:38:38 2015 paul david
** Last update Wed Jul  1 14:02:24 2015 paul david
*/

#ifndef CASE_H_
#define CASE_H_

#include "ressources.h"
#include "String.h"

struct	s_client;

typedef struct	s_case
{
  int		xy[2];
  t_ressources	objects[7];
  int		(*is_empty)(struct s_case *);
  char		*(*ressources_list)(struct s_case *, struct s_client **, int);
  char		*(*player_list)(struct s_case *, struct s_client **, int);
  int		(*take_ressources)(struct s_case *, char *);
  int		(*add_ressources)(struct s_case *, char *);
}		t_case;

void	case_init(t_case *, int, int);
void	case_primary(t_case *);
void	case_destroy(t_case *);
extern	t_cress	g_char_ress[];

#endif /* CASE_H_ */
