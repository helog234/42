/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:08:20 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/18 13:04:03 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *stock, char *buffer);
char	*set_stock(char *stock, int i, int j);
int		ft_strchr_line(const char *line, int c);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *str1);
char	*ft_substr(char const *s, unsigned int start, size_t len, size_t i);

#endif