/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:02:54 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_token(char *str, int flag, t_token *token, t_env *env)
{
	DEBUG
	if (flag == CMD || flag == BUILT_IN)
		token->type = init_cmd(str, token, env);
	else if (flag == REDIR)
		token->type = init_redir(str, token);
	else if (flag == FILES)
		token->type = init_file(str, token);
	else if (flag == ARG)
		token->type = init_arg(str, token, env);
}

char	*check_line(char *line, t_token *token, t_clean *utils)
{
	int		i;
	int		j;
	char	*result;
	char	*tmp;

	utils->size = (utils->j - utils->i + 1) * 2;
	utils->line = line;
	i = utils->i;
	j = 0;
	result = run_line(&i, &j, utils, token);
	if (result && result[0] != 0 && j < (int)utils->size)
	{
		tmp = ft_strdup(result);
		free(result);
		result = malloc((j + 1) * sizeof(char));
		i = 0;
		j = 0;
		while (tmp[i])
			result[j++] = tmp[i++];
		result[j] = 0;
		utils->size = j + 1;
		free(tmp);
	}
	return (result);
}

// to get the first token of the commande (for exemple a 
// commande entered after a pipe)
t_token	*get_first_cmd(t_token *token)
{
	t_token	*curr_tok;

	if (!token->prev)
		return (token);
	curr_tok = token->prev;
	while (curr_tok->prev)
	{
		if (curr_tok->class == REDIR)
		{
			if (is_pipe(curr_tok))
				return (curr_tok->next);
		}
		curr_tok = curr_tok->prev;
	}
	return (curr_tok);
}

void	define_token(char *arg, t_token *token, t_clean *utils)
{
	t_word	*cur_word;
	t_token	*f_cmd;

	cur_word = token->word;
	if (cur_word->end < cur_word->start)
		return ;
	utils->i = cur_word->start;
	utils->j = cur_word->end;
	cur_word->data = check_line(arg, token, utils);
	if (cur_word->data == NULL)
	{
		token->type = NULL;
		return ;
	}
	f_cmd = get_first_cmd(token);
	if (is_redir(cur_word->data))
		init_token(cur_word->data, REDIR, token, utils->env);
	else if (token->prev && token->prev->class == REDIR && \
	(token->prev->needs_file == true))
		init_token(cur_word->data, FILES, token, utils->env);
	else if ((token == f_cmd && !ft_strchr(cur_word->data, '=')) || \
	((f_cmd->class != CMD && f_cmd->class != BUILT_IN) && token != f_cmd))
		init_token(cur_word->data, CMD, token, utils->env);
	else
		init_token(cur_word->data, ARG, token, utils->env);
}
