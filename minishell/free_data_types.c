/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:06:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:11:01 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_token *token)
{
	t_cmd	*cmd;
	t_arg	*to_free;
	t_arg	*next_arg;

	cmd = token->type;
	free(cmd->data);
	free(cmd->path_to_cmd);
	cmd->path_to_cmd = NULL;
	cmd->data = NULL;
	if (cmd->first_arg)
	{
		to_free = cmd->first_arg;
		while (to_free)
		{
			next_arg = to_free->next;
			free(to_free->data);
			to_free->data = NULL;
			free(to_free);
			to_free = next_arg;
		}
	}
}

void	free_redir(t_token *token)
{
	t_redir	*redir;

	redir = token->type;
	if (redir->limiter != NULL)
	{
		unlink(".Here_doc.txt");
		free(redir->heredoc);
		free(redir->limiter);
		redir->heredoc = NULL;
	}
	if (redir->fd_in > 1)
		close(redir->fd_in);
	if (redir->fd_out > 1)
		close(redir->fd_out);
	redir->fd_in = 0;
	redir->fd_out = 0;
	free(redir->data);
	free(redir->content);
	redir->data = NULL;
}
