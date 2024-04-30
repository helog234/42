/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:45:35 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 17:54:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_path(t_env *env, char *cmd)
{
	char	**env_paths;
	char	*path;

	while (env)
	{
		if (ft_strncmp(env->name, "PATH", 4) == 0)
		{
			env_paths = ft_split(env->value, ':');
			if (env_paths == NULL)
				return (NULL);
			path = get_path(cmd, env_paths);
			return (path);
		}
		env = env->next;
	}
	return (NULL);
}

char	*get_path(char *cmd, char *env_paths[])
{
	int		i;
	char	*path;

	i = 0;
	while (env_paths[i] != NULL)
	{
		if (ft_strstr(env_paths[i], cmd) == 0)
		{
			path = form_err_msg(env_paths[i], "/", cmd);
			if (access(path, F_OK | X_OK) == 0)
			{
				free_paths(env_paths);
				return (path);
			}
			free(path);
		}
		i++;
	}
	free_paths(env_paths);
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

void	free_paths(char **all)
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
