/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/09 18:22:43 by hgandar          ###   ########.fr       */
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

char	*fill_line_buffer(int fd, char *stash, char *buffer)
{
	int		i;
	int		j;
	int		control;

	control = 0;
	i = 1;
	while (i > 0 && control < BUFFER_SIZE_D + 1)
	{
		i = read(fd, buffer, 5);
		control = ft_strlcat_stash(stash, buffer, i);
		if (control == -1)
			return (NULL);
		j = ft_strchr_line(stash, '\n');
		if (j != 0)
			return (stash);
	}
	return (stash);
}

char	*set_line(char *stash, char *line)
{
	int	i;
	int	j;

	i = ft_strchr_line(stash, '\n');
	j = ft_strlen(stash);
	if (i != 0)
	{
		line = ft_substr(stash, 0, i + 1);
		stash[0] = stash[i + 1];
		return(line);
	}
	else
	{
		line = ft_substr(stash, 0, j + 1);
		stash[0] = stash[j + 1];
		return(line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE_D];
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE_D <= 0)
		return (NULL);
	line = NULL;
	stash = malloc((BUFFER_SIZE_D + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	stash = fill_line_buffer(fd, stash, buffer);
	line = set_line(stash, line);
	free(stash);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*line;
    fd = open("text.txt", O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}