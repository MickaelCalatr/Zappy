/*
** server.h for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server/include
** 
** Made by Caltraba Mickael
** Login   <calatr_m@epitech.net>
** 
** Started on  Mon May 11 15:50:02 2015 Caltraba Mickael
** Last update Sun Jul  5 14:00:48 2015 paul david
*/

#ifndef _SERVER_H_
# define _SERVER_H_

#include <stdio.h>
#include "ZappyServer.h"
#include "map.h"
#include "Trantorien.h"

# define true		0
# define false		-1
# define HOST		"zappy.love.org"
# define SIZE		4096
# define TIME		5
# define REQUEST	10
# define CONVERT	1000000
# define SEC		((now.tv_sec - client->time.tv_sec) * CONVERT)
# define USEC		(now.tv_usec - client->time.tv_usec)
# define DELAY(x)	(float)(((x) * CONVERT) / server->args->time)
# define COMP(x)	(((SEC + USEC) > DELAY(x)) ? 1 : 0)
# define STRANT(x)	server->user[x]->trant
# define CTRANT		client->trant

typedef int		bool;
typedef bool		(*fptr)();

extern char		text[7][6];

typedef enum		err_type
  {
    NOERRNO = 0,
    ERRNO,
  }			err_type;

typedef enum		color
  {
    GREEN = 0,
    RED,
    BLUE,
    YELLOW,
    NOCOLOR,
    PURPLE,
    CYAN,
  }			color;

typedef enum		fd_type
  {
    FD_FREE = 0,
    FD_CLIENT,
    FD_SERVER,
    FD_SOCKET,
  }			fd_type;

typedef struct		s_client
{
  int			id;
  int			fd;
  int			team;
  int			client_socket_id;
  int			ret;
  int			ret_r;
  char			buff[SIZE];
  char			buff_r[SIZE];
  bool			graphic;
  bool			action;
  struct timeval	food;
  struct timeval	time;
  t_trantorien		trant;
}			t_client;

typedef struct		s_server
{
  t_args		*args;
  int			socket;
  fd_type		*fd_type;
  fptr			*exec;
  t_client		**user;
  int			client_log;
  int			client_max;
  int			*id_users;
  int			*team;
  t_map			map;
}			t_server;

typedef struct		s_cmd
{
  const char		*cmd;
  bool			(*func)(t_client *, t_server *);
}			t_cmd;

/*
* action.c
*/
void	inventory_graphic(t_server *, t_client *);
void	drop_graphic(t_server *, t_client *, const char cmd[]);
void	take_graphic(t_server *, t_client *, const char cmd[]);
void	exp_graphic(t_server *, t_client *, t_client *);
bool	f_nb_connect(t_client *, t_server *);
/*
** cmd_all.c
*/
bool	f_exp(t_client *, t_server *);
bool	f_broad(t_client *, t_server *);
bool	incant(t_client *, t_server *);

/*
** cmd_env.c
*/
bool	f_view(t_client *, t_server *);
bool	f_drop(t_client *, t_server *);
bool	f_take(t_client *, t_server *);
bool	f_inventory(t_client *, t_server *);
bool	f_incant(t_client *, t_server *);

/*
** cmd_game.c
*/
void	send_player(t_server *, t_client *);
void	send_players(t_server *);
void	send_case(t_server *, int, int);
void	send_map(t_server *);
void	send_egg(t_server *, t_client *);

/*
** cmd_graphic.c
*/
void	send_to_graphic(t_server *, char *, int);
bool	f_graphic(t_server *, t_client *);

/*
** cmd_ia.c
*/
bool	f_connect(t_server *, t_client *);

/*
** concat_buff.c
*/
void	concat_buff(char buff[], char *conc, int size);

/*
** error.c
*/
bool	my_error(const char *msg, err_type type);

/*
** find_cmd.c
*/
bool	find_separator(char buff[], int size);
bool    find_cmd(t_client *client, t_server *server);

/*
** find_food.c
*/
void	find_food(t_server *);

/*
** handler_client.c
*/
bool	handler_client(int client_fd, t_server *server);

/*
** handler_connection.c
*/
void	shut_down(int signal);
bool	handler_connection(t_server *);

/*
** handler_signal.c
*/
void	shutdown_server(int signal_id, t_server *server);
bool	signal_handler();

/*
** init_client.c
*/
bool	add_client(int fd_socket, t_server *server);
bool	init_users(t_server *server);

/*
** init_server.c
*/
bool	init_server(t_server *server);

/*
** main.c
*/
int	print_usage();

/*
** message.c
*/
void	broad_graphic(t_server *, t_client *, const char buff[]);
void	incant_graphic(t_server *, t_client *);
void	end_incant(t_server *server, t_client *client, int yes);

/*
** move.c
*/
void	move(t_server *, t_client *);
bool	f_forward(t_client *, t_server*);
bool	f_right(t_client *, t_server*);
bool	f_left(t_client *, t_server*);

/*
** reponse_to_client.c
*/
bool	reponse_to_client(int client_fd, char *msg, t_server *server, int len);

/*
** ressources_spawn.c
*/
void	spawn_res(t_map *);
void	spawn_food(t_map *);

/*
** start_server.c
*/
bool	start_server(t_server *server);

/*
** write_on_client.c
*/
bool	deco_client(t_server *server, t_client *client, int client_fd);
bool	write_on_client(int client_fd, t_server *server);
bool	read_on_client(int client_fd, t_server *server);

#endif /* !_SERVER_H_ */
