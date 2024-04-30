/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:05:51 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/26 14:19:49 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cd(t_env **env, t_token cmd_cd)
{
	t_cmd	*cd;
	t_env	*var;
	t_arg	*cd_arg;

	cd = cmd_cd.type;
	cd_arg = cd->first_arg;
	if (!cd_arg || !ft_strncmp(cd_arg->data, "~", 2))
	{
		var = find_var(*env, 0, "HOME");
		if (!var)
			return (update_last_cmd(env, cd->data), \
			ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
		return (update_last_cmd(env, cd->data), change_dir(env, var->value));
	}
	else if (!ft_strncmp(cd_arg->data, "-", 2))
	{
		var = find_var(*env, 0, "OLDPWD");
		if (!var->value)
			return (update_last_cmd(env, cd_arg->data), \
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), 1);
		printf("%s\n", var->value);
		return (update_last_cmd(env, cd_arg->data), \
		change_dir(env, var->value));
	}
	return (update_last_cmd(env, cd_arg->data), change_dir(env, cd_arg->data));
}

// if cd command is written with one or more capital letters, 
// everything is executed the same, but no chdir is actually done
int	exec_demi_cd(t_env **env, t_token cmd_cd)
{
	t_cmd	*cd;
	t_env	*var;
	t_arg	*cd_arg;

	cd = cmd_cd.type;
	cd_arg = cd->first_arg;
	if (!cd_arg)
	{
		var = find_var(*env, 0, "HOME");
		if (!var)
			return (update_last_cmd(env, cd->data), \
			ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
		return (update_last_cmd(env, cd->data), 0);
	}
	else if (!ft_strncmp(cd_arg->data, "-", 2))
	{
		var = find_var(*env, 0, "OLDPWD");
		if (!var->value)
			return (update_last_cmd(env, cd_arg->data), \
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), 1);
		printf("%s\n", var->value);
		return (update_last_cmd(env, cd_arg->data), 0);
	}
	return (update_last_cmd(env, cd_arg->data), check_dir(env, cd));
}

int	change_dir(t_env **env, char *new_path)
{
	char	*oldpwd;
	t_env	*curr_var;
	char	*err_msg;

	oldpwd = getcwd(NULL, 0);
	if (ft_strncmp(new_path, ".", 2) && chdir(new_path) < 0)
	{
		err_msg = ft_strjoin("minishell : cd: ", new_path);
		return (perror(err_msg), free(err_msg), free(oldpwd), 1);
	}
	curr_var = find_var(*env, 0, "PWD");
	if (curr_var && curr_var->value)
		free(curr_var->value);
	curr_var->value = getcwd(NULL, 0);
	curr_var = find_var(*env, 0, "OLDPWD");
	if (curr_var->value)
		free(curr_var->value);
	curr_var->value = oldpwd;
	curr_var->equal_flag = EQUAL_FLAG;
	return (0);
}

void	exec_pwd(t_env **env, t_token cmd_pwd)
{
	char	*pwd;
	t_cmd	*c_pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	pwd = NULL;
	c_pwd = cmd_pwd.type;
	if (!c_pwd->first_arg)
		update_last_cmd(env, c_pwd->data);
	else
	{
		while (c_pwd->first_arg->next)
			c_pwd->first_arg = c_pwd->first_arg->next;
		update_last_cmd(env, c_pwd->first_arg->data);
	}
}
