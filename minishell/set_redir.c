/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:21:00 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:04:29 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_file(t_file *file, t_redir *redir, t_clean *utils)
{
	char	*err_msg;

	if (file->path_to_file)
	{
		err_msg = form_err_msg(file->path_to_file, "/", file->data);
		if (chdir(file->path_to_file) < 0 && !utils->file_error)
			set_error(utils, err_msg);
	}
	else
		err_msg = ft_strdup(file->data);
	file->fd = open(file->data, O_RDONLY);
	if (file->fd == -1 && !utils->file_error)
		set_error(utils, err_msg);
	if (utils->token->next != NULL)
	{
		file = utils->token->next->type;
		redir->fd_in = file->fd;
		redir->fd_out = STDIN_FILENO;
	}
	if (file->path_to_file)
		set_message_err(utils, err_msg, file);
	free(err_msg);
	err_msg = NULL;
}

void	output_file(t_file *file, t_redir *redir, t_clean *utils, int flag)
{
	char	*err_msg;

	if (file->path_to_file)
	{
		err_msg = form_err_msg(file->path_to_file, "/", file->data);
		if (chdir(file->path_to_file) < 0 && !utils->file_error)
			set_error(utils, err_msg);
	}
	else
		err_msg = ft_strdup(file->data);
	open_output(flag, file);
	if (file->fd == -1 && !utils->file_error)
		set_error(utils, err_msg);
	if (utils->token->next != NULL)
	{
		file = utils->token->next->type;
		redir->fd_in = STDIN_FILENO;
		redir->fd_out = file->fd;
	}
	if (file->path_to_file)
		set_message_err(utils, err_msg, file);
	free(err_msg);
	err_msg = NULL;
}

void	set_fd(t_file *fd, t_redir *redir, t_clean *utils)
{
	fd = utils->token->next->type;
	if (ft_strncmp("<", redir->data, 1) == 0)
		input_file(fd, redir, utils);
	else if (ft_strncmp(">", redir->data, 2) == 0)
		output_file(fd, redir, utils, 0);
	else if (ft_strncmp(">>", redir->data, 2) == 0)
		output_file(fd, redir, utils, 1);
}

void	set_heredoc(t_redir *redir, t_file *tmp, t_env *env, t_clean *utils)
{
	tmp = malloc(sizeof(t_file));
	if (!tmp)
		errors(utils->token, 0);
	tmp->data = ".Here_doc.txt";
	tmp->limiter = redir->limiter;
	tmp->fd = open(tmp->data, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp->fd == -1 && !utils->file_error)
	{
		utils->file_error = ft_strdup(".Here_doc.txt");
		utils->err_num = errno;
	}
	gnl_argv(tmp, env, utils);
	close(tmp->fd);
	tmp->fd = open(tmp->data, O_RDONLY);
	redir->heredoc = tmp;
	redir->fd_in = tmp->fd;
	redir->fd_out = STDIN_FILENO;
}

void	open_output(int flag, t_file *file)
{
	if (flag == 0)
		file->fd = open(file->data, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (flag == 1)
		file->fd = open(file->data, O_CREAT | O_WRONLY | O_APPEND, 0644);
}
