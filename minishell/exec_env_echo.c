/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thajak <thajak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:30:39 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/26 11:37:16 by thajak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_env(t_env **env, t_token cmd_env)
{
	t_cmd	*c_env;
	char	*error_msg;

	c_env = cmd_env.type;
	while (c_env->first_arg && !ft_strncmp(c_env->first_arg->data, "env", 4))
		c_env->first_arg = c_env->first_arg->next;
	if (!c_env->first_arg)
	{
		update_last_cmd(env, "/usr/bin/env");
		return (print_env(env, 0), 0);
	}
	if (!ft_strncmp(c_env->first_arg->data, "cd", 3) \
		|| !ft_strncmp(c_env->first_arg->data, "echo", 5) \
		|| !ft_strncmp(c_env->first_arg->data, "pwd", 4))
		return (ft_putstr_fd("Naughty, naughty, env should be implemented \
		and tested without options or arguments :D\n", 2), 5);
	error_msg = form_err_msg("env: ", \
	c_env->first_arg->data, ": No such file or directory\n");
	ft_putstr_fd(error_msg, 2);
	free(error_msg);
	while (c_env->first_arg->next)
		c_env->first_arg = c_env->first_arg->next;
	return (update_last_cmd(env, c_env->first_arg->data), 127);
}

void	exec_echo(t_env **env, t_token cmd_echo)
{
	t_cmd	*echo;
	bool	newline;
	t_arg	*arg;

	echo = cmd_echo.type;
	newline = true;
	arg = echo->first_arg;
	if (!arg || !arg->data)
		return (printf("\n"), update_last_cmd(env, echo->data));
	if (!ft_strncmp(arg->data, "-n", 3))
		newline = false;
	while (arg)
	{
		if (arg->prev || (!arg->prev \
		&& ft_strncmp(arg->data, "-n", 3)))
			printf("%s", arg->data);
		if (!arg->next)
			break ;
		if (ft_strncmp(arg->data, "-n", 3))
			printf(" ");
		arg = arg->next;
	}
	update_last_cmd(env, arg->data);
	if (newline)
		printf("\n");
}
