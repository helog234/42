/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:14:16 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:03:44 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*set_arg(t_token *token, t_token *tmp)
{
	t_cmd	*cmd;
	t_arg	*arg;

	if (!token->prev)
		return (token);
	if ((token->prev->class == REDIR && read_cmd_special(token) == ARG) || \
	(token && token->class == ARG && token->prev && \
	token->prev->class == CMD) || (token && token->class == ARG \
	&& token->prev && token->prev->class == BUILT_IN))
	{
		tmp->next = NULL;
		free_one_token(&token, 0);
		token = tmp;
	}
	if (token && token->class == ARG && token->prev && \
	token->prev->class == FILES)
	{
		cmd = get_token_cmd(token);
		arg = token->type;
		place_arg(arg, cmd);
		tmp->next = NULL;
		free_one_token(&token, 0);
		token = tmp;
	}
	return (token);
}

//iterer dans les argv et creer des tokens
void	parse_line(char *line, t_clean *utils)
{
	int		end;
	int		start;
	t_token	*token;
	t_token	*tmp;

	token = NULL;
	start = 0;
	end = is_word_str(line, start);
	while (end >= start)
	{
		tmp = token;
		token = create_lst(start, end, token, utils->head);
		if (token)
		{
			utils->i = start;
			utils->j = end;
			define_token(line, token, utils);
			if (tmp)
				token = set_arg(token, tmp);
		}
		start = next_word(line, end + 1);
		end = is_word_str(line, start);
	}
}

int	init_parsing(char *line, t_clean *utils)
{
	char	*add;
	int		ctr;

	while (check_quote_and_pipe(line) == -1)
	{
		add = readline("> ");
		line = add_back_line(add, line);
	}
	if (*(utils->head) == NULL && line && line[0] != 0)
		parse_line(line, utils);
	if (line)
		free(line);
	line = NULL;
	ctr = check_syntax(utils);
	if (ctr != 0)
		return (ctr);
	return (0);
}
