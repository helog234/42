/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:32 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/28 15:52:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int		fd[2];
	int		pid1;
	int		pid2;
	char	**arg_env;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	arg_env = NULL;
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
}