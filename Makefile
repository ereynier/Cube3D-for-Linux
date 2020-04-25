# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/08 18:19:15 by ereynier     #+#   ##    ##    #+#        #
#    Updated: 2019/10/26 11:49:29 by ereynier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS	= srcs/parsing.c srcs/main.c srcs/parsing_2.c srcs/parsing_map.c srcs/utils.c \
			srcs/raycasting.c srcs/utils_2.c srcs/input.c srcs/utils_raycast.c srcs/display.c \
			srcs/utils_input.c srcs/init_variables.c srcs/utils_sprite.c srcs/display_sprite.c \
			srcs/utils_sprite_2.c srcs/utils_sprite_3.c srcs/save.c srcs/utils_raycast_2.c

OBJS	= ${SRCS:.c=.o}

NAME	= Cub3D

LIBFT	= libft/libft.a

MINILIBX= minilibX/libmlx.a

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c	$(INCS)
		gcc $(CFLAGS) -o $@ -c $<

$(NAME):	${OBJS}
			make -C minilibX
			make -C libft
			gcc -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX) -lm -lbsd -lX11 -lXext
			
all:		${NAME}

clean:		
			rm -f ${OBJS}
			make clean -C libft

fclean:		clean
			rm -f ${NAME} cub.bmp
			make clean -C minilibX
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean
