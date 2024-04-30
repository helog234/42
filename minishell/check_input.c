/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:28:01 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:58:16 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*add_new_arg_read(t_token *cmd_token, t_env *env)
{
	t_word	*word;
	t_token	*token;
	char	*str;

	word = cmd_token->next->word;
	str = ft_strdup(word->data);
	token = add_token(cmd_token, word->start, word->end);
	token->type = init_arg(str, token, env);
	word = token->word;
	word->data = str;
	cmd_token = cmd_token->next;
	if (cmd_token->next && cmd_token->next->class != REDIR)
	{
		add_new_arg_read(cmd_token, env);
		free_types_data(cmd_token);
		if (cmd_token->type)
			free(cmd_token->type);
		free(cmd_token->word);
		free(cmd_token);
	}
	return (cmd_token);
}

t_token	*add_new_arg(t_token **cmd_token, t_arg *arg)
{
	t_word	*word;
	t_token	*token;
	t_token	*previ;
	t_token	*next;
	char	*str;

	word = (*cmd_token)->word;
	previ = (*cmd_token)->prev;
	next = (*cmd_token)->next;
	previ->next = next;
	if (next)
		next->prev = previ;
	str = ft_strdup(word->data);
	token = add_token(previ, word->start, word->end);
	arg = add_arg(word->data, token);
	arg->data = str;
	token->type = arg;
	word = token->word;
	word->data = str;
	free_one_token(cmd_token, 1);
	return (token);
}

void	manage_grep_cat(t_clean *utils)
{
	t_file	*fd;
	t_token	*new;
	t_env	*env;
	t_redir	*redir;

	fd = NULL;
	new = NULL;
	env = utils->env;
	if (utils->token->next && utils->token->next->class == REDIR \
	&& utils->token->next->next)
	{
		redir = utils->token->next->type;
		if (ft_strncmp(redir->data, "<<", 2) == 0)
		{
			set_heredoc(redir, fd, env, utils);
			new = add_new_arg_read(utils->token, env);
		}
		if (new)
			utils->token->next = new;
	}
}

bool	manage_reconversion(t_token **token)
{
	t_cmd	*cmd;
	t_token	*curr;
	t_arg	*arg;
	t_token	*new;

	curr = (*token)->prev;
	arg = NULL;
	while (curr && (curr->class != CMD && curr->class != BUILT_IN))
		curr = curr->prev;
	if (!curr)
	{
		if ((*token)->next)
		*token = (*token)->next;
		return (false);
	}
	cmd = curr->type;
	new = add_new_arg(token, arg);
	arg = new->type;
	place_arg(arg, cmd);
	return (true);
}

void	set_error(t_clean *utils, char *err_msg)
{
	free(utils->file_error);
	utils->file_error = ft_strdup(err_msg);
	utils->err_num = errno;
}
