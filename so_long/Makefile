# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 17:59:58 by hgandar           #+#    #+#              #
#    Updated: 2024/02/26 11:51:57 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Wno-deprecated-declarations -g3
LIBFT_DIR = libft
MLX_DIR = mlx
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLXINC = $(MLX_DIR)/mlx.h
INC = ./so_long.h

CFILES = 	error.c \
			map_init.c \
			map_utils.c \
			parsing.c \
			launch_game.c \
			move.c \
			map_vizu.c \
			play.c

PS_FILES = main.c $(CFILES)
PS_OFILES = $(PS_FILES:.c=.o)

all: $(NAME)

$(NAME): libft $(PS_OFILES) $(MLX)
	$(CC) $(CFLAGS) $(PS_OFILES) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $@

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PS_OFILES)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re libft