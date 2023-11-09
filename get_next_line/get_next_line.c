/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/09 16:25:54 by hgandar          ###   ########.fr       */
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
	int		control;

	control = 0;
	i = 1;
	while (i != 0 > 0 && control < BUFFER_SIZE_D)
	{
		i = read(fd, buffer, 5);
		control = ft_strlcat_stash(stash, buffer, i);
		if (control == -1)
			return (NULL);
		i = ft_strchr_line(stash, '\n');
		if (i != 0)
			return (stash);
		else
			continue ;
	}
	return (stash);
}

char	*set_line(char *stash, char *line)
{
	int	i;

	i = ft_strchr_line(stash, '\n');
	line = ft_substr(stash, 0, i + 1);
	stash[0] = stash[i + 1];
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE_D];
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE_D <= 0 || read(fd, buffer, 5) <= 0)
		return (NULL);
	line = NULL;
	stash = malloc((BUFFER_SIZE_D + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	stash = fill_line_buffer(fd, stash, buffer);
	line = set_line(stash, line);
	return (line);
}

/* #include <fcntl.h>
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
} */