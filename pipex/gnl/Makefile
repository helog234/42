# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 10:37:17 by hgandar           #+#    #+#              #
#    Updated: 2023/12/08 17:41:36 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CC = gcc
LIBFT_DIR = ../libft
CFLAGS = -Wall -Wextra -Werror
CFILES = 	get_next_line_bonus.c \
			get_next_line_utils_bonus.c
LIBFT = $(LIBFT_DIR)/libft.a
OFILES = $(CFILES:.c=.o)
BOFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	ar rcs $(NAME) $(OFILES)

bonus: $(BOFILES) $(LIBFT)
	ar rcs $(NAME) $(BOFILES)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OFILES) $(BOFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:  all clean fclean re