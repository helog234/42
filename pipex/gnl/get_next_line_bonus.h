/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:08:20 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/09 18:35:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd, char *line, int i);
char	*fill_line_buffer(int fd, char *stock, char *buffer);
int		ft_strchr_line(const char *line, int c);
char	*ft_substr_l(char const *s, unsigned int start, size_t len, size_t i);
char	*free_str(char *str);
char	*ft_strjoin_l(char *s1, char const *s2);
char	*init(char *stock, int fd);

#endif