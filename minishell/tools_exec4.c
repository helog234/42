/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:09:54 by thajak            #+#    #+#             */
/*   Updated: 2024/04/26 19:55:54 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*verifications(char **slash, t_token *curr_cmd, t_env **env)
{
	t_cmd	*cmd;

	verify_cmd(curr_cmd, env);
	cmd = curr_cmd->type;
	if (cmd->path_to_cmd)
		*slash = ft_strrchr(cmd->path_to_cmd, '/');
	else
		*slash = ft_strrchr(cmd->data, '/');
	verify_msh(cmd, *slash);
	return (cmd);
}

void	handle_exit_error(char *arg, int *exit_code)
{
	char	*error_msg;

	error_msg = form_err_msg("minishell: ", arg, \
	": numeric argument required\n");
	ft_putstr_fd(error_msg, 2);
	free(error_msg);
	*exit_code = 255;
}

char	*find_last_arg(t_cmd *cmd)
{
	t_arg	*arg;

	arg = cmd->first_arg;
	if (arg)
	{
		while (arg->next)
			arg = arg->next;
		return (arg->data);
	}
	return (cmd->data);
}
