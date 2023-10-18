# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 10:37:17 by hgandar           #+#    #+#              #
#    Updated: 2023/10/18 12:15:05 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = t_isalpha.c, ft_isdigit.c, ft_isalnum.c, ft_isascii.c, \
         ft_isprint.c, ft_strlen.c, ft_memset.c, ft_bzero.c, \
         ft_memcpy.c, ft_memmove.c, ft_strlcpy.c, ft_strlcat.c, \
         ft_toupper.c, ft_tolower.c, ft_strchr.c, ft_strrchr.c, \
         ft_strcmp.c, ft_memcmp.c, ft_strnstr.c, ft_atoi.c, \
		 ft_calloc.c, ft_strdup.c

OFILES = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME) clean

$(NAME): $(OFILES)
     ar rcs $(NAME) $(OFILES) 

clean:
  rm -f $(OFILES)

fclean:  
  clean rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re