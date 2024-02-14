/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:59:47 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/08 18:12:55 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	gnl_argv(char *argv[], int output)
{
	char	*line;
	int		control;

	(void)output;
	line = NULL;
	control = 1;
	while (control != 0)
	{
		line = get_next_line(STDIN_FILENO, line, control);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0 && \
			argv[2][ft_strlen(argv[2] + 1)] != '\n')
		{
			control = 0;
			free(line);
			break ;
		}
		ft_putstr_fd(line, output);
		free(line);
	}
}

void	here_doc_process(int argc, char **argv, t_fd *fd)
{
	int		pid;

	if (argc < 6)
		error_message(1);
	if (pipe(fd->pipe) == -1)
		error_message(2);
	pid = fork();
	if (pid < 0)
		error_message(3);
	if (pid == 0)
	{
		close(fd->pipe[0]);
		gnl_argv(argv, fd->pipe[1]);
		close(fd->pipe[1]);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
	close(fd->tmp);
	fd->tmp = fd->pipe[0];
	close(fd->pipe[1]);
}
