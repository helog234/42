/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:38:49 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/13 11:21:11 by hgandar          ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *stock, char *buffer);
char	*set_stock(char *stock);
int		ft_strchr_line(const char *line, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif