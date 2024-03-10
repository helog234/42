/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:31:55 by hgandar           #+#    #+#             */
/*   Updated: 2024/03/10 16:40:44 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *buffer, char c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	cpy = malloc((j + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_strjoin(const char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = malloc((i + j + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*sub;
	int		i;

	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}

char	*read_line(int fd, char *stock, char *buffer)
{
	int	i;
	int	control;

	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = 0;
		if (stock == NULL)
			stock = ft_strdup("");
		stock = ft_strjoin(stock, buffer);
		if (stock == NULL)
			return (NULL);
		control = ft_strchr(stock, '\n');
		if (control > 0)
			return (stock);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stock;
	char		*line;
	int			control;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stock = read_line(fd, stock, buffer);
	if (stock == NULL)
		return (NULL);
	if (stock && (control = ft_strchr(stock, '\n')) > 0)
	{
		line = ft_substr(stock, 0, control + 1);
		stock = ft_substr(stock, control + 1, ft_strlen(stock) - control);
	}
	if (stock && *stock == 0)
	{
		line = ft_strdup(stock);
		free(stock);
		stock = NULL;
	}
	return (line);
}

/* static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	length;
	size_t	i;

	length = ft_strlen(s1);
	if (!(copy = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(joined = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		joined[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		joined[s1_len + i] = s2[i];
	joined[s1_len + s2_len] = '\0';
	return (joined);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char		*temp;
	char		*line;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (rest == NULL)
			rest = ft_strdup("");
		temp = ft_strjoin(rest, buffer);
		free(rest);
		rest = temp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	if (bytes_read < 0 || (bytes_read == 0 && (rest == NULL || *rest == '\0')))
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	line = ft_substr(rest, 0, i + (rest[i] == '\n' ? 1 : 0));
	temp = ft_strdup(rest + i + (rest[i] == '\n' ? 1 : 0));
	free(rest);
	rest = temp;
	return (line);
} */




#include <fcntl.h>
int	main(void)
{
	int	fd;
	char	*line;
	
	//line = NULL;
    fd = open("ex.txt", O_RDONLY);
	//line = get_next_line(fd);
	//printf("%s", line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
