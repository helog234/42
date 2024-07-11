# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 10:00:38 by hgandar           #+#    #+#              #
#    Updated: 2024/07/08 15:26:14 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = utils
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
CPPFILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
RobotomyRequestForm.cpp PresidentialPardonForm.cpp
INC = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
RobotomyRequestForm.hpp PresidentialPardonForm.hpp
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