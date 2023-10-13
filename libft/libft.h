/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:02:49 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/13 20:04:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

CFILES = t_isalpha.c, ft_isdigit.c, ft_isalnum.c, ft_isascii.c, \
         ft_isprint.c, ft_strlen.c, ft_memset.c, ft_bzero.c, \
         ft_memcpy.c, ft_memmove.c, ft_strlcpy.c, ft_strlcat.c, \
         ft_toupper.c, ft_tolower.c, ft_strchr.c, ft_strrchr.c, \
         ft_strcmp.c, ft_memcmp.c, ft_strnstr.c, ft_atoi.c

OFILES = $(SRCS:.c=.o)

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

#ifndef __LIBFT__
#define __LIBFT__

int	ft_isalpha();
int	ft_isdigit();
int	ft_isalnum();
int	ft_isascii();
int	ft_isprint();
int	ft_strlen();
void	*ft_memset();
void	ft_bzero();
void	*ft_memcpy();
void	*ft_memmove();
unsigned long	ft_strlcpy();
unsigned long	ft_strlcat();
char	ft_toupper();
char	ft_tolower();
const char	*ft_strchr();
const char	*ft_strrchr();
int	ft_strcmp();
void	*ft_memchr();
int	ft_memcmp();
char *ft_strnstr();
int	ft_atoi();


#endif