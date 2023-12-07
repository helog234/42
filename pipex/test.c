
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <string.h> 

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
				perror("in env_path");
			return (env_paths);
		}
		i++;
	}
	perror("in env_path2");
	return (NULL);
}

char	*get_path(char *cmd, char *env_paths[])
{
	int		i;
	//char	**exec;
	char	*path;

	i = 0;
	//exec = ft_split(cmd, ' ');
	/* if (exec == NULL)
	{
		perror("error in split");
		free_all(exec);
	}*/
	while (env_paths[i] != NULL)
	{
		//if (ft_strncmp(env_paths[i], exec[0], ft_strlen(exec[0])) == 0)
		if (ft_strstr(env_paths[i], cmd) == 0)
		{
			path = ft_strjoin(env_paths[i], "/");
			path = ft_strjoin(path, cmd);
			if (access(path, F_OK | X_OK))
			{
				free(cmd);
				free_all(env_paths);
				return (path);
			}
			//free(path);
		}
		i++;
	}
	//free(exec);
	free_all(env_paths);
	perror("not found path");
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	int j;
	char	**cmd_split;
	char	**env_paths;
	char	*path;

	i = 2;
	j = 0;
	(void)envp;
	while (i < argc -1)
	{
		cmd_split = ft_split(argv[i], ' ');
		printf("cmd_split: %s\n", cmd_split[j]);
		if (cmd_split == NULL)
			perror("sorry");
		i++;
		j++;
	}
	i = 0;
	env_paths = get_env_path(envp);
/* 	while (env_paths[i])
	{
		printf("env PATH: %s\n", env_paths[i]);
		i++;
	} */
	
 	if (env_paths == NULL)
	{
		free(cmd_split);
		perror("sorry2");
	}
	path = get_path(cmd_split[0], env_paths);
	printf("PATH: %s\n", path);
	return (0);
}