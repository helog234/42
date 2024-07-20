# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 09:57:13 by hgandar           #+#    #+#              #
#    Updated: 2024/07/18 15:53:23 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Converter
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
CPPFILES = main.cpp ScalarConverter.cpp Checker.cpp Converter.cpp Print.cpp
INC = ScalarConverter.hpp Checker.hpp Converter.hpp Print.hpp
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