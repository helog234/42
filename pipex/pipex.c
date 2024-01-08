/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:21:55 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/08 15:06:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//attendre que le dernier child ai termine pour renvoye pour statut
int	wait_last(int last_pid)
{
	int	status;
	int	pid;

	while (1)
	{
		pid = waitpid(-1, &status, WNOHANG);
		// if (pid == -1)
		// 	break ;
		// else if (pid == last_pid)
		if (pid == last_pid)
			return (WEXITSTATUS(status));
	}
	// return (42);
}

//recherche le path et l'environnement puis executer
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

// fork process: check si child (==0) et une fois dedans 
//check la condition de l'argv
// en fonction de ces conditions, dup des fils differents 
//car au debut lit de infile 
//(remplace par temp) et ecrit dans pipe
// et ensuite lit et ecrit dans les pipe
//qu'importe les condition au dessu, ensuite on execute
void	fork_process(char *argv, char *envp[], t_fd *fd, int i)
{
	fd->pid = fork();
	if (fd->pid < 0)
		error_message(3);
	if (fd->pid == 0)
	{
		if (i == 2)
		{	
			dup2(fd->tmp, 0);
			dup2(fd->pipe[1], 1);
			close(fd->tmp);
		}
		else
		{
			dup2(fd->pipe[0], 0);
			dup2(fd->out_file, 1);
			close(fd->out_file);
		}
		(void)close(fd->pipe[0]);
		(void)close(fd->pipe[1]);
		execute(argv, envp);
	}
	close(fd->pipe[1]);
}

//ouverture des fichiers, initialisation du pipe et iteration de fork process
int	pipex(int argc, char *argv[], char *envp[])
{
	t_fd	fd;
	int		i;

	i = 1;
	if (pipe(fd.pipe) == -1)
		error_message(2);
	fd.tmp = open(argv[1], O_RDONLY);
	fd.out_file = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd.tmp == -1 || fd.out_file == -1)
		error_message(1);
	while (++i < argc - 1)
	{
		fork_process(argv[i], envp, &fd, i);
	}
	(void)close(fd.tmp);
	(void)close(fd.out_file);
	(void)close(fd.pipe[0]);
	return (wait_last(fd.pid));
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		error_message(1);
	return (pipex(argc, argv, envp));
}
