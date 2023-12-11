# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:34:06 by hgandar           #+#    #+#              #
#    Updated: 2023/12/10 11:16:18 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFT_DIR = libft
GNL_DIR = gnl
LIBFT = $(LIBFT_DIR)/libft.a
GNL_OFILES = $(GNL_DIR)/get_next_line_bonus.o \
             $(GNL_DIR)/get_next_line_utils_bonus.o
CFILES = 	pipex.c \
			utils.c
BFILES =	pipex_bonus.c \
			utils_bonus.c
OFILES = $(CFILES:.c=.o)
BOFILES = $(BFILES:.c=.o)

all : $(NAME)

$(NAME): $(OFILES) $(LIBFT) $(GNL_OFILES)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BOFILES) $(LIBFT) $(GNL_OFILES)
	ar rcs $(NAME) $(BOFILES)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OFILES) $(BOFILES)
	rm -f $(GNL_OFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:  all clean fclean re