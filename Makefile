##
## Makefile for rt in /home/bourhi_a/rendu/rt
## 
## Made by amine bourhime
## Login   <bourhi_a@epitech.net>
## 
## Started on  Mon Mar 24 04:32:01 2014 
## Last update Wed Jun  4 08:04:05 2014 
##

MLX		=	-lmlx -L./mlx -L/usr/lib64/X11 -lXext -lX11

SRC		= 	src/main.c \
			src/init_rt.c \
			src/graphix/init_graphix.c \
			src/graphix/pixel_to_img.c \
			src/graphix/img_to_win.c \
			src/obj_parser/parse_obj_file.c \
			src/obj_parser/parser_functions.c \
			src/obj_parser/show_obj_data.c \
			src/obj_parser/obj_correction.c \
			src/geometry/geometry_functions.c \
			src/geometry/point_rotation.c \
			src/geometry/plane_ray_inter.c \
			src/geometry/obj_ray_inters.c \
			src/geometry/obj_functions.c \
			src/geometry/triangle.c \
			src/geometry/quad.c \

OBJ		=	$(SRC:.c=.o)

NAME		=	xrt

GRPOF		=	-pg

CC		=	cc $(GRPOF) -lm

INCLUDE		=	-I./include -I./lib -I./lib/lst_stuff/include -I./mlx

DEBUG		=	-W -Wall -ansi -pedantic -Wextra -g

CFLAGS		=	$(INCLUDE) $(DEBUG)

LDFLAGS		=	-lmy -L./lib -llist -L./lib/lst_stuff $(MLX)

RM		=	rm -f

BCP		=	*~

LIB		=	lib

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			make -C $(LIB)
			$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			make clean -C $(LIB)
			$(RM) $(OBJ)

fclean		:	clean
			make fclean -C $(LIB)
			$(RM) $(NAME)

re		:	fclean all
