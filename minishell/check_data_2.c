/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:50:46 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:15:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//checker si comprend un dollar sign
int	is_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}

bool	is_heredoc_separator(char c)
{
	if ((exp_separ(c) || is_quote(c)))
		return (true);
	return (false);
}

bool	exp_separ(char c)
{
	if ((c >= 32 && c <= 47 && c != '\'') || (c >= 58 && c <= 64))
		return (true);
	return (false);
}

bool	is_dollar_question_mark(char *str, int i)
{
	char	*tmp;

	if (i < 0)
		return (false);
	tmp = &str[i];
	if (ft_strncmp(tmp, "$?", 2) == 0)
		return (true);
	return (false);
}

bool	is_special_dollar(char *str, t_clean *utils)
{
	if (ft_strncmp(str, "*", 2) == 0)
		errors((*utils->head), 258);
	if (ft_strncmp(str, "$", 2) == 0)
		errors((*utils->head), 258);
	if (ft_strncmp(str, "#", 2) == 0)
		errors(*(utils->head), 258);
	if (ft_strncmp(str, "!", 2) == 0)
		errors(*(utils->head), 258);
	return (false);
}
