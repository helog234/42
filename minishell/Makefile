# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 13:46:07 by hgandar           #+#    #+#              #
#    Updated: 2024/03/01 13:49:41 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = ./minishell.h

CFILES = 	

PS_FILES = main.c $(CFILES)
PS_OFILES = $(PS_FILES:.c=.o)

all: $(NAME)

$(NAME): libft $(PS_OFILES)
	$(CC) $(CFLAGS) $(PS_OFILES) -L$(LIBFT_DIR) -lft -o $@

libft:
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PS_OFILES)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft