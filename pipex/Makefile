# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:34:06 by hgandar           #+#    #+#              #
#    Updated: 2023/12/14 16:53:54 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CFILES = 	pipex.c \
			utils.c \
			quote.c \
			errors.c
BFILES =	pipex_bonus.c \
			utils_bonus.c \
			quote.c \
			here_doc.c \
			errors.c
OFILES = $(CFILES:.c=.o)
BOFILES = $(BFILES:.c=.o)

all: $(OFILES) $(LIBFT)

link: $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(BOFILES)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	
clean:
	rm -f $(OFILES) $(BOFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:  all clean fclean re bonus