##
## Makefile for Makefile in /home/troncy_l/prog/rendu/PSU_2015_my_printf
## 
## Made by lucas TRONCY
## Login   <troncy_l@epitech.net>
## 
## Started on  Tue Nov  3 12:02:47 2015 lucas TRONCY
## Last update Sun Dec 27 21:52:39 2015 
##

SRCS	=	src/main_funcs.c	\
		src/ini_file.c		\
		src/lib/lib.c		\
		src/lib/my_strcmp.c	\
		src/lib/my_getnbr.c	\
		src/lib/my_strcpy.c	\
		src/read_server.c	\
		src/ender.c		\
		src/parser.c		\
		src/my_tracer.c		\
		src/music.c		\
		src/loader.c		\
		src/socket/socket.c	\
		src/socket/com.c	\
		src/my_renderer.c	\
		src/others.c		\
		src/key/do_sound.c	\
		src/key/init_keyboard.c	\
		src/colli.c		\
		src/main.c		\

OBJS	=	$(SRCS:.c=.o)

LIBS	=	-Iinclude/ -L/home/${USER}/.froot/lib

NAME	=	wolf3d

CC	=	cc

CFLAGS	=	-W -Wall -Wextra

CFLAGS	+=	-ansi -pedantic

CFLAGS	+=	-lsfml-audio -lsfml-graphics

CFLAGS	+=	-lsfml-window -lsfml-system

CFLAGS	+=	-lstdc++ -ldl -lm -llapin

CFLAGS 	+=	-g $(LIBS)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
