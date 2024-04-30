/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:44:30 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:04:00 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*here_doc_sub(char *str, t_redir *redir)
{
	int		i;
	int		j;
	char	*lim;

	i = 0;
	while (str[i] == '<')
		i++;
	redir->data = ft_substr(str, 0, i);
	while (str[i] == ' ')
		i++;
	j = i;
	while (str[j])
		j++;
	lim = malloc((j + 1) * sizeof(char));
	if (!lim)
		return (NULL);
	j = 0;
	while (str[i])
	{
		lim[j] = str[i];
		j++;
		i++;
	}
	lim[j] = 0;
	return (lim);
}

t_word	*init_word(int begin, int stop)
{
	t_word	*word;

	word = malloc(sizeof(t_word));
	if (word == NULL)
		return (NULL);
	word->data = NULL;
	word->start = begin;
	word->end = stop;
	return (word);
}

void	place_arg(t_arg *arg, t_cmd *cmd)
{
	int		i;
	t_arg	*curr;

	i = 1;
	if (!cmd)
		return ;
	if (cmd->first_arg == NULL)
	{
		arg->index = 0;
		cmd->first_arg = arg;
	}
	else
	{
		curr = cmd->first_arg;
		while (curr->next != NULL)
		{
			i++;
			curr = curr->next;
		}
		arg->index = i;
		arg->prev = curr;
		arg->prev->next = arg;
	}
}

char	*get_file_path(char **str)
{
	char	*file_name;
	char	*path;

	path = NULL;
	file_name = ft_strrchr(*str, '/');
	if (file_name && file_name != *str)
	{
		path = ft_substr(*str, 0, file_name - *str);
		file_name = ft_strdup(file_name + 1);
		free(*str);
		*str = file_name;
	}
	return (path);
}
