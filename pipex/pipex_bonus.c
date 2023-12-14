/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:38:39 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/14 09:56:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>

int	wait_last(int last_pid)
{
	int	status;
	int	pid;

	while (1)
	{
		pid = waitpid(-1, &status, WNOHANG);
		if (pid == -1)
			break ;
		else if (pid == last_pid)
			return (WEXITSTATUS(status));
	}
	return (42);
}

void	execute(char *argv, char *envp[])
{
	char	**cmd_split;
	char	**env_paths;
	char	*path;

	cmd_split = check_quote(argv);
	if (cmd_split == NULL)
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

int	fork_process(char *argv, char *envp[], int *pipefd)
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
	return (pid);
}


int	pipex(int argc, char *argv[], char *envp[], int i)
{
	int	fd_out;
	int	pipefd[2];
	int	last_pid;

	if (pipe(pipefd) == -1)
		error_message(2);
	if (ft_strncmp(argv[1], "here_doc", 7) == 0)
	{
		i = 3;
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		here_doc_process(argc, argv, pipefd);
	}
	else
	{
		i = 2;
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	dup2(fd_out, STDOUT_FILENO);
	while (i < argc - 1)
	{
		last_pid = fork_process(argv[i], envp, pipefd);
		i++;
	}
	i = wait_last(last_pid);
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
