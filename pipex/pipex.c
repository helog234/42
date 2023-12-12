/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:21:55 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/12 08:33:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "pipex.h"
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

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	int	pipefd[2];

	if (argc < 5)
		error_message(1);
	fd_in = open(argv[1], O_RDONLY);
	dup2(fd_in, STDIN_FILENO);
	if (pipe(pipefd) == -1)
		error_message(2);
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fork_process(argv[2], envp, pipefd);
	dup2(fd_out, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (EXIT_SUCCESS);
}
