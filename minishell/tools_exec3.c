/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:14:56 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 16:49:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_special_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (i);
	}
	return (-1);
}

void	handle_var_arg(char *function, char *data)
{
	char	*error_msg;
	char	*temp;

	temp = form_err_msg("minishell : ", function, ": `");
	error_msg = form_err_msg(temp, data, "\': not a valid identifier\n");
	ft_putstr_fd(error_msg, 2);
	free(temp);
	free(error_msg);
}

int	get_exit_code(int code)
{
	if (code < 0)
		return (get_exit_code(256 + code));
	if (code > 255)
		return (get_exit_code(code - 256));
	return (code);
}

bool	builtin_to_exec(t_token *lst_token)
{
	t_cmd	*builtin;

	if (lst_token && lst_token->class == BUILT_IN)
	{
		builtin = lst_token->type;
		if ((!get_no_pipe(lst_token) \
		&& ft_strncmp(builtin->data, "echo", 5)) \
		|| (!ft_strncmp(builtin->data, "echo", 5) && !lst_token->next))
			return (true);
	}
	return (false);
}

int	catch_error(int wstatus, t_token *lst_token, t_env **env)
{
	set_signals(lst_token, PARENT_WO_CHILD);
	update_last_cmd(env, get_last_cmd(lst_token));
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (printf("^C\n"), WTERMSIG(wstatus) + 128);
	return (0);
}
