##
## Makefile for lib in /home/bourhi_a/rendu/PSU_2013_minitalk/lib
## 
## Made by amine bourhime
## Login   <bourhi_a@epitech.net>
## 
## Started on  Tue Mar 18 18:24:20 2014 
## Last update Fri May 30 00:20:05 2014 
##

LISTS		=	lst_stuff

NAME		=	libmy.a

SRC		= 	explode.c \
			explose.c \
			xmalloc.c \
			my_putstr.c \
			my_putnbr.c \
			my_strlen.c \
			my_stralen.c \
			my_revstr.c \
			is_digit.c \
			my_atoi.c \
			my_atof.c \
			my_strdup.c \
			my_memset.c \
			is_file.c \
			my_strcmp.c \
			my_strncmp.c \
			merge_string.c \
			epur_str.c \
			my_char_replace.c \
			get_next_line.c \

OBJ		=	$(SRC:.c=.o)

CC		=	cc -g

RM		=	rm -f

BCP		=	*~

CFLAGS		=	-I./ -I./lst_stuff/include

all:			$(NAME)

$(NAME):		$(OBJ)
			make -C $(LISTS)
			ar -r $(NAME) $(OBJ)
			ranlib $(NAME)

clean:	
			make clean -C $(LISTS)
			$(RM) $(OBJ) lib/$(BCP) include/$(BCP) $(BCP)

fclean:			clean
			make fclean -C $(LISTS)
			$(RM) $(NAME)

re:	fclean all
