/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:04:50 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/26 18:38:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_substr(char *str, int *end, char stop)
{
	int	start;

	start = *end;
	while (str[*end] && str[*end] != stop)
		*end += 1;
	if (*end != start)
		return (ft_substr(str, start, *end - start));
	else
		return (NULL);
}

void	sort_env(t_env **env)
{
	int		i;
	t_env	*curr;
	t_env	*compare;

	curr = *env;
	while (curr)
	{
		i = 1;
		compare = *env;
		while (compare)
		{
			if (ft_strncmp(curr->name, compare->name, \
				ft_strlen(curr->name) + 1) > 0)
				i++;
			compare = compare->next;
		}
		curr->i_sort = i;
		curr = curr->next;
	}
}

void	update_variable(t_env **to_update, int i, \
		char *var_new, int export_flag)
{
	t_env	*curr;
	char	*tmp;

	curr = *to_update;
	if (!curr)
		return ;
	if (curr->value && var_new)
	{
		free(curr->value);
		curr->value = NULL;
	}
	if (var_new)
	{
		tmp = get_substr(var_new, &i, STOP_AT_ENDSTR);
		curr->value = tmp;
	}
	else if (!i)
	{
		free(curr->value);
		curr->value = NULL;
	}
	curr->equal_flag = EQUAL_FLAG;
	if (export_flag)
		curr->exported_flag = EXPORT_FLAG;
}
