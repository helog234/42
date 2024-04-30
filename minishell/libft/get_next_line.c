/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:38:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:54:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"

static char	*set_stock(char *stock, int i, int j)
{
	unsigned int	k;
	char			*new_stock;

	k = 0;
	new_stock = ft_substr_gnl(stock, i + 1, j, k);
	if (new_stock == NULL)
	{
		free(stock);
		return (NULL);
	}
	free(stock);
	return (new_stock);
}

char	*set_line(char *stock, char *line, int i, int j)
{
	unsigned int	k;

	k = 0;
	if (i >= 0)
		line = ft_substr_gnl(stock, 0, i + 1, k);
	else
		line = ft_substr_gnl(stock, 0, j, k);
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

char	*fill_line_buffer(int fd, char *stock, char *buffer, int flag)
{
	int				i;
	int				control;
	struct termios	original_term;

	i = 1;
	control = 0;
	if (flag == 1)
		ft_putstr_fd("> ", STDOUT_FILENO);
	tcgetattr(STDIN_FILENO, &original_term);
	while (i > 0)
	{
		if (control && flag)
			ignore_ctrld(&original_term);
		i = read(fd, buffer, BUFFER_SIZE);
		restore_ctrld(&original_term);
		if (i == -1)
			return (free_str(stock), NULL);
		control = control_gnl(&stock, buffer, i);
		if (control > 0)
			return (stock);
		else if (!control)
			return (NULL);
		control = i;
	}
	return (stock);
}

char	*get_next_line(int fd, int flag)
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
	stock = fill_line_buffer(fd, stock, buffer, flag);
	if (stock == NULL)
		return (NULL);
	i = ft_strchr_line(stock, '\n');
	j = ft_strlen_gnl(stock);
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
/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*line;
	
	//line = NULL;
    fd = open("map1.ber", O_RDONLY);
	//line = get_next_line(fd);
	//printf("%s", line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
} */