/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:04:02 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/18 13:35:45 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"
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
		line = ft_substr(stock, 0, j + 1, k);
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
		{
			free_str(stock);
			return (NULL);
		}
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
	static char	*stock[FD_MAX];
	char		*line;
	int			i;
	int			j;

	line = NULL;
	i = 0;
	j = 0;
	if (fd == -1 || fd >= FD_MAX)
		return (NULL);
	stock[fd] = fill_line_buffer(fd, stock[fd], buffer);
	if (stock[fd] == NULL)
		return (NULL);
	i = ft_strchr_line(stock[fd], '\n');
	j = ft_strlen(stock[fd]);
	line = set_line(stock[fd], line, i, j);
	if (i >= 0)
		stock[fd] = set_stock(stock[fd], i, j);
	else
	{
		free(stock[fd]);
		stock[fd] = NULL;
	}
	return (line);
}
 #include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd;
    int fd2;
	int fd3;
	int fd4;
    char *line;
    char *line_2;
	char *line_3;
	char *line_4;

    line = NULL;
    fd = open("text_short.txt", O_RDONLY);
    fd2 = open("text.txt", O_RDONLY);
	fd3 = open("line_around_10.txt", O_RDONLY);
	fd4 = open("giant_line_nl.txt", O_RDONLY);

    while ((line = get_next_line(fd)) != NULL && \
	(line_2 = get_next_line(fd2)) != NULL && (line_3 = get_next_line(fd3)) != NULL && (line_4 = get_next_line(fd4)) != NULL)
    {
        if (line != NULL)
        {
            printf("%s", line);
            free(line);
        }
        if (line_2 != NULL)
        {
            printf("%s", line_2);
            free(line_2);
        }
		 if (line_3 != NULL)
        {
            printf("%s", line_3);
            free(line_3);
        }
		 if (line_4 != NULL)
        {
            printf("%s", line_4);
            free(line_4);
        }
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    while ((line_2 = get_next_line(fd2)) != NULL)
    {
        printf("%s", line_2);
        free(line_2);
    }
	while ((line_3 = get_next_line(fd3)) != NULL)
    {
        printf("%s", line_3);
        free(line_3);
    }
	while ((line_4 = get_next_line(fd4)) != NULL)
    {
        printf("%s", line_4);
        free(line_4);
    }
    close(fd);
    close(fd2);
	close(fd3);
	close(fd4);
	
    return (0);
}