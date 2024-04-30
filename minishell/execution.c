/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:16:32 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/26 19:43:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"

int	execution(t_env **env, t_token *lst_token)
{
	int		i;
	int		wstatus;
	t_exe	data;

	if (!lst_token)
		return (0);
	if (lst_token->class == ARG && all_vars(&lst_token))
		return (exec_var(env, lst_token));
	if (builtin_to_exec(lst_token))
		return (exec_bi(env, lst_token));
	init_exec(&data, lst_token);
	if (!data.lst_cmd)
		return (1);
	i = -1;
	while (++i <= data.no_pipes)
	{
		if (forking(&data, i, env) > 0)
			return (1);
	}
	i = 0;
	while (i <= data.no_pipes)
		waitpid(data.pids[i++], &wstatus, 0);
	free(data.pids);
	return (catch_error(wstatus, lst_token, env));
}

int	exec_bi(t_env **env, t_token *cmd_bi)
{
	t_cmd	*cmd;
	char	*to_lower;

	cmd = cmd_bi->type;
	to_lower = is_capital(cmd->data);
	if (!ft_strncmp(cmd->data, "export", 7) && cmd->first_arg)
		return (free(to_lower), exec_var(env, cmd_bi));
	if (!ft_strncmp(cmd->data, "unset", 6))
		return (free(to_lower), exec_unset(env, cmd->first_arg));
	if (!ft_strncmp(cmd->data, "exit", 5))
		return (free(to_lower), exec_exit(env, cmd_bi));
	if (!ft_strncmp(cmd->data, "cd", 3))
		return (free(to_lower), exec_cd(env, *cmd_bi));
	if (!ft_strncmp(to_lower, "cd", 3))
		return (free(to_lower), exec_demi_cd(env, *cmd_bi));
	if (!ft_strncmp(to_lower, "echo", 5))
		return (free(to_lower), exec_echo(env, *cmd_bi), 0);
	if (!ft_strncmp(cmd->data, "export", 7))
		return (free(to_lower), exec_export(env, *cmd_bi), 0);
	if (!ft_strncmp(to_lower, "env", 4))
		return (free(to_lower), exec_env(env, *cmd_bi));
	if (!ft_strncmp(to_lower, "pwd", 4))
		return (free(to_lower), exec_pwd(env, *cmd_bi), 0);
	return (-1);
}

void	init_exec(t_exe *data, t_token *lst_token)
{
	data->lst_cmd = NULL;
	data->no_pipes = get_no_pipe(lst_token);
	data->fd_pipe_a[0] = 0;
	data->fd_pipe_b[0] = 0;
	data->pids = NULL;
	if (data->no_pipes > 0)
	{
		if (!open_pipes(data, BOTH_PIPES))
			return ;
	}
	data->pids = malloc(sizeof(int) * (data->no_pipes + 1));
	if (!data->pids)
		return (ft_putstr_fd("minishell: pids allocation memory failed\n", 2));
	data->lst_cmd = lst_token;
}

int	forking(t_exe *data, int i, t_env **env)
{
	t_token	*curr_cmd;
	t_cmd	*cmd;
	char	**exec_cmd;
	char	**tbl_env;
	char	*slash;

	data->pids[i] = fork();
	if (data->pids[i] < 0)
		return (ft_putstr_fd("minishell: problem forking\n", 2), 1);
	if (data->pids[i] == 0)
	{
		set_signals(data->lst_cmd, CHILD_FLAG);
		curr_cmd = set_redir(data, i);
		slash = NULL;
		cmd = verifications(&slash, curr_cmd, env);
		exec_cmd = get_exec_cmd(cmd);
		tbl_env = get_exec_env(*env, slash);
		execve(exec_cmd[0], exec_cmd, tbl_env);
		error_execve(exec_cmd[0], slash);
	}
	set_signals(data->lst_cmd, PARENT_WITH_CHILD);
	return (set_parent_pipes(data, i), 0);
}

int	exec_exit(t_env **env, t_token *lst_token)
{
	t_cmd	*cmd;
	int		i;
	int		exit_code;

	exit_code = 0;
	cmd = lst_token->type;
	i = 0;
	if (cmd->first_arg)
	{
		if (cmd->first_arg->next)
			return (ft_putstr_fd("minishell: exit: too many arguments\n", 2), 1);
		if (cmd->first_arg->data[i] == '-' || cmd->first_arg->data[i] == '+')
			i++;
		while (cmd->first_arg->data[i] && ft_isdigit(cmd->first_arg->data[i]))
			i++;
		if (cmd->first_arg->data[i])
			handle_exit_error(cmd->first_arg->data, &exit_code);
		else
			exit_code = get_exit_code(ft_atoi(cmd->first_arg->data));
	}
	free_lst_env(env);
	return (exit_code);
}
