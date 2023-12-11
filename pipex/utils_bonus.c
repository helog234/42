/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:50 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/11 17:19:19 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>


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
	char	*path;
	//char	*str;

	i = 0;
	while (env_paths[i] != NULL)
	{
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
//pas printf malheureusment
 /*   if (errno == ENOENT) {
        fprintf(stderr, "pipex: command not found: %s\n", cmd);
    } else {
        // For other errors, print a generic message with strerror
        fprintf(stderr, "Error: Pipex standard stream - %s\n", strerror(errno));
    } */
	exit(0);
	return (NULL);
}

char	*ft_strstr(const char *hstack, const char *needle)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (needle[i] == 0 || needle[j] == 0)
		return ((char *)hstack);
	if (hstack == NULL)
		return (NULL);
	while (hstack[i])
	{
		j = 0;
		while (needle[j] && needle[j] == hstack[i + j])
			j++;
		if (needle[j] == 0)
			return ((char *)&hstack[i]);
		i++;
	}
	return (0);
}

void	free_all(char **all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all[i])
		i++;
	while (j < i)
	{
		free(all[j]);
		j++;
	}
	free(all);
}

void	error_message(int flag)
{
	if (flag == 1)
		perror("Not enough arguments\n");
	else if (flag == 2)
		perror("Could not create pipe\n");
	else if (flag == 3)
		perror("Could not fork\n");
	else if (flag == 4)
		perror("Error splitting the command\n");
	else if (flag == 5 || flag == 8)
		perror("Error getting env path\n");
	else if (flag == 6)
		perror("Error getting execute");
	else if (flag == 7)
		perror("Error getting exec split");
	exit(EXIT_FAILURE);
}
