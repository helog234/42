# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 12:01:31 by hgandar           #+#    #+#              #
#    Updated: 2024/07/04 15:35:50 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INC = ClapTrap.hpp ScavTrap.hpp FragTrap.cpp
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