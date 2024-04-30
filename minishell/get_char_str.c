/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:35:52 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:18:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pipe_char(char *line, int i, int start)
{
	if (line[i] != '|')
		return (-1);
	if (line[i] == '|' && i == start)
		return (i);
	if (line[i] == '|')
		return (i - 1);
	return (-1);
}

int	get_quote_char(char *line, int i)
{
	int	flag;

	flag = is_quote(line[i]);
	i++;
	while (line[i] && line[i] != (char)flag)
		i++;
	return (i);
}

int	get_dollar_str(char *line, int i)
{
	return (is_word_str(line, i + 1));
}

int	is_left_redir(char c)
{
	if (c == '<')
		return (1);
	return (0);
}

int	is_right_redir(char c)
{
	if (c == '>')
		return (1);
	return (0);
}
