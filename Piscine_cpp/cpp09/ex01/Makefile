# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 14:13:12 by hgandar           #+#    #+#              #
#    Updated: 2024/07/26 14:14:08 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
CPPFILES = main.cpp RPN.cpp
INC = RPN.hpp
OFILES = $(CPPFILES:.cpp=.o)
LEAK = Leaks -atExit --
SANIT = -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re