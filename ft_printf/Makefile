# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:35:56 by hgandar           #+#    #+#              #
#    Updated: 2023/11/07 10:58:26 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 	ft_printf.c \
			va_arg_c.c \
			va_arg_di.c \
			va_arg_prce.c \
			va_arg_p.c \
			va_arg_s.c \
			va_arg_u.c \
			va_arg_x.c \
			functions.c \
			function_hexa.c
			
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