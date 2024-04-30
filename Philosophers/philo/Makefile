# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 16:37:56 by hgandar           #+#    #+#              #
#    Updated: 2024/04/29 17:37:09 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
INC = ./philo.h

CFILES = 

PS_FILES = main.c $(CFILES)
PS_OFILES = $(PS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(PS_OFILES)
	$(CC) $(CFLAGS) $(PS_OFILES) $^ -o $@

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PS_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re