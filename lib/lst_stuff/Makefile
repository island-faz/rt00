##
## Makefile for lib in /home/bourhi_a/rendu/PSU_2013_minitalk/lib
## 
## Made by amine bourhime
## Login   <bourhi_a@epitech.net>
## 
## Started on  Tue Mar 18 18:24:20 2014 
## Last update Tue Jun  3 07:00:41 2014 
##

NAME		=	liblist.a

SRC		= 	src/init_list.c \
			src/push_back.c \
			src/push_front.c \
			src/in_list.c \
			src/rm_elem.c \
			src/list_len.c \
			src/rm_first.c \
			src/rm_last.c \
			src/get_rev.c \
			src/get_elem.c \
			src/sort_list.c \
			src/clone_list.c \
			src/get_index.c \
			src/to_array.c \

OBJ		=	$(SRC:.c=.o)

CC		=	cc -W -Wall -ansi -pedantic -Wextra -g

RM		=	rm -f

BCP		=	*~

CFLAGS		=	-I./include

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			ar -r $(NAME) $(OBJ)
			ranlib $(NAME)

clean		:
			$(RM) $(OBJ) lib/$(BCP) include/$(BCP) $(BCP)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
