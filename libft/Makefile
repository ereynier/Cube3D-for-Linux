# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ereynier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/08 18:19:15 by ereynier     #+#   ##    ##    #+#        #
#    Updated: 2019/11/01 12:24:47 by ereynier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS	= ft_atoi.c	ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c \
		  ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
		  ft_isascii.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c \
		  ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c \
		  ft_memchr.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c \
		  ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
		  ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_iswspace.c \
		  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c \
		  ft_lstiter.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_putstr.c \
		  ft_putnbr.c ft_putchar.c ft_uitoa.c ft_itohex.c

OBJS	= ${SRCS:.c=.o}

INCS	= libft.h

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c	$(INCS)
		gcc $(CFLAGS) -o $@ -c $<

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean
