/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:36:48 by mremenar          #+#    #+#             */
/*   Updated: 2023/12/04 09:08:58 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_line
{
	int				id_fd;
	char			*line;
	struct s_line	*next;
}	t_line;

char	*get_next_line(int fd);

char	*extract_line(t_line *curr_file, int fd);

char	*cpy_lines(t_line *curr_file, int len);

void	gnl_strlcat(char **dst, char *src);

int		gnl_len(char *str, char end);

int		verif(t_line **root, int fd);

t_line	*gnl_add_new(t_line **lst, int fd);

void	free_list(t_line **root, int fd);

t_line	*find_to_free(t_line *root, int fd);

void	free_curr(t_line *curr);

#endif