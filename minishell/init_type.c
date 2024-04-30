/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:13:20 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:44:26 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(char *str, t_token *token, t_env *env)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = add_cmd(token, cmd);
	if (is_cmd(str, env, token) == BUILT_IN)
	{
		token->class = BUILT_IN;
		cmd->path_to_cmd = NULL;
	}
	else if (is_cmd(str, env, token) == CMD)
	{
		token->class = CMD;
		cmd->path_to_cmd = extract_path(env, str);
	}
	else
		token->class = CMD;
	if (cmd->data == NULL)
		cmd->data = str;
	return (cmd);
}

t_redir	*init_redir(char *str, t_token *token)
{
	t_redir	*redir;

	redir = NULL;
	redir = add_redir(token, redir);
	if (ft_strncmp(str, "<<", 2) == 0)
	{
		redir->limiter = here_doc_sub(str, redir);
		token->needs_file = false;
		free(str);
	}
	else
	{
		redir->limiter = NULL;
		token->needs_file = true;
		redir->data = str;
	}
	if (ft_strncmp(str, "|", 2) == 0)
		token->needs_file = false;
	return (redir);
}

t_file	*init_file(char *str, t_token *token)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (file == NULL)
		errors(token, 0);
	file->fd = 0;
	file->path_to_file = get_file_path(&str);
	file->pwd = getcwd(NULL, 0);
	file->data = str;
	token->class = FILES;
	return (file);
}

void	set_arg_in_place(char *str, t_token *token, t_arg *arg)
{
	t_cmd	*cmd;

	cmd = NULL;
	if (token->prev)
	{
		if (token->prev->class == CMD || token->prev->class == BUILT_IN)
			cmd = token->prev->type;
		if (token->prev->prev && (token->prev->class == CMD \
		|| token->prev->class == BUILT_IN))
		{
			if (token->prev->prev && is_arg(str, token) == ARG)
				cmd = token->prev->prev->type;
		}
	}
	place_arg(arg, cmd);
}

t_arg	*init_arg(char *str, t_token *token, t_env *env)
{
	t_arg	*arg;
	int		check;

	(void)env;
	check = 0;
	arg = add_arg(str, token);
	if (str == NULL)
		return (free(arg), NULL);
	arg->data = ft_strdup(str);
	if (ft_strchr(str, '=') != NULL && \
	(is_quote(str[0]) != 0 && is_quote(str[ft_strlen(str)]) != 0))
		check = 1;
	if (check == 0)
		set_arg_in_place(str, token, arg);
	return (arg);
}
