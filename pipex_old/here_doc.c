/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:59:47 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/14 09:29:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>

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
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			control = 0;
			free(line);
			break ;
		}
		ft_putstr_fd(line, output);
		free(line);
	}
}

void	here_doc_process(int argc, char **argv, int *pipefd)
{
	int		pid;

	if (argc < 6)
		error_message(1);
	if (pipe(pipefd) == -1)
		error_message(2);
	pid = fork();
	if (pid < 0)
		error_message(3);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		gnl_argv(argv, pipefd[1]);
		close(pipefd[1]);//ajout
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		wait(NULL);
	}
}
