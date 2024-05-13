# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 16:37:56 by hgandar           #+#    #+#              #
#    Updated: 2024/05/13 13:08:34 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INC = ./philo.h
#leaks -atExit --
#-g3 -fsanitize=address

CFILES = parsing.c \
		set_table.c \
		process.c \
		dinner.c \
		eat_think_sleep.c \
		msg_and_free.c \
		utils.c

PS_FILES = main.c $(CFILES)
PS_OFILES = $(PS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(PS_OFILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PS_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re