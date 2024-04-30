/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handeling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:53:14 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:22:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"

volatile sig_atomic_t	g_signal_flag = 0;

void	handle_signal_child(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', 1);
	rl_redisplay();
}

void	handle_signal_wo_child(int signal)
{
	(void)signal;
	g_signal_flag = 1;
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_signal_heredoc(int signal)
{
	(void)signal;
	g_signal_flag = 1;
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signal(struct sigaction *sa, t_token *head)
{
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = 0;
	if (sigaction(SIGINT, sa, NULL) != 0)
		errors(head, 3);
}

void	set_signals(t_token *head, int flag)
{
	struct sigaction	sa_ignore;
	struct sigaction	sa_parent_wo_child;
	struct sigaction	sa_child;
	struct sigaction	sa_heredoc;

	sa_ignore.sa_handler = SIG_IGN;
	sigemptyset(&sa_ignore.sa_mask);
	sa_ignore.sa_flags = 0;
	if (sigaction(SIGQUIT, &sa_ignore, NULL) != 0)
		errors(head, 3);
	sa_parent_wo_child.sa_handler = handle_signal_wo_child;
	sa_child.sa_handler = handle_signal_child;
	sa_heredoc.sa_handler = handle_signal_heredoc;
	if (!flag)
		handle_signal(&sa_parent_wo_child, head);
	else if (flag == PARENT_WITH_CHILD)
		handle_signal(&sa_ignore, head);
	else if (flag == HEREDOC_FLAG)
		handle_signal(&sa_heredoc, head);
	else
		handle_signal(&sa_child, head);
}
