/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:58:48 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:59:00 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_message(int errnum, char *file)
{
	char	*err_msg;

	err_msg = form_err_msg("minishell: ", file, NULL);
	if (errnum == ENOENT)
		perror(err_msg);
	else if (errnum == EACCES)
		perror(err_msg);
	else if (errnum == 15)
		ft_putstr_fd("minishell: allocation memory failed\n", 2);
	else if (errnum == 258)
	{
		ft_putstr_fd("minishell: syntax error near \
		unexpected token `newline'\n", 2);
		strerror(errnum);
	}
	else
		perror(err_msg);
	free(err_msg);
}

void	error_return_prompt(t_clean *utils, int flag, char *c)
{
	t_token	*curr;
	char	*str;

	curr = *(utils->head);
	if (*c == '\n')
		c = "`newline'\n";
	str = ft_strjoin("minishell: syntax error near unexpected token ", c);
	ft_putstr_fd(str, 2);
	strerror(flag);
	utils->exit_status = flag;
	while (*(utils->head))
	{
		free_types_data(*(utils->head));
		if (!curr->type)
			free(curr->type);
		*(utils->head) = curr->next;
		free(curr);
		curr = *(utils->head);
	}
	*(utils->head) = NULL;
}

void	error_execve(char *cmd, char *slash)
{
	ft_putstr_fd("minishell : ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (!slash)
	{
		ft_putstr_fd("command not found\n", 2);
		exit (127);
	}
	else if (errno == 2)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		exit (127);
	}
	else if (errno == 13)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		exit (126);
	}
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	exit (1);
}

void	errors(t_token *curr, int flag)
{
	t_token	*head;

	while (curr->prev && curr->prev != NULL)
		curr = curr->prev;
	head = curr;
	error_message(flag, "");
	while (head)
	{
		free_types_data(curr);
		if (!curr->type)
			free(curr->type);
		head = curr->next;
		free(curr);
		curr = head;
	}
	exit(EXIT_FAILURE);
}
