/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thajak <thajak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:10:32 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 10:48:43 by thajak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//checker si c'est une redirection
int	is_redir(char *data)
{
	if (data[0] == '|' && data[1] == 0)
		return (REDIR);
	else if (data[0] == '<' && data[1] == 0)
		return (REDIR);
	else if (data[0] == '>' && data[1] == 0)
		return (REDIR);
	else if (data[0] == '>' && data[1] == '>')
		return (REDIR);
	else if (data[0] == '<' && data[1] == '<')
		return (REDIR);
	return (0);
}

bool	is_built_in(char *lower, char *data)
{
	if (ft_strncmp("echo", lower, 4) == 0)
		return (true);
	else if (ft_strncmp("cd", lower, 2) == 0)
		return (true);
	else if (ft_strncmp("pwd", lower, 3) == 0)
		return (true);
	else if (ft_strncmp("export", data, 6) == 0)
		return (true);
	else if (ft_strncmp("unset", data, 5) == 0)
		return (true);
	else if (ft_strncmp("env", lower, 3) == 0)
		return (true);
	else if (ft_strncmp("exit", data, 4) == 0)
		return (true);
	return (false);
}

//checker si c'est une commande
int	is_cmd(char *data, t_env *env, t_token *token)
{
	char	*tmp;
	char	*lower;

	tmp = extract_path(env, data);
	lower = is_capital(data);
	if (lower == NULL)
	{
		free(tmp);
		errors(token, 0);
	}
	if (is_built_in(lower, data) == true)
		return (free(lower), free(tmp), BUILT_IN);
	else if (tmp != NULL)
		return (free(lower), free(tmp), CMD);
	else if (is_dollar(data) >= 0)
		return (free(tmp), 3);
	else if (!is_redir(lower))
		return (free(lower), free(tmp), 0);
	else if (token->prev == NULL)
		return (free(lower), free(tmp), CMD);
	else
		return (free(lower), free(tmp), 0);
}

int	is_arg(char *str, t_token *token)
{
	if (ft_strchr(str, '=') != NULL && \
	(!is_quote(str[0]) && !is_quote(str[ft_strlen(str)])))
		return (2);
	if (!token->prev)
		return (0);
	if ((token->prev->class == CMD || token->prev->class == BUILT_IN || \
	!token->prev) && ft_strncmp(str, "$_", 2) != 0)
	{
		if (is_flag(str, token))
			return (1);
		return (2);
	}
	if (token->prev->class == REDIR)
		return (read_cmd_special(token));
	return (0);
}

int	read_cmd_special(t_token *token)
{
	t_redir	*redir;
	t_cmd	*cmd;

	if (!token->prev && !token->prev->prev)
		return (0);
	redir = token->prev->type;
	if ((ft_strncmp(redir->data, "<<", 2) == 0 && \
	!token->prev->prev) || (ft_strncmp(redir->data, "<<", 2) == 0 && \
	token->prev->prev->class == CMD))
	{
		if (!token->prev->prev)
			cmd = token->prev->type;
		else
			cmd = token->prev->prev->type;
		if (ft_strncmp(cmd->data, "cat", 3) == 0 || \
		ft_strncmp(cmd->data, "grep", 4) == 0)
			return (ARG);
	}
	return (0);
}
