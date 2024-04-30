/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctr_input_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:23:43 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:09:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//en cas de pipe à la fin de l'input retourner prompt et 
// premier argument sera suite de pipe

char	*add_back_line(char *add, char *line)
{
	char	*new;

	new = ft_strjoin(line, add);
	free(add);
	free(line);
	return (new);
}

int	check_unclosed_pipe(int i, char *str)
{
	i++;
	while (str[i] && is_separator(str[i]))
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

int	check_unclosed_quote(int i, char *str)
{
	int	quote;

	quote = is_quote(str[i]);
	i++;
	while (str[i] && (int)str[i] != quote)
		i++;
	if (str[i] && (int)str[i] == quote)
		return (i + 1);
	else
		return (-1);
}

int	check_quote_and_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]) > 0)
		{
			i = check_unclosed_quote(i, str);
			if (i < 0)
				return (i);
		}
		else if (str[i] == '|')
		{
			i++;
			i = check_unclosed_pipe(i, str);
			if (i < 0)
				return (i);
		}
		else
			i++;
	}
	return (i);
}

t_cmd	*get_token_cmd(t_token *token)
{
	t_token	*curr;
	t_cmd	*cmd;

	curr = token;
	while (curr && (curr->class != CMD && curr->class != BUILT_IN))
		curr = curr->prev;
	if (!curr)
	{
		ft_printf("No CMD token found.\n");
		return (NULL);
	}
	cmd = curr->type;
	return (cmd);
}
