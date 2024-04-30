/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 07:43:29 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 17:54:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"

void	load_history(char *path)
{
	int		fd_hist;
	char	*line;
	size_t	ctr;

	line = NULL;
	fd_hist = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd_hist == -1)
	{
		perror("open history.log failed1");
		return ;
	}
	line = get_next_line(fd_hist, 0);
	if (!line)
		return ;
	while (line)
	{
		ctr = 0;
		ctr = strlen(line);
		if (ctr > 0 && line[ctr - 1] == '\n')
			line[ctr - 1] = '\0';
		add_history(line);
		free(line);
		line = get_next_line(fd_hist, 0);
	}
	close(fd_hist);
}

void	history_log(char *line, char *path)
{
	int	fd_hist;

	add_history(line);
	fd_hist = open(path, O_CREAT | O_RDWR | O_APPEND, 0777);
	if (fd_hist == -1)
	{
		perror("open history.log failed2");
		return ;
	}
	ft_putstr_fd(line, fd_hist);
	ft_putstr_fd("\n", fd_hist);
	close(fd_hist);
}
