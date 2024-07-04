# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:28:20 by hgandar           #+#    #+#              #
#    Updated: 2024/06/24 16:18:46 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dreamjob
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFILES = tests.cpp Account.cpp
INC = Account.hpp
OFILES = $(CPPFILES:.cpp=.o)

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