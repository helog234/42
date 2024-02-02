# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 12:38:13 by hgandar           #+#    #+#              #
#    Updated: 2024/02/02 14:47:47 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker_ps
CC = cc
CFLAGS = -Wall -Wextra -Werror
# -g3 -fsanitize=address
LFLAG = leaks -atExit --
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LFTINC = $(LIBFT_DIR)/libft.h
INC	= ./push_swap.h

CFILES = 	noding.c \
			init_stack.c \
			op_push.c \
			op_swap.c \
			op_rot.c \
			rev_rot.c \
			sort_values.c \
			common_stacks_op.c \
			on_a_stack_op.c \
			on_b_stack_op.c \
			costing.c \
			print_stack.c \
			errors.c

# ajouter print_stack.c au besoin

PS_FILES = main.c $(CFILES)			
PS_OFILES =  $(PS_FILES:.c=.o)

BFILES = checker.c $(CFILES)
BOFILES = $(BFILES:.c=.o)

all : $(NAME)

$(NAME): $(PS_OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): $(LFTINC) $(INC)
	make -C $(LIBFT_DIR)

$(LFTINC):
	make -C $(LIBFT_DIR) $(LFTINC)

%.o: %.c $(INC) $(LFTINC)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(BOFILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(CHECKER_NAME)
	
clean:
	rm -f $(PS_OFILES) $(BOFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:  all clean fclean re bonus