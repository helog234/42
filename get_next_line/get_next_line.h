/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:47:06 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/08 16:55:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char			*get_next_line(int fd);
int				ft_strchr_line(const char *s, int c);
unsigned long	ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *str1);
int				ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif