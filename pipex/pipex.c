/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:38:39 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/07 15:19:30 by hgandar          ###   ########.fr       */
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

char	**get_env_path(char *envp[])
{
	int		i;
	char	**env_paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], "PATH") != 0)
		{
			env_paths = ft_split(ft_strstr(envp[i], "PATH"), ':');
			if (env_paths == NULL)
				error_message(8);
			return (env_paths);
		}
		i++;
	}
	error_message(8);
	return (NULL);
}

char	*get_path(char *cmd, char *env_paths[])
{
	int		i;
	//char	**exec;
	char	*path;

	i = 0;
	/* exec = ft_split(cmd, ' ');
	if (exec == NULL)
	{
		error_message(7);
		free_all(exec);
	} */
	while (env_paths[i] != NULL)
	{
		//if (ft_strncmp(env_paths[i], exec[0], ft_strlen(exec[0])) == 0)
		if (ft_strstr(env_paths[i], cmd) == 0)
		{
			path = ft_strjoin(env_paths[i], "/");
			path = ft_strjoin(path, cmd);
			if (access(path, F_OK | X_OK) == 0)
			{
				//free(exec);
				//free_all(env_paths);
				return (path);
			}
			//free(path);
		}
		i++;
	}
	//free(exec);
	//free_all(env_paths);
	error_message(9);
	return (NULL);
}

void	child_process(int input_fd, int output_fd, char *argv, char *envp[])
{
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	execute(argv, envp);
}

void	create_pipe(int argc, char *argv[], char *envp[], int fd)
{
	int	pipefd[2];
	int	pid;
	int	i;

	dup2(fd, STDIN_FILENO);
	if (pipe(pipefd) == -1)
		error_message(2);
	i = 2;
	while (i < argc - 2)
	{
		pid = fork();
		if (pid < 0)
			error_message(3);
		if (pid == 0)
		{
			close(pipefd[0]);
			child_process(fd, pipefd[1], argv[i], envp);
		}
		else
		{
			close(pipefd[1]);
			fd = pipefd[0];
		}
		i++;
	}
	
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	//int	i;

	//i = 0;
	if (argc < 5)
		error_message(1);
	/* if (i == 0)
	{ */
		//i = 2;
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	dup2(fd_in, STDIN_FILENO);
	
/* 	if (ft_strncmp(argv[1], "here_doc", 7))
	{
		i = 
	} 
	if (i == 0)
	{
	i = 2;*/
	create_pipe(argc, argv, envp, fd_in);
	dup2(fd_out, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (EXIT_SUCCESS);
}
