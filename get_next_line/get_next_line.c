/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:38:25 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/14 12:48:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *str1)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = (char *) malloc (ft_strlen(str1) + 1);
	if (str2 == NULL)
		return (NULL);
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}

char	*set_line(char *stash, char *line)
{
	int	i;
	int	j;

	i = ft_strchr_line(stash, '\n');
	j = ft_strlen(stash);
	if (i >= 0)
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, j + 1);
	return (line);
}

int	ft_strchr_line(const char *line, int c)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == (char) c)
			return (i);
		i++;
	}
	if (!line || line[i] == 0)
		return (0);
	return (-1);
}

char	*fill_line_buffer(int fd, char *stock, char *buffer)
{
	int	i;
	int	control;

	i = 1;
	control = 0;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buffer[i] = 0;
		stock = ft_strjoin(stock, buffer);
		control = ft_strchr_line(stock, '\n');
		if (i == 0 && control == 0)
		{
			free(stock);
			return (NULL);
		}
		if (control >= 0)
			return (stock);
		if (i == 0 && control > 0)
			return (stock);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	char		*line;

	line = NULL;
	if (fd == -1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	stock = fill_line_buffer(fd, stock, buffer);
	if (stock == NULL)
	{
		free(buffer);
		return (NULL);
	}
	line = set_line(stock, line);
	stock = set_stock(stock);
	free(buffer);
	return (line);
}
/* #include <fcntl.h>
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
} */