# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:35:56 by hgandar           #+#    #+#              #
#    Updated: 2023/11/03 14:44:50 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 	ft_printf.c \
			var_arg_c.c \
			var_arg_di.c \
			var_arg_prce.c \
			var_arg_px.c \
			var_arg_u.c
OFILES = $(CFILES:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re