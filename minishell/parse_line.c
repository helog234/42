/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:57:57 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:24:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_limiter(char *line, int i, int start)
{
	while (line[i])
	{
		if (is_separator(line[i]) == 1 && i > start)
			return (i - 1);
		if (is_right_redir(line[i]) && i > start)
			return (i - 1);
		if (is_left_redir(line[i]) && i > start)
			return (i - 1);
		if (line[i] == '|')
			return (i - 1);
		if (is_quote(line[i]))
			return (i - 1);
		if (line[i] == '$')
			return (i - 1);
		i++;
	}
	return (i);
}

int	handle_redir(int start, int i, char *line)
{
	int	j;

	j = i;
	if (i == start || is_separator(line[i - 1]))
	{
		while (line[i] == line[i + 1])
			i++;
		if (is_right_redir(line[j]))
			return (i);
		if (is_left_redir(line[j]) && i > j)
			i = get_limiter(line, i + 1, i + 1);
		return (i);
	}
	else
		return (i - 1);
}

//checker si il y a un espace et donc que c'est un argument a tokeniser
int	is_word_str(char *str, int start)
{
	int		i;
	int		j;

	if (start >= ft_strlen(str))
		return (0);
	i = start;
	j = 0;
	while (str[i])
	{
		if (is_separator(str[i]) == 1 && i > start)
			return (i - 1);
		if (is_right_redir(str[i]) || is_left_redir(str[i]))
			return (handle_redir(start, i, str));
		if (str[i] == '|')
			return (get_pipe_char(str, i, start));
		if (is_quote(str[i]))
		{
			j = get_quote_char(str, i);
			i = j;
		}
		i++;
	}
	return (i);
}
