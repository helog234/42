/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:32 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/01 17:29:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "pipex.h"
#include <fcntl.h>

int	**create_pipes(char *argv, char *envp[])
{
	int	*pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		if (execve(get_path, &argv[3], get_env) < 0)
			return (3);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
	}
	return (pipes);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc < 5)
	{
		// a changer avec ma fonction
		ft_printf("Not enough arguments");
		return (0);
	}
	else if (ft_strncmp(argv[1], "here_doc", 7))
	{
		i = 
	}
	else
	{
		i = 2;
		fd_in = open(argv[1], O_RDONLY);
		fd_out = open(argv[argc - 1], O_WRONLY);
		dup2(fd_in, 0);
	}
	while (i < argc)
	{
		create_pipes(argv[i]);
		i++;
	}
	
	
}
/* char	**make_ls(char *argv[])
{
	int		i;
	int		j;
	int		k;
	char	**arg_env;

	i = 2;
	j = 0;
	k = ft_strlen(argv[i]);
	arg_env = malloc((k) * sizeof (char *));
	if (arg_env == NULL)
		return (NULL);
	while (argv[i])
	{
		arg_env[j] = ft_strdup(argv[i]);
		j++;
		i++;
	}
	arg_env[j] = NULL;
	return (arg_env);
}

char	*get_path(int *i, char *argv)
{
	int		i;
	char	**ls_command;
	char	path;

	i = 2;

	while (argv[i] != NULL)
	{
		ls_command = ft_split(argv[i], ' ')
		path = 
	}
	
}

int	execute(int **pipes, int argc, char *argv[], char *envp[])
{
	int i;
	int	pids[argc];

	i = 0;
	while (i < argc)
	{
		pids[i] = fork();
		if (pids[i] < 0)
			return (2);
		if (pids[i] == 0)
		{
			dup2(pids[1], STDOUT_FILENO);
			if (execve(get_path(pids[1], argv), pids[i], envp) < 0)
				return (3);
		}
	}
	
	
}

int	**create_pipes(int argc)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes[argc][2];
	while (i < argc)
	{
		if (pipe(pipes[i]) == -1)
			return (1);
		i++;
	}
	pipes[i] = NULL;
	return (pipes);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		**pipes;
	char	*path;

	i = 0;
	path = 0;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	pipes = create_pipes(argc);
	execute(pipes, argc, argv, envp);
	if (envp == NULL)
		return (NULL);
} */

/*int	main(int argc, char *argv[])
{
	int		i;
	int		fd[i][2];
	int		pid1;
	int		pid2;
	char	**arg_env;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[2])
		arg_env = make_ls(argv[2]);
	if (arg_env == NULL)
		return (NULL);
	 if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(argv[2], &argv[3], arg_env) < 0)
			return (3);
	}
	pid2 = fork();
	if (pid1 < 0)
		return (3);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		if (execve(argv[2], &argv[3], arg_env) < 0)
			return (3);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0); 
	return (0);
}*/