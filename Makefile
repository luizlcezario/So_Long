# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 16:11:34 by prafael-          #+#    #+#              #
#    Updated: 2022/01/23 22:37:20 by llima-ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx/libmlx_Linux.a

SRC =	so_long.c error.c start_game.c utils.c move.c verify_map.c \
		hooks.c print_map.c print_map_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) $(addprefix ./src/,$(SRC)) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ):
	gcc $(CFLAGS) -I . -c $(addprefix ./src/, $(SRC))

$(LIBFT):
	make others -C ./libft

$(MINILIBX):
	./minilibx/configure

clean:
	rm -f $(NAME)

teste: all
	$(NAME) "./assets/maps/map_3.ber"

valgrind: all
	$(NAME) "./assets/maps/map_3.ber" 
	
.PHONY: all clean teste valgrind