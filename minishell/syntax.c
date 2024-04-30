/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:18:16 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 18:49:14 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctr_file_error(t_clean *utils, int *i)
{
	char	*err_msg;

	err_msg = form_err_msg("minishell: ", utils->file_error, ": ");
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd(strerror(utils->err_num), 2);
	ft_putstr_fd("\n", 2);
	free(err_msg);
	free(utils->file_error);
	utils->file_error = NULL;
	if (!*i && utils->err_num == 2)
		*i = 1;
}

int	check_invalid_token(t_redir *redir, t_clean *utils)
{
	if (redir->limiter && redir->limiter[0] == 0 && (!utils->token->next \
	|| ft_strncmp(redir->data, "<<<", 4) == 0))
	{
		error_return_prompt(utils, 258, "\n");
		return (258);
	}
	else if (ft_strncmp(redir->data, ">>>", 4) == 0)
	{
		error_return_prompt(utils, 258, "`>'\n");
		return (258);
	}
	return (0);
}

bool	read_cmd(t_clean *utils, t_token **token)
{
	t_cmd	*cmd;

	cmd = utils->token->type;
	if (ft_strncmp(cmd->data, "cat", 3) == 0 || \
	ft_strncmp(cmd->data, "grep", 4) == 0)
	{
		manage_grep_cat(utils);
		return (false);
	}
	else if (utils->token->prev && utils->token->prev->class != REDIR)
		return (manage_reconversion(token));
	return (false);
}

int	check_redir(int flag, t_clean *utils)
{
	t_redir	*redir;
	t_file	*fd;
	t_env	*env;
	t_token	*find_pipe;
	int		i;

	redir = utils->token->type;
	find_pipe = get_first_cmd(utils->token);
	env = utils->env;
	fd = NULL;
	i = check_invalid_token(redir, utils);
	if (i > 0)
		return (i);
	i = utils->err_num;
	if ((find_pipe->prev && is_pipe(find_pipe->prev)))
		utils->err_num = 0;
	if (flag == 1 && !is_pipe(utils->token) && utils->token->next \
	&& ft_strncmp(redir->data, "<<", 3) != 0 && !utils->err_num)
		set_fd(fd, redir, utils);
	else if (flag == 1 \
		&& (ft_strncmp(redir->data, "<<", 3) == 0 && redir->limiter[0] != 0))
		set_heredoc(redir, fd, env, utils);
	if (i)
		utils->err_num = i;
	return (0);
}

int	check_syntax(t_clean *utils)
{
	t_token	*curr;
	int		i;

	curr = (*utils->head);
	i = 0;
	utils->token = curr;
	while (curr)
	{
		if (curr->class == CMD || curr->class == BUILT_IN)
		{
			if (read_cmd(utils, &curr) == true)
				curr = (*utils->head);
		}
		else if (curr->class == REDIR)
		{
			i = check_redir(1, utils);
			if (i != 0)
				break ;
		}
		curr = curr->next;
		utils->token = curr;
	}
	if (utils->file_error)
		ctr_file_error(utils, &i);
	return (i);
}
