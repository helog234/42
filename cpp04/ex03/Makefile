# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 17:41:51 by hgandar           #+#    #+#              #
#    Updated: 2024/07/03 13:02:34 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Complex
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
CPPFILES = main.cpp AMateria.cpp Ice.cpp \
Cure.cpp Character.cpp MateriaSource.cpp
INC = AMateria.hpp Ice.hpp Cure.hpp Character.hpp \
ICharacter.hpp MateriaSource.hpp IMateriaSource.hpp
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