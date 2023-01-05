# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:41:47 by kdaiane-          #+#    #+#              #
#    Updated: 2023/01/05 01:01:07 by kdaiane-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		src/so_long.c \
			src/inicialize_values.c \
			src/map_validation.c \
			src/valid_path.c \
			src/grid.c \
			src/inicialize_mlx.c \
			src/render.c \
			src/sprites.c \
			src/movements.c \
			src/handle_error.c \
			src/end_game.c

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