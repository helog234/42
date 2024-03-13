/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:23:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/03/13 21:53:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = 0;
	free(s1);
	return (new);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*read_line(int fd, char *stock, char *buff)
{
	int	control;
	int	i;

	i = 1;
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = 0;
		if (stock == NULL)
			stock = ft_strdup("");
		stock = ft_strjoin(stock, buff);
		control = ft_strchr(stock, '\n');
		if (control > 0)
		{
			//printf("stock : %s control %i\n", stock, control);
			return (stock);
		}
	}
	return (stock);
}

char	*ft_strsub(char *str, int start, int len)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = str[start];
		start++;
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stock;
	char		*line;
	int			control;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	control = 0;
	line = NULL;
	stock = read_line(fd, stock, buff);
	if (stock == NULL)
		return (NULL);
	if ((control = ft_strchr(stock, '\n')) >= 0)
	{
		line = ft_strsub(stock, 0, control + 1);
		stock = ft_strsub(stock, control + 1, ft_strlen(stock) - control);
	}
	else if ((*stock || stock == NULL) && line == NULL)
	{
		line = ft_strdup(stock);
		free(stock);
		stock = NULL;
	}
	return (line);
}

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("ex.txt", O_RDONLY);
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
