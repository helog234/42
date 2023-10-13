/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:02:49 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/13 19:04:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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