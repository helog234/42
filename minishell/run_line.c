/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:44:14 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/28 11:00:04 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_single_quote(char **result, int *i, int *j, t_clean *utils)
{
	(*i)++;
	utils->in_single_quote = true;
	while (utils->in_single_quote && utils->line[*i] != '\0')
	{
		if (utils->line[*i] == '\'')
		{
			utils->in_single_quote = false;
			(*i)++;
		}
		else
		{
			(*result)[(*j)++] = utils->line[*i];
			(*i)++;
		}
	}
}

void	run_double_quote(int *i, t_clean *utils)
{
	if (utils->line[*i] == '\"' && (!utils->in_single_quote))
	{
		if (!utils->in_double_quote && utils->line[*i] != '\0')
		{
			utils->in_double_quote = true;
			(*i)++;
		}
		else
		{
			utils->in_double_quote = false;
			(*i)++;
		}
	}
}

void	prep_dollar(char **result, int *i, int *j, t_clean *utils)
{
	if (utils->line[*i + 1] == '?')
		get_last_exit_code(result, i, j, utils);
	else if (utils->line[*i + 1] == '_')
		get_cmd_dollar(result, i, j, utils);
	else if (exp_separ(utils->line[*i + 1]))
		(*result)[(*j)++] = utils->line[(*i)++];
	else if (ft_isalpha(utils->line[*i + 1]))
		expand_dollar(result, i, j, utils);
	else if (utils->line[*i + 1] == 0)
	{
		(*result)[*j] = utils->line[*i];
		(*j)++;
		(*i)++;
		return ;
	}
	else if (utils->line[*i])
		*result[*j++] = utils->line[*i++];
	else
		return ;
}

char	*run_line(int *i, int *j, t_clean *utils, t_token *token)
{
	char	*result;

	result = malloc((utils->size) * sizeof(char));
	if (!result)
		errors((*utils->head), 15);
	while (utils->line[*i] && *i <= utils->j)
	{
		if (utils->line[*i] == '\'' && (!utils->in_double_quote))
			run_single_quote(&result, i, j, utils);
		else if (utils->line[*i] == '\"' && (!utils->in_single_quote))
			run_double_quote(i, utils);
		else if (utils->line[*i] && utils->line[*i] == '$' \
		&& (!utils->in_single_quote))
		{
			token->dollar = true;
			prep_dollar(&result, i, j, utils);
		}
		else
			result[(*j)++] = utils->line[(*i)++];
	}
	if (result)
		result[*j] = '\0';
	return (result);
}
