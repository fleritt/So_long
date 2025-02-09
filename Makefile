# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 10:11:54 by marvin            #+#    #+#              #
#    Updated: 2024/12/03 10:11:54 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = So_long

LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx_Linux.a

CC = gcc
CFLAGS 	= -Wall -Werror -Wextra -fsanitize=address -g3
MINILIBX_FLAGS	= -lmlx -lXext -lX11
RM = rm -f

SRC = ./src/so_long.c ./src/ft_keypress.c ./src/ft_load_map.c ./src/ft_error.c \
./src/ft_draw_map.c ./src/ft_victory.c ./src/ft_check_map.c
OBJ = $(SRC:.c=.o)

BONUSSRC =
BONUSOBJ = $(BONUSSRC:.c=.o)
	
all: ${MLX} ${LIBFT} ${NAME}

${NAME}: ${OBJ}
		${CC} ${SRC} ${MLX} ${LIBFT} ${CFLAGS} ${MINILIBX_FLAGS} -o ${NAME}

${LIBFT}:
		make -C libft/

bonus: ${OBJ}
		${CC} ${SRC} ${MLX} ${LIBFT} ${CFLAGS} ${MINILIBX_FLAGS} -o ${NAME}

clean: 
		make clean -C libft/
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}
		make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re