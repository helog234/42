/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:23:41 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 19:52:40 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_pipe(t_token *token)
{
	t_redir	*redir;

	if (token->class != REDIR)
		return (false);
	redir = token->type;
	if (ft_strncmp("|", redir->data, 2) == 0)
		return (true);
	return (false);
}

t_token	*get_last(t_token *head)
{
	int	i;

	i = 1;
	while (head->next != NULL)
	{
		head = head->next;
		printf ("token %i - ", i++);
	}
	printf("\n");
	return (head);
}

void	ft_put_nbr(int n, char **str, char *old_str)
{
	char	*code_status;
	int		size;

	size = ft_count_digit(n);
	code_status = malloc((size + 1) * sizeof(char));
	if (code_status == NULL)
		error_message(15, "malloc");
	ft_num_str(code_status, size, n);
	free(*str);
	*str = NULL;
	*str = ft_strjoin(old_str, code_status);
	free(code_status);
	free(old_str);
}

void	strjoin_andfree(char **line, char *str)
{
	char	*tmp;

	tmp = ft_strjoin(*line, str);
	free(*line);
	*line = tmp;
	if (str)
		free(str);
	tmp = NULL;
}

void	set_message_err(t_clean *utils, char *err_msg, t_file *file)
{
	if (chdir(file->pwd) < 0 && !utils->file_error)
		set_error(utils, err_msg);
}
