##
## Makefile for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy/Client
## 
## Made by Caltraba Mickael
## Login   <calatr_m@epitech.net>
## 
## Started on  Mon Jun 22 13:19:11 2015 Caltraba Mickael
## Last update Sun Jul  5 17:08:27 2015 paul david
##

NAME		=	zappy_ai

CXX		=	g++

CXXFLAGS	=	-W -Wall -Werror -std=c++11
CXXFLAGS	+=	-I./include/
CXXFLAGS	+=	-I../GRAPHIC/include/

SRCS		=	main.cpp				\
			../GRAPHIC/srcs/Socket/Socket.cpp	\
			../GRAPHIC/srcs/Select/Select.cpp	\
			src/IA.cpp

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)
		cp $(NAME) ../../

clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)
		$(RM) ../../$(NAME)

re		:	fclean all

.PHONY		:	fclean clean all re


