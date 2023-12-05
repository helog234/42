/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_eric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:32 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/05 16:45:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "pipex.h"
#include <fcntl.h>

char	**get_env_paths(char *envp[])
{
	int		i;
	char	**env_paths;
	
	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], "PATH") != 0)
		{
			env_paths = ft_split(ft_strstr(envp[0], "PATH"), ':');
			return (env_paths);
		}
		i++;
		// trouver un moyen pour itérer dans toute la commande "ls -l par exemple"
	}
	return (NULL);
}
char	*get_path(char *argv, char *envp[])
{
	int		i;
	char	**env_paths;
	char 	**cmd_split;
	i = 0;
	env_paths = get_env_paths(envp);
	cmd_split = ft_split(argv, ' ');
	if (env_paths == NULL || cmd_split == NULL)
	{
		//ajouter fonction de free selon si pas NULL
		return (NULL);
	}
	while (env_paths[i] != NULL)
	{
		if (ft_strstr(env_paths[i], cmd_split[i]) != NULL)
			return (env_paths[i]);
		i++;
	}
	return (NULL);
}

int	child_process(int input_fd, int output_fd, char *argv, char *envp[])
{
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(input_fd);
	close(output_fd);
	if (execve(get_path(argv, envp), argv, envp) < 0)
		return (3);
}

void	create_pipes(char *argv, char *envp[], int fd)
{
	int	pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0)
	{
		close(pipefd[0]);
		child_process(fd, pipefd[1], argv, envp);
	}
	else
	{
		close(pipefd[1]);
		close(fd);
		fd = pipefd[0]
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd;
	int	i;

	if (argc < 5)
	{
		// a changer avec ma fonction
		ft_printf("Not enough arguments");
		return (0);
	}
	if (ft_strncmp(argv[1], "here_doc", 7))
	{
		i = 
	}
	else
	{
		i = 2;
		fd = open(argv[1], O_RDONLY);
		dup2(fd, STDIN_FILENO);
	}
	while (i < argc - 1)
	{
		create_pipes(argv[i], envp, fd);
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