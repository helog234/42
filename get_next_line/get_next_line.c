/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/09 14:57:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int	ft_strchr_line(const char *line, int c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == (char) c)
			return (i);
		else
			i++;
	}
	return (0);
}

char	*fill_line_buffer(int fd, char *stash, char *buffer, char *line)
{
	size_t	count;
	int		i;
	int		j;
	int		control;

	count = 5;
	control = 0;
	j = 0;
	while ((j = read(fd, buffer, count)) > 0 && control + 1 < BUFFER_SIZE_D)
	{
		control = ft_strlcat_stash(stash, buffer, j);
		if (control == - 1)
			return (NULL);
		i = ft_strchr_line(stash, '\n');
		if (i != 0)
		{
			line = ft_substr(stash, 0, i + 1);
			stash[0] = stash[i + 1];
			return (line);
		}
		else
			continue ;
	}
	line = ft_strdup(stash);
	return(line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE_D];
	static char	*stash;
	char		*line;

	line = NULL;
	stash = malloc((BUFFER_SIZE_D) * sizeof(char));
	if(!stash)
		return (NULL);
	stash = fill_line_buffer(fd, stash, buffer, line);
	return(stash);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*line;
    fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}