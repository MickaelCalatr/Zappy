##
## Makefile for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Server
## 
## Made by Caltraba Mickael
## Login   <calatr_m@epitech.net>
## 
## Started on  Mon May 11 14:27:01 2015 Caltraba Mickael
## Last update Sun Jul  5 17:08:49 2015 paul david
##

CC	=	gcc

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I./include

RM	=	rm -f

NAME	=	zappy_server

SRCSCMD	=	main.c			\
		error_functions.c	\
		parsing_functions.c	\
		parsing_functions_bis.c	\
		cmd_graphic.c		\
		cmd_env.c		\
		cmd_game.c		\
		actions.c		\
		cmd_all.c		\
		message.c		\
		cmd_ia.c		\
		String.c		\
		String_second.c		\
		String_third.c		\
		String_utility.c	\
		Trantorien.c		\
		case.c			\
		food.c			\
		map.c			\
		move.c			\
		ressources.c		\
		Tranto_move.c		\
		Tranto_see.c		\
		Tranto_movement.c	\
		Tranto_primary.c	\
		case_primary.c		\
		Tranto_incant.c		\
		Tranto_broad.c		\
		Tranto_expulse.c	\
		Tranto_all.c		\
		ressource_spawn.c	\
		tools.c

SRCSNET	=	handler_connection.c	\
		init_server.c		\
		init_client.c		\
		start_server.c		\
		handler_signal.c	\
		write_client.c		\
		concat_buff.c		\
		reponse_to_client.c	\
		find_cmd.c		\
		error.c

NETPATH	=	./src/Socket/
CMDPATH	=	./src/Command/

OBJS	=	$(addprefix $(CMDPATH), $(SRCSCMD:.c=.o)) $(addprefix $(NETPATH), $(SRCSNET:.c=.o))

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	cp $(NAME) ../

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
