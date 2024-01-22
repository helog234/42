# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 12:38:13 by hgandar           #+#    #+#              #
#    Updated: 2024/01/22 17:27:56 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
#-fsanitize=address
LFLAG = leaks -atExit --
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LFTINC = $(LIBFT_DIR)/libft.h
INC	= ./push_swap.h

CFILES = 	main.c \
			init_stack.c \
			op_push.c \
			op_swap.c \
			op_rot.c \
			rev_rot.c \
			sort_values.c \
			common_stacks_op.c \
			on_a_stack_op.c \
			on_b_stack_op.c \
			print_stack.c \
			errors.c
				
OFILES = $(CFILES:.c=.o)
BOFILES = $(BFILES:.c=.o)

all : $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): $(LFTINC) $(INC)
	make -C $(LIBFT_DIR)

$(LFTINC):
	make -C $(LIBFT_DIR) $(LFTINC)

%.o: %.c $(INC) $(LFTINC)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(BOFILES)
	$(CC) $(CFLAGS) $^ -o $(NAME)

leaks:
	$(LFLAGS) ./push_swap 2 1 3 6 5 8 1
	
clean:
	rm -f $(OFILES) $(BOFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:  all clean fclean re bonus