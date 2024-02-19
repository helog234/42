# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 17:59:58 by hgandar           #+#    #+#              #
#    Updated: 2024/02/19 15:57:10 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Wno-deprecated-declarations -g3
# -g3 -fsanitize=address
LIBFT_DIR = libft
MLX_DIR = mlx
LIBFT = $(LIBFT_DIR)/libft.a
LFTINC = $(LIBFT_DIR)/libft.h
MLX = $(MLX_DIR)/libmlx.a
MLXINC = $(MLX_DIR)/mlx.h
INC	= ./so_long.h

CFILES = 	error.c \
			map_init.c \
			map_utils.c \
			parsing.c \
			launch_game.c \
			move.c \
			play.c \


PS_FILES = main.c $(CFILES)			
PS_OFILES =  $(PS_FILES:.c=.o)

all : $(NAME)

$(NAME): $(PS_OFILES) $(LIBFT) $(MLX)
	$(CC) -g $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(LIBFT): $(LFTINC) $(INC)
	make -C $(LIBFT_DIR)

$(LFTINC):
	make -C $(LIBFT_DIR) $(LFTINC)

$(MLX): $(MLXINC) $(INC)
	make -C $(MLX_DIR)

$(MLXINC):
	make -C $(MLX_DIR) $(MLXINC)

%.o: %.c $(INC) $(LFTINC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PS_OFILES) $(BOFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:  all clean fclean re bonus