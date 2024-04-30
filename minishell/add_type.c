/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:56:53 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:57:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*add_arg(char *str, t_token *token)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (arg == NULL)
		errors(token, 15);
	if (is_flag(str, token))
		arg->flag = true;
	else
		arg->flag = false;
	token->class = ARG;
	arg->next = NULL;
	arg->prev = NULL;
	arg->data = NULL;
	return (arg);
}

t_cmd	*add_cmd(t_token *token, t_cmd	*cmd)
{
	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		errors(token, 15);
	cmd->fd = 0;
	cmd->path_to_cmd = NULL;
	cmd->first_arg = NULL;
	cmd->data = NULL;
	return (cmd);
}

t_redir	*add_redir(t_token *token, t_redir *redir)
{
	redir = malloc(sizeof(t_redir));
	if (redir == NULL)
		errors(token, 15);
	redir->fd_in = 0;
	redir->fd_out = 0;
	redir->heredoc = NULL;
	redir->content = NULL;
	redir->limiter = NULL;
	token->class = REDIR;
	return (redir);
}
