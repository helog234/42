# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 09:13:08 by hgandar           #+#    #+#              #
#    Updated: 2024/05/14 11:23:57 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./
OBJS_DIR = ./objs

INC = -I. -I ./libft

CFILES = $(addsuffix .c, main)
OFILES = $(CFILES:%.c=$(OBJS_DIR)/%.o)

all: obdir $(NAME)

$(NAME): $(OFILES) | libftk 
	$(CC) $(CFLAGS) -L $(LIBFT_DIR) -lft -o $@ $^

libftk:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obdir:
	@test -d $(OBJS_DIR) || mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft obdir
