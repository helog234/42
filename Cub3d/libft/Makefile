# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 10:37:17 by hgandar           #+#    #+#              #
#    Updated: 2024/05/14 11:08:19 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER_FILES = ./
CFILES =  ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_free_arr.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strcmp.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_realloc.c \
		  get_next_line.c \
		  get_next_line_utils.c \
		  ft_printf.c \
		  va_arg_c.c \
		  va_arg_di.c \
		  va_arg_prce.c \
		  va_arg_p.c \
		  va_arg_s.c \
		  va_arg_u.c \
		  va_arg_x.c \
		  functions.c \
		  function_hexa.c
		  
BFILES = ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c

OBJS_DIR = ./objs

OFILES = $(CFILES:%.c=$(OBJS_DIR)/%.o)

all: obdir $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_FILES)

obdir:
	@test -d $(OBJS_DIR) || mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re obdir