##
## Makefile for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client
## 
## Made by Caltraba Mickael
## Login   <calatr_m@epitech.net>
## 
## Started on  Mon Jun 22 13:19:11 2015 Caltraba Mickael
## Last update Sun Jul  5 13:13:29 2015 Alexandre Tanyeres
##

NAME		=	zappy_grf

CXX		=	g++

CXXFLAGS	=	-W -Wall -Werror -std=c++11
CXXFLAGS	+=	-I./lib/SFML-2.2/include/ 
CXXFLAGS	+=	-I./include/

LDFLAGS         =       -L./lib/SFML-2.2/lib/ -Wl,-rpath=./SFML-2.2/lib/
LDFLAGS         +=      -lGLEW
LDFLAGS         +=      -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS         +=      -Wl,-rpath=./lib/SFML-2.2/lib


LDFLAGS         +=       -L./lib/SFML-2.2/lib/
LDFLAGS         +=      -lGLEW
LDFLAGS         +=      -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS		+=	-Wl,-rpath=./Client/GRAPHIC/lib/SFML-2.2/lib
LDFLAGS		+=	-L./Client/GRAPHIC/lib/SFML-2.2/lib	

SRCS		=	main.cpp			\
			srcs/Socket/Socket.cpp		\
			srcs/Select/Select.cpp		\
			srcs/Core/Client.cpp		\
			srcs/Core/Buffer.cpp		\
			srcs/Graphic/ZappyUI.cpp	\
			srcs/Graphic/Map.cpp		\
			srcs/Graphic/Case.cpp		\
			srcs/Graphic/Player.cpp		\
			srcs/Graphic/Eggs.cpp

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)
		cp $(NAME) ../../

clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)
		$(RM) ../../$(NAME)

re		:	fclean all

.PHONY		:	fclean clean all re


