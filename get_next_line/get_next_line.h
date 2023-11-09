/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:47:06 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/09 15:53:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifdef BUFFER_SIZE
#  define BUFFER_SIZE_D BUFFER_SIZE
# else
#  define BUFFER_SIZE_D 42
# endif

char			*get_next_line(int fd);
char			*fill_line_buffer(int fd, char *stash, char *buffer);
int				ft_strchr_line(const char *line, int c);
unsigned long	ft_strlcat_stash(char *dst, const char *src, int read);
char			*ft_strdup(const char *str1);
int				ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif