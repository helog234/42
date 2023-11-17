/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:04:02 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/17 16:04:16 by hgandar          ###   ########.fr       */
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

char	*set_line(char *stock, char *line, int i, int j)
{
	unsigned int	k;

	k = 0;
	if (i >= 0)
		line = ft_substr(stock, 0, i + 1, k);
	else
		line = ft_substr(stock, 0, j, k);
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
		return (-2);
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
		if ((ft_strlen(stock) == 0 && control == -2 && i == 0) || stock == NULL)
		{
			free(stock);
			return (NULL);
		}
		if (control >= 0)
			return (stock);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stock;
	char		*line;
	int			i;
	int			j;

	line = NULL;
	i = 0;
	j = 0;
	if (fd == -1)
		return (NULL);
	stock = fill_line_buffer(fd, stock, buffer);
	if (stock == NULL)
		return (NULL);
	i = ft_strchr_line(stock, '\n');
	j = ft_strlen(stock);
	line = set_line(stock, line, i, j);
	if (i >= 0)
		stock = set_stock(stock, i, j);
	else
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*line;
	
	//line = NULL;
    fd = open("text_short.txt", O_RDONLY);
	//line = get_next_line(fd);
	//printf("%s", line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}