/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:04:02 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/14 07:49:56 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

char	*set_stock(char *stock, int i, int j)
{
	unsigned int	k;
	char			*new_stock;

	k = 0;
	new_stock = ft_substr_l(stock, i + 1, j, k);
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
		line = ft_substr_l(stock, 0, i + 1, k);
	else
		line = ft_substr_l(stock, 0, j + 1, k);
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
		stock = ft_strjoin_l(stock, buffer);
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

char	*get_next_line(int fd, char *line, int i)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stock[FD_MAX];
	int			j;

	i = 0;
	j = 0;
	if (stock[fd] == NULL || fd == -1 || fd >= FD_MAX)
		stock[fd] = init(stock[fd], fd);
	ft_putstr_fd("pipe heredoc> ", STDIN_FILENO);//change avant = stout
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

/*  #include <fcntl.h>
#include <stdio.h>
int main(void)
{
   	int fd[4];
    char *line;

    line = NULL;
    fd[0] = open("text_short.txt", O_RDONLY);
    fd[1] = open("text.txt", O_RDONLY);
	fd[2] = open("line_around_10.txt", O_RDONLY);
	fd[3] = open("giant_line_nl.txt", O_RDONLY);
	
	int fileIndex = 0;
    int fileFinished[4] = {0}; 
    while (1)
    {
        if (fileFinished[fileIndex])
        {
            printf("NULL\n");
        }
        else
        {
            line = get_next_line(fd[fileIndex]);
            if (line != NULL)
            {
                printf("%s\n", line);
                free(line);
            }
            else
            {
                printf("NULL\n");
                fileFinished[fileIndex] = 1;
            }
        }
        fileIndex = (fileIndex + 1) % 4;
        int allFilesFinished = 1;
        for (int i = 0; i < 4; ++i)
        {
            if (!fileFinished[i])
            {
                allFilesFinished = 0;
                break;
            }
        }

        if (allFilesFinished)
        {
            break; 
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        close(fd[i]);
    }
 
    return (0);
} */