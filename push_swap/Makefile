# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 12:38:13 by hgandar           #+#    #+#              #
#    Updated: 2024/01/08 13:09:02 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LFTINC = $(LIBFT_DIR)/libft.h
INC	= ./push_swap.h

CFILES = 	main.c \
			init_stack.c \
			op_push.c \
			op_swap.c \
			op_rot.c \
			sort_values.c
BFILES =	
OFILES = $(CFILES:.c=.o)
BOFILES = $(BFILES:.c=.o)

all : $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(INC) $(LFTINC)
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