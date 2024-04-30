/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:59:52 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 15:44:54 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dir(t_env **env, t_cmd *cmd)
{
	t_arg	*curr_arg;
	char	*err_msg;
	char	*tmp;

	(void)env;
	curr_arg = cmd->first_arg;
	if (ft_strncmp(curr_arg->data, ".", 2) && opendir(curr_arg->data) == 0)
	{
		err_msg = ft_strjoin("/usr/bin/", cmd->data);
		tmp = ft_strjoin(err_msg, ": line 4: cd: ");
		free(err_msg);
		err_msg = ft_strjoin(tmp, curr_arg->data);
		return (perror(err_msg), free(err_msg), free(tmp), 1);
	}
	return (0);
}

void	set_parent_pipes(t_exe *data, int i)
{
	if (i > 0)
	{
		if (i == data->no_pipes)
			close_pipes(data, BOTH_PIPES);
		else if (i % 2 == 0)
		{
			close_pipes(data, PIPE_A);
			open_pipes(data, PIPE_A);
		}
		else
		{
			close_pipes(data, PIPE_B);
			open_pipes(data, PIPE_B);
		}
	}
}

char	*update_value(t_env *curr_env, char *temp, char *slash)
{
	int		old_val;
	char	*new_val;

	if (!ft_strncmp(curr_env->name, "SHLVL", 6) && slash \
		&& !ft_strncmp(slash, "/minishell", 11))
	{
		if (curr_env->value)
		{
			old_val = ft_atoi(curr_env->value);
			new_val = ft_itoa(old_val + 1);
		}
		else
			new_val = ft_strdup("1");
		strjoin_andfree(&temp, new_val);
	}
	else if (curr_env->value)
	{
		new_val = ft_strjoin(temp, curr_env->value);
		free(temp);
		return (new_val);
	}
	return (temp);
}

void	verify_cmd(t_token *curr_cmd, t_env **env)
{
	int	exit_code;

	if (!curr_cmd || curr_cmd->class == ARG)
		exit (0);
	if (curr_cmd->class == BUILT_IN)
	{
		exit_code = exec_bi(env, curr_cmd);
		exit (exit_code);
	}
}

int	all_vars(t_token **lst_token)
{
	int		first_type;
	t_token	*curr;

	curr = *lst_token;
	first_type = curr->class;
	while (curr && curr->class == first_type)
		curr = curr->next;
	if (!curr)
		return (1);
	*lst_token = curr;
	return (0);
}
