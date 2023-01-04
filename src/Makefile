# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:41:47 by kdaiane-          #+#    #+#              #
#    Updated: 2022/11/07 19:32:56 by kdaiane-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		so_long.c \
			inicialize_values.c \
			map_validation.c \
			valid_path.c \
			grid.c \
			inicialize_mlx.c \
			render.c \
			sprites.c \
			movements.c \
			handle_error.c \
			end_game.c

NAME =		so_long
FLAGS =		-Wall -Wextra -Werror
FMLX =	 	-lmlx -lXext -lX11

LIBFT =		libft/libft.a
PRINTF =	printf/libftprintf.a

OBJS = 		${SRC:%.c=%.o}

all: ${NAME}

%.o: %.c
	cc -g3 -c ${FLAGS} $< -o $@

${LIBFT}:
	make -sC libft/

${PRINTF}:
	make -sC printf/

${NAME}: 	${LIBFT} ${PRINTF} ${OBJS}
	cc -g3 ${FLAGS} ${OBJS} ${LIBFT} ${PRINTF} ${FMLX} -o $@

clean: 
	rm -f ${OBJS}
	make clean -sC libft/
	make clean -sC printf/

fclean: clean
	rm -rf ${NAME}
	rm -f ${OBJS}
	make fclean -sC libft/
	make fclean -sC printf/

re: fclean all

PHONY: re fclean clean all