/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:43:55 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 12:34:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env		*ms_env;
	t_token		*head;
	char		*msh_dir;

	(void)argv;
	(void)argc;
	ms_env = NULL;
	head = NULL;
	save_env(&ms_env, envp);
	msh_dir = form_err_msg(getenv("PWD"), "/", ".history.log");
	load_history(msh_dir);
	set_signals(head, 0);
	g_signal_flag = 0;
	return (set_prompt(ms_env, &head, msh_dir));
	free(msh_dir);
}
