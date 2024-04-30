/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:37:33 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/27 17:26:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"

void	get_previous_cmd(t_env *env, char **str)
{
	char	*tmp;

	tmp = env_last_cmd(env);
	if (tmp)
	{
		free(*str);
		*str = ft_strdup(tmp);
	}
}

char	*env_last_cmd(t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->name, "_", 2) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*env_found(char *str, t_env *env)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(env->value);
	if (!tmp)
		return (NULL);
	if (ft_strlen(str) > ft_strlen(env->name))
	{
		tmp2 = ft_strdup(str + ft_strlen(env->name));
		if (!tmp2)
			return (NULL);
		strjoin_andfree(&tmp, tmp2);
		return (tmp);
	}
	return (tmp);
}

char	*dollar_expansion(char *str, t_env *env)
{
	char	*tmp;

	while (env)
	{
		if (env->name && env->value && \
		ft_strncmp(env->name, str, ft_strlen(env->name)) == 0)
		{
			if (str[ft_strlen(env->name)] == '/')
			{
				tmp = ft_substr(str, ft_strlen(env->name), \
				ft_strlen(str) - ft_strlen(env->name));
				tmp = ft_strdup(tmp);
				free(str);
				str = ft_strjoin(env->value, tmp);
				free(tmp);
				tmp = NULL;
				return (str);
			}
			return(env_found(str, env));
		}
		env = env->next;
	}
	return (NULL);
}

void	manage_special_dollar(char *var_name, char *old_str, \
char **str, t_clean *utils)
{
	if (var_name && ft_strncmp(var_name, "?", 2) == 0)
	{
		ft_put_nbr(utils->exit_status, str, old_str);
		free(var_name);
		return ;
	}
	else if (is_separator(var_name[0]))
	{
		free(old_str);
		return ;
	}
	else if (var_name && is_special_dollar(var_name, utils) != false)
		return ;
	free (old_str);
	free(var_name);
}

void	handle_dollar(char **str, t_env *env, int start, t_clean *utils)
{
	char	*var_name;
	char	*tmp;
	char	*old_str;
	int		len;

	var_name = NULL;
	old_str = NULL;
	len = utils->j - start;
	if (ft_strlen(*str) >= 1)
	{
		old_str = ft_substr(*str, 0, start - 1);
		var_name = ft_substr(*str, start, len);
	}
	if (var_name && ft_strncmp(var_name, "_", 2) == 0)
		get_previous_cmd(env, str);
	if (var_name && (ft_strncmp(var_name, "?", 2) == 0 || \
	is_separator(var_name[0]) || is_special_dollar(var_name, utils)))
		return (manage_special_dollar(var_name, old_str, str, utils));
	tmp = dollar_expansion(var_name, env);
	free(*str);
	*str = old_str;
	if (!tmp)
		return ;
	strjoin_andfree(str, tmp);
}
