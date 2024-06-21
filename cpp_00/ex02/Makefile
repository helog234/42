# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:28:20 by hgandar           #+#    #+#              #
#    Updated: 2024/06/21 16:22:05 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dreamjob
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFILES = tests.cpp Account.cpp
INC = Account.hpp
OCPPFILES = $(CPPFILES:.c=.o)

all: $(NAME)

$(NAME): $(OCPPFILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OCPPFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re