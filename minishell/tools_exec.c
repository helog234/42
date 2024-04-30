/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:03:16 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 16:57:09 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_no_pipe(t_token *lst_token)
{
	int		n;
	t_token	*curr;
	t_redir	*type_redir;

	curr = lst_token;
	n = 0;
	while (curr)
	{
		if (curr->class == REDIR)
		{
			type_redir = curr->type;
			if (ft_strncmp(type_redir->data, "|", 2) == 0)
				n++;
		}
		curr = curr->next;
	}
	return (n);
}

int	open_pipes(t_exe *data, int flag)
{
	if (flag == PIPE_A || flag == BOTH_PIPES)
	{
		if (pipe(data->fd_pipe_a) == -1)
			return (ft_putstr_fd("minishell: error openning pipe", 2), 0);
	}
	if (flag == PIPE_B || flag == BOTH_PIPES)
	{
		if (pipe(data->fd_pipe_b) == -1)
			return (ft_putstr_fd("minishell: error openning pipe", 2), 0);
	}
	return (1);
}

char	*form_err_msg(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*err_msg;

	tmp = ft_strjoin(s1, s2);
	if (s3)
		err_msg = ft_strjoin(tmp, s3);
	else
		err_msg = ft_strdup(tmp);
	return (free(tmp), err_msg);
}

void	update_last_cmd(t_env **env, char *val)
{
	t_env	*curr;

	curr = find_var(*env, 0, "_");
	update_variable(&curr, 0, val, EXPORT_FLAG);
}

char	*get_last_cmd(t_token *lst)
{
	t_token	*curr_tok;
	t_cmd	*curr_cmd;

	curr_tok = lst;
	curr_cmd = NULL;
	while (1)
	{
		if (curr_tok->class == REDIR && is_pipe(curr_tok))
			return (NULL);
		if (curr_tok->class == CMD)
			curr_cmd = curr_tok->type;
		if (!curr_tok->next)
			break ;
		curr_tok = curr_tok->next;
	}
	if (curr_cmd)
		return (find_last_arg(curr_cmd));
	return ("error: no command found, function: get_last_cmd");
}
