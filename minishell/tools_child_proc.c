/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_child_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:57:40 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 16:29:03 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redir_in(t_token *token)
{
	t_redir	*redir;

	redir = token->type;
	if (ft_strncmp("<", redir->data, 2) == 0 \
		|| ft_strncmp("<<", redir->data, 3) == 0)
		return (true);
	return (false);
}

bool	is_redir_out(t_token *token)
{
	t_redir	*redir;

	redir = token->type;
	if (ft_strncmp(">", redir->data, 2) == 0 \
		|| ft_strncmp(">>", redir->data, 3) == 0)
		return (true);
	return (false);
}

void	do_redir(int fd, int std)
{
	if (dup2(fd, std) < 0)
		exit(1);
}

int	find_redir(t_token *curr_tok, int pipe, int std)
{
	t_redir	*redir_tok;

	if (curr_tok->class == REDIR)
	{
		redir_tok = curr_tok->type;
		if (std == STDOUT_FILENO && is_pipe(curr_tok))
		{
			if (isatty(1))
				do_redir(pipe, std);
			return (1);
		}
		else if (is_redir_in(curr_tok) \
		&& redir_tok->fd_in && std == STDIN_FILENO)
			do_redir(redir_tok->fd_in, std);
		else if (is_redir_out(curr_tok) \
		&& redir_tok->fd_out && std == STDOUT_FILENO)
			do_redir(redir_tok->fd_out, std);
		else if (!curr_tok->prev)
			close (pipe);
		if (std == STDIN_FILENO && is_pipe(curr_tok) && isatty(0))
			return (1);
	}
	return (0);
}

void	close_pipes(t_exe *data, int flag)
{
	if ((flag == PIPE_A || flag == BOTH_PIPES) && data->fd_pipe_a[0])
	{
		close(data->fd_pipe_a[0]);
		close(data->fd_pipe_a[1]);
	}
	if ((flag == PIPE_B || flag == BOTH_PIPES) && data->fd_pipe_b[0])
	{
		close(data->fd_pipe_b[0]);
		close(data->fd_pipe_b[1]);
	}
}
