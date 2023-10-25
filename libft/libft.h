/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:02:49 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/25 10:25:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *s);
void			*ft_memset(void *str, int c, size_t len);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void	*dst, const void *src, unsigned long n);
void			*ft_memmove(void *dst, const void *src, unsigned long len);
unsigned long	ft_strlcpy(char *dst, const char *src, size_t dstsize);
unsigned long	ft_strlcat(char *dst, const char *src, size_t dstsize);
char			ft_toupper(int c);
char			ft_tolower(int c);
const char		*ft_strchr(const char *s, int c);
const char		*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *str1, const char *str2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strnstr(const char *hstack, const char *needle, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *str1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);

#endif