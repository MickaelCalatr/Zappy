/*
** String.h for String in /home/david_k/cpp_rendu/piscine_cpp_d03/ex00
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Fri Jan  9 09:12:51 2015 paul david
** Last update Tue Jun 30 18:33:00 2015 paul david
*/

#ifndef STRING_H_
# define STRING_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_string
{
  char		*str;
  void		(*assign_s)(struct s_string *, struct s_string const *);
  void		(*assign_c)(struct s_string *, char const *);
  void		(*append_s)(struct s_string *, struct s_string const *);
  void		(*append_c)(struct s_string *, char const *);
  char		(*at)(struct s_string* , size_t);
  void		(*clear)(struct s_string *);
  int		(*size)(struct s_string *);
  int		(*compare_s)(struct s_string *, struct s_string const *);
  int		(*compare_c)(struct s_string *, char const *);
  size_t	(*copy)(struct s_string *, char *, size_t, size_t);
  char		*(*c_str)(struct s_string *);
  int		(*empty)(struct s_string *);
  int		(*find_s)(struct s_string *, struct s_string const *, size_t);
  int		(*find_c)(struct s_string *, char const *, size_t);
}		t_string;

void	stringInit(t_string *, char const *);
void	string_init_first(t_string *);
void	string_init_second(t_string *);
void	string_init_third(t_string *);
void	s_stringDestroy(t_string *);
char	*my_strcat(char *, char const *);

#endif /* !STRING_H_ */
