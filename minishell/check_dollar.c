/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:46:43 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/28 11:00:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_arg(int len, int *i, t_clean *utils)
{
	char	*arg;
	int		k;

	arg = malloc((len + 1) * sizeof(char));
	if (!arg)
		errors((*utils->head), 15);
	k = 0;
	while (utils->line[*i] && !exp_separ(utils->line[*i]) && k < len)
		arg[k++] = utils->line[(*i)++];
	arg[k] = 0;
	*i = *i - k;
	return (arg);
}

void	get_last_exit_code(char **result, int *i, int *j, t_clean *utils)
{
	int		k;
	char	*tmp;

	k = ft_count_digit(utils->exit_status);
	tmp = malloc((k + 1) * sizeof(char));
	if (tmp == NULL)
		error_message(15, "malloc");
	if (k > 2)
	{
		*result = ft_realloc(*result, utils->size + k + 1, utils->size);
		utils->size = utils->size + k + 1;
	}
	ft_num_str(tmp, k, utils->exit_status);
	k = 0;
	while (tmp[k])
		(*result)[(*j)++] = tmp[k++];
	free(tmp);
	(*i) += 2;
}

void	get_cmd_dollar(char **result, int *i, int *j, t_clean *utils)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = env_last_cmd(utils->env);
	if (!tmp)
		errors(*utils->head, 15);
	if (ft_strlen(tmp) > 2)
	{
		*result = ft_realloc(*result, utils->size + \
		ft_strlen(tmp) + 1, utils->size);
		utils->size = utils->size + ft_strlen(tmp) + 1;
	}
	while (tmp[k])
		(*result)[(*j)++] = tmp[k++];
	(*i) += 2;
}

bool	check_expansion(char *expanded, char **result, int *j, t_clean *utils)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = NULL;
	if (!expanded)
	{
		if (*j)
			tmp = ft_substr(*result, 0, *j);
		if (tmp)
		{
			free(*result);
			*result = tmp;
		}
		return (false);
	}
	if (ft_strlen(expanded) > 2)
	{
		*result = ft_realloc(*result, utils->size + ft_strlen(expanded) \
		+ 1, utils->size);
		utils->size = utils->size + ft_strlen(expanded) + 1;
	}
	while (expanded[k])
		(*result)[(*j)++] = expanded[k++];
	return (free(expanded), true);
}

void	expand_dollar(char **result, int *i, int *j, t_clean *utils)
{
	int		k;
	char	*tmp;
	char	*expanded;
	int		l;

	(*i)++;
	k = *i;
	while (utils->line[k] && !exp_separ(utils->line[k]) && \
	((utils->line[k] != '\'' || utils->in_double_quote) && \
	(utils->line[k] != '\"' || utils->in_single_quote)))
		k++;
	l = k - *i;
	tmp = copy_arg(l, i, utils);
	l = *i;
	*i = k;
	expanded = dollar_expansion(tmp, utils->env);
	free(tmp);
	tmp = NULL;
	if (check_expansion(expanded, result, j, utils) == true)
		*i = k;
	else
	{
		while (utils->line[l] && !exp_separ(utils->line[l]) && \
		utils->line[l] != '\''  && utils->line[l] != '\"' )
			l++;
		*i = l;
	}
}
