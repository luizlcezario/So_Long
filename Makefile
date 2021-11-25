# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 16:11:34 by prafael-          #+#    #+#              #
#    Updated: 2021/11/25 02:33:17 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Solong.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx/libmlx_Linux.a
SRC =	so_long.c error.c start_game.c utils.c move.c verify_map.c \
		hooks.c print_map.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MINILIBX)
	$(CC) $(addprefix ./src/,$(SRC)) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

$(OBJ):
	gcc $(CFLAGS) -I . -c $(addprefix ./src/, $(SRC))

$(LIBFT):
	make others -C ./libft

$(MINILIBX):
	./minilibx/configure
clean:
	rm -f $(OBJ)

teste: all
	./a.out "./assets/maps/map_3.ber"

valgrind: all
	valgrind -s --show-leak-kinds=all --track-origins=yes  --leak-check=full   ./a.out "./assets/maps/map_3.ber" 
# $(OBJ): $(SRC)
# 	$(CC) -Wall -Wextra -Werror -Imlx_linux -O3 -c $(SRC)