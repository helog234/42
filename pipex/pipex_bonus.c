/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:38:39 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/11 11:10:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "pipex.h"
#include "gnl/get_next_line_bonus.h"
#include <fcntl.h>

void	execute(char *argv, char *envp[])
{
	char	**cmd_split;
	char	**env_paths;
	char	*path;

	cmd_split = ft_split(argv, ' ');
	if (cmd_split == NULL)
		error_message(4);
	env_paths = get_env_path(envp);
	if (env_paths == NULL)
	{
		free(cmd_split);
		error_message(5);
	}
	path = get_path(cmd_split[0], env_paths);
	if (execve(path, cmd_split, envp) < 0)
	{
		free(cmd_split);
		free(env_paths);
		error_message(6);
	}
}

void	fork_process(char *argv, char *envp[], int *pipefd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		error_message(3);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
}

void	gnl_argv(char *argv[], int output)
{
	char	*line;
	int		control;

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

void	here_doc_process(int argc, char **argv, int *pipefd, int output)
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
		gnl_argv(argv, output);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		wait(NULL);
	}
	exit(EXIT_SUCCESS);
}

int	pipex(int argc, char *argv[], char *envp[], int i)
{
	int	fd_out;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		error_message(2);
	if (ft_strncmp(argv[1], "here_doc", 7) == 0)
	{
		i = 3;
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		here_doc_process(argc, argv, pipefd, fd_out);
	}
	else
	{
		i = 2;
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	while (i < argc - 2)
	{
		fork_process(argv[i], envp, pipefd);
		i++;
	}
	dup2(fd_out, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	int	fd_in;

	if (argc < 5)
		error_message(1);
	i = 0;
	fd_in = open(argv[1], O_RDONLY);
	dup2(fd_in, STDIN_FILENO);
	pipex(argc, argv, envp, i);
	return (0);
}
