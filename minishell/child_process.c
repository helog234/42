/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:44:31 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 16:16:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*set_redir(t_exe *data, int i)
{
	int		count_pipe;
	int		pipe_used[2];
	t_redir	*redir;
	t_exe	*curr_data;

	curr_data = data;
	count_pipe = 0;
	while (curr_data->lst_cmd)
	{
		if (curr_data->lst_cmd->class == REDIR)
		{
			redir = curr_data->lst_cmd->type;
			if (!ft_strncmp(redir->data, "|", 2))
				count_pipe++;
		}
		if (i == count_pipe)
		{
			set_pipes(i, &pipe_used, data);
			close_pipes(curr_data, BOTH_PIPES);
			return (get_cmd(curr_data->lst_cmd));
		}
		curr_data->lst_cmd = curr_data->lst_cmd->next;
	}
	return (NULL);
}

void	set_i_o(t_token *token, int pipe, int std)
{
	t_token	*curr_tok;

	curr_tok = token;
	if (curr_tok->class == REDIR && is_pipe(curr_tok))
	{
		if (std == STDIN_FILENO && is_pipe(curr_tok))
			do_redir(pipe, std);
		curr_tok = curr_tok->next;
	}
	while (curr_tok)
	{
		if (find_redir(curr_tok, pipe, std))
			break ;
		curr_tok = curr_tok->next;
	}
}

t_token	*get_cmd(t_token *lst_token)
{
	t_token	*curr_tok;

	curr_tok = lst_token;
	if (curr_tok->class == REDIR)
	{
		if (is_pipe(curr_tok))
			curr_tok = curr_tok->next;
	}
	while (curr_tok)
	{
		if (curr_tok->class == CMD || curr_tok->class == BUILT_IN \
			|| curr_tok->class == ARG)
			return (curr_tok);
		if (curr_tok->class == REDIR)
		{
			if (is_pipe(curr_tok))
				break ;
		}
		curr_tok = curr_tok->next;
	}
	return (NULL);
}

char	**get_exec_cmd(t_cmd *cmd)
{
	char	**exec_cmd;
	t_arg	*curr_arg;
	int		i;

	curr_arg = cmd->first_arg;
	i = lstsize(curr_arg, ARG);
	exec_cmd = malloc(sizeof(char *) * (i + 2));
	if (cmd->path_to_cmd)
		exec_cmd[0] = ft_strdup(cmd->path_to_cmd);
	else
		exec_cmd[0] = ft_strdup(cmd->data);
	i = 1;
	while (curr_arg)
	{	
		exec_cmd[i++] = ft_strdup(curr_arg->data);
		curr_arg = curr_arg->next;
	}
	exec_cmd[i] = NULL;
	return (exec_cmd);
}

char	**get_exec_env(t_env *env, char *slash)
{
	char	**exec_env;
	t_env	*curr_env;
	char	*temp;
	int		i;

	curr_env = env;
	i = lstsize(curr_env, EXPORT_FLAG);
	exec_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (curr_env)
	{
		if (curr_env->exported_flag && curr_env->equal_flag)
		{
			temp = ft_strjoin(curr_env->name, "=");
			exec_env[i] = update_value(curr_env, temp, slash);
			temp = NULL;
			i++;
		}
		curr_env = curr_env->next;
	}
	exec_env[i] = NULL;
	return (exec_env);
}
