/*
** ressources.h for ressources in /home/david_k/PSU_2014_zappy/Ressources
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Jun 18 17:35:41 2015 paul david
** Last update Wed Jul  1 14:06:53 2015 paul david
*/

#ifndef RESSOURCES_H_
# define RESSOURCES_H_

typedef enum	r_type
  {
    nourriture = 0,
    linemate = 1,
    deraumere = 2,
    sibur = 3,
    mendiane = 4,
    phiras = 5,
    thystame = 6
  }		r_type;

typedef struct	s_cress
{
  r_type	type;
  char		*tochar;
}		t_cress;

typedef struct	s_ressources
{
  int		quantity;
  r_type	type;

  char		*(*getinventory)(struct s_ressources *);
  char		*(*getname)(struct s_ressources *);
}		t_ressources;

void	ressources_init(t_ressources *, int, r_type);
void	ressources_destroy(t_ressources *);

#endif /* RESSOURCES_H_ */
