/*
** Trantorien.h for Trantorien in /home/david_k/rendu/Zappy/Trantorien
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Jun 15 16:59:31 2015 paul david
** Last update Sun Jul  5 04:19:18 2015 paul david
*/

#ifndef TRANTORIEN_H_
# define TRANTORIEN_H_

#include "map.h"

typedef enum	Direction
  {
    North = 0,
    South = 2,
    West = 3,
    East = 1
  }		Direction;

struct	s_move;
struct	s_client;

typedef struct	s_lvl_up
{
  t_ressources	objects[7];
  int		lvl;
  int		nb;
}		t_lvl_up;

typedef struct		s_trantorien
{
  int			xy_limit[2];
  int			xy[2];
  t_ressources		objects[7];
  int			vision;
  Direction		direction;
  struct s_move		*move;
  t_lvl_up		*incant;
  void			(*forward)(struct s_trantorien *);
  void			(*turn_right)(struct s_trantorien *);
  void			(*turn_left)(struct s_trantorien *);
  char			*(*see)(struct s_trantorien *, t_map *,
				struct  s_client **, int nb);
  char			*(*inventory)(struct s_trantorien *);
  int			(*take)(struct s_trantorien *, t_map *, char *);
  int			(*drop)(struct s_trantorien *, t_map *, char *);
  int			(*incantation)(struct s_trantorien *,
				       struct s_client **user,
				       int nb, t_map *);
  int			(*expulse)(struct s_trantorien *, int *pos,
				   Direction direction);
  int			(*broadcast)(struct s_trantorien *this, int *pos);
  void			(*empty_lvl)(struct s_trantorien *this, t_map *);
}			t_trantorien;

typedef struct	s_move
{
  Direction	direction;
  void		(*move)(t_trantorien *);
  char		*(*d_see)(t_trantorien *, t_map *, struct s_client **, int nb);
  int		(*expulse)(t_trantorien *, int *, Direction direction);
  int		(*broad)(t_trantorien	*, int *);
}		t_move;

void	trantorien_init(t_trantorien *, int *, int *);
void	init_broad(t_trantorien *);
void	init_expulse(t_trantorien *);
void	init_move(t_trantorien *);
void	init_see(t_trantorien *);
void	init_movement(t_trantorien *);
void	init_primary(t_trantorien *);
void	init_incant(t_trantorien *);
void	init_all(t_trantorien *);
void	trantorien_destroy(t_trantorien *);

extern  t_cress	g_char_ress[];

# define MAP(x, y)	map->map[y][x]
# define X		this->xy[0]
# define Y		this->xy[1]

#endif /* TRANTORIEN_H_ */
