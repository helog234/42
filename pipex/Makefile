# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:34:06 by hgandar           #+#    #+#              #
#    Updated: 2023/11/28 13:37:05 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 	file.c
			
OFILES = $(CFILES:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re