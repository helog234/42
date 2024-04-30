/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:35:57 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:01:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//checker si c'est un separateur
int	is_separator(char c)
{
	if (c == ' ' || c == '	' || c == 0 \
	|| c == '&' || c == ';' || c == '\n')
		return (1);
	return (0);
}

//checker si c'est une quote
int	is_quote(char c)
{
	if (c == 34)
		return (34);
	else if (c == 39)
		return (39);
	return (0);
}

//aller rechercher la fin de l'argument passee en parametre
int	is_str(int start, char *str)
{
	int		i;
	char	c;

	i = start + 1;
	c = is_quote((int)start);
	if (c == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_flag(char *str, t_token *token)
{
	t_token	*curr;

	curr = token->prev;
	if (str[0] == '-')
	{
		if (curr->class == CMD || curr->class == BUILT_IN)
			return (1);
	}
	return (0);
}

char	*is_capital(char *str)
{
	int		i;
	char	*lower;

	i = 0;
	lower = ft_strdup(str);
	if (lower == NULL)
		return (NULL);
	while (lower[i])
	{
		if (lower[i] >= 'A' && lower[i] <= 'Z')
			lower[i] = ft_tolower(lower[i]);
		i++;
	}
	return (lower);
}
