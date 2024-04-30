/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_child_proc2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:51:24 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 16:40:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipes(int i, int (*pipe_used)[2], t_exe *data)
{
	if (i % 2 == 0)
	{
		(*pipe_used)[0] = data->fd_pipe_a[0];
		(*pipe_used)[1] = data->fd_pipe_b[1];
	}
	else
	{
		(*pipe_used)[0] = data->fd_pipe_b[0];
		(*pipe_used)[1] = data->fd_pipe_a[1];
	}
	set_i_o(data->lst_cmd, (*pipe_used)[0], STDIN_FILENO);
	set_i_o(data->lst_cmd, (*pipe_used)[1], STDOUT_FILENO);
}

void	verify_msh(t_cmd *cmd, char *slash)
{
	if (slash && !ft_strncmp(slash, "/minishell", 11))
	{
		if (!isatty(0) || !isatty(1))
			exit (0);
		if (cmd->first_arg)
		{
			free(cmd->data);
			cmd->data = ft_strdup(cmd->first_arg->data);
			if (cmd->path_to_cmd)
			{
				free(cmd->path_to_cmd);
				cmd->path_to_cmd = NULL;
			}
		}
	}
}
