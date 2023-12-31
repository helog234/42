/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:38:39 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/14 19:03:50 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdbool.h>

int	wait_last(int last_pid)
{
	int	status;
	int	pid;
	int	value;

	value = 0;
	while (1)
	{
		pid = waitpid(-1, &status, WNOHANG);
		if (pid == -1)
			break ;
		else if (pid == last_pid)
			value = (WEXITSTATUS(status));
	}
	return (value);
}
//checker si un argument contien des quotes et parser les commandes en consequences
//sinon spliter les commandes en espace (split espace)
//recherche le path et l'environnement puis executer
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
// fork process: check si child (==0) et une fois dedans check la condition de l'argv
// en fonction de ces conditions, dup des fils differents car au debut lit de infile (remplace par temp) et ecrit dans pipe
// et ensuite lit et ecrit dans les pipe
//qu'importe les condition au dessu, ensuite on execute
void	fork_process(char *argv, char *envp[], t_fd *fd, bool option)
{
	if (pipe(fd->pipe) == -1)
		error_message(2);
	fd->pid = fork();
	if (fd->pid < 0)
		error_message(3);
	if (fd->pid == 0)
	{
		dup2(fd->tmp, 0);
		close(fd->tmp);
		if (option == true)
		{
			dup2(fd->pipe[1], 1);
			close(fd->pipe[1]);
		}
		else
		{
			dup2(fd->out_file, 1);
			close(fd->out_file);
		}
		execute(argv, envp);
	}
	close(fd->tmp);
	fd->tmp = fd->pipe[0];
	close(fd->pipe[1]);
}
// checker si le 2e argument et here_doc et si oui agir en fonction
//le true ou fals pourrait juste etre remplace par le i en checkant sa valeur
int	pipex(int argc, char *argv[], char *envp[])
{
	int		i;
	t_fd	fd;

	fd.tmp = open(argv[1], O_RDONLY);
	if (ft_strncmp(argv[1], "here_doc", 7) == 0)
	{
		i = 3;
		fd.out_file = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		here_doc_process(argc, argv, &fd);
	}
	else
	{
		i = 2;
		fd.out_file = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	while (i < argc - 1)
	{
		if (i != argc - 2)
			fork_process(argv[i], envp, &fd, true);
		else
			fork_process(argv[i], envp, &fd, false);
		i++;
	}
	close(fd.out_file);
	return (wait_last(fd.pid));
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		error_message(1);
	return (pipex(argc, argv, envp));
}
