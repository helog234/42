# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 17:59:58 by hgandar           #+#    #+#              #
#    Updated: 2024/02/02 18:27:14 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Wno-deprecated-declarations -g3 -fsanitize=address
# -g3 -fsanitize=address
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LFTINC = $(LIBFT_DIR)/libft.h
INC	= ./so_long.h

CFILES = 	


PS_FILES = main.c $(CFILES)			
PS_OFILES =  $(PS_FILES:.c=.o)


all : $(NAME)

#est-ce que les CFLAGS sont nécessaires ici ?
$(NAME): $(PS_OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(LIBFT): $(LFTINC) $(INC)
	make -C $(LIBFT_DIR)

$(LFTINC):
	make -C $(LIBFT_DIR) $(LFTINC)

%.o: %.c $(INC) $(LFTINC)
	$(CC) $(CFLAGS) -c $< -o $@

	
clean:
	rm -f $(PS_OFILES) $(BOFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:  all clean fclean re bonus