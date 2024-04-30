/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exp_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:32:08 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/26 19:43:07 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_export(t_env **env, t_token cmd_export)
{
	t_cmd	*exp;

	exp = cmd_export.type;
	if (exp->first_arg)
		return ;
	print_env(env, EXPORT_FLAG);
	update_last_cmd(env, "export");
}

int	exec_var(t_env **env, t_token *lst_token)
{
	t_token	*curr;
	t_cmd	*curr_cmd;
	t_arg	*curr_arg;

	curr = lst_token;
	if (curr->class == ARG)
	{
		while (curr)
		{
			curr_arg = curr->type;
			handle_variable(env, curr_arg->data, NOT_EXPORTED);
			curr = curr->next;
		}
		return (update_last_cmd(env, ""), 0);
	}
	curr_cmd = curr->type;
	curr_arg = curr_cmd->first_arg;
	return (exported_var(curr_arg, env));
}

int	exported_var(t_arg *curr_arg, t_env **env)
{
	int		i;
	t_env	*variable;

	while (1)
	{
		i = has_special_char(curr_arg->data);
		if (!ft_isalpha(curr_arg->data[0]) || \
		(i >= 0 && curr_arg->data[i] != '='))
		{
			handle_var_arg("export", curr_arg->data);
			if (!curr_arg->next)
				return (update_last_cmd(env, curr_arg->data), 1);
		}
		i = 0;
		variable = find_var(*env, 0, get_substr(curr_arg->data, &i, ST_EQ));
		if (variable && curr_arg->data[i] != '=')
			update_variable(&variable, i, NULL, EXPORT_FLAG);
		else
			handle_variable(env, curr_arg->data, EXPORT_FLAG);
		if (!curr_arg->next)
			break ;
		curr_arg = curr_arg->next;
	}
	return (update_last_cmd(env, ft_strchr(curr_arg->data, '=')), 0);
}

int	exec_unset(t_env **env, t_arg *lst_var)
{
	t_arg	*curr_var;

	curr_var = lst_var;
	if (!curr_var)
		return (0);
	while (curr_var)
	{
		if (!ft_isalpha(curr_var->data[0]) || \
		has_special_char(curr_var->data) >= 0)
		{
			handle_var_arg("unset", curr_var->data);
			if (!curr_var->next)
				return (update_last_cmd(env, curr_var->data), 1);
		}
		else if (!ft_strncmp(curr_var->data, "PWD", 4))
			remove_exported_flag(env, "PWD");
		else if (!ft_strncmp(curr_var->data, "OLDPWD", 7))
			remove_exported_flag(env, "OLDPWD");
		lstremove(env, curr_var->data);
		if (!curr_var->next)
			break ;
		curr_var = curr_var->next;
	}
	return (update_last_cmd(env, curr_var->data), 0);
}

void	remove_exported_flag(t_env **env, char *var)
{
	t_env	*node_var;

	node_var = find_var(*env, 0, var);
	node_var->exported_flag = NOT_EXPORTED;
	if (node_var->value)
		free(node_var->value);
	node_var->value = NULL;
}
