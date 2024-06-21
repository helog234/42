# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:57:41 by hgandar           #+#    #+#              #
#    Updated: 2024/06/21 20:36:13 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFILES = main.cpp phonebook.cpp contact.cpp
INC = phonebook.hpp contact.hpp
OFILES = $(CPPFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re