##
## Makefile for zappy in /home/calatr_m/cpp_rendu/PSU/PSU_2014_zappy
## 
## Made by Caltraba Mickael
## Login   <calatr_m@epitech.net>
## 
## Started on  Mon May 11 14:22:37 2015 Caltraba Mickael
## Last update Thu Jun 25 18:05:35 2015 Caltraba Mickael
##

all	:	server client

server	:
		make -C ./Server

client	:
		make -C ./Client/GRAPHIC
		make -C ./Client/IA

clean	:
		make -C ./Server clean
		make -C ./Client/GRAPHIC clean
		make -C ./Client/IA clean

fclean	:
		make -C ./Server fclean
		make -C ./Client/GRAPHIC fclean
		make -C ./Client/IA fclean

re	:	fclean all

.PHONY	:	all server client clean fclean re
