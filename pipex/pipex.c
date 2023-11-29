/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:32 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/29 16:39:15 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "pipex.h"

char	**make_ls(char *argv[])
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

int	main(int argc, char *argv[])
{
	/* int		fd[2];
	int		pid1;
	int		pid2; */
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
	/* if (pipe(fd) == -1)
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
	waitpid(pid2, NULL, 0); */
	return (0);
}