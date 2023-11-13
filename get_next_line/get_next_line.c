/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:38:25 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/13 14:14:04 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

char	*set_line(char *stash, char *line)
{
	int	i;
	int	j;

	i = ft_strchr_line(stash, '\n');
	j = ft_strlen(stash);
	if (i != 0)
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, j + 1);

	return (line);
}

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

char	*fill_line_buffer(int fd, char *stock, char *buffer)
{
	int	i;
	int	control;

	i = 1;
	control = 0;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE_D);
		if (i == -1)
			return (NULL);
		buffer[i] = 0;
		stock = ft_strjoin(stock, buffer);
		control = ft_strchr_line(stock, '\n');
		if (control != 0)
			return (stock);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE_D];
	static char	*stock;
	char		*line;

	line = NULL;
	stock = fill_line_buffer(fd, stock, buffer);
	if (stock == NULL)
	{
		free(stock);
		return (NULL);
	}
	line = set_line(stock, line);
	stock = set_stock(stock);
	return (line);
}
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*line;
    fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}