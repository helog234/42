# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:57:41 by hgandar           #+#    #+#              #
#    Updated: 2024/06/20 10:09:24 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFILES = main.cpp phonebook.cpp contact.cpp
INC = phonebook.hpp contact.hpp
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