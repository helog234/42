/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env_lst2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:01:41 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/26 17:21:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*find_var(t_env *env, int index, char *var)
{
	t_env	*curr;

	curr = env;
	while (curr && (index || var))
	{
		if (index)
		{
			if (curr->i_sort == index)
				return (curr);
		}
		else
		{
			if (ft_strncmp(var, curr->name, ft_strlen(var) + 1) == 0)
				return (curr);
		}
		curr = curr->next;
	}
	return (NULL);
}

void	rm_node(t_env *curr, t_env **lst)
{
	if (curr->prev)
	curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	if (curr == *lst)
		*lst = curr->next;
	curr->next = NULL;
	curr->prev = NULL;
	free(curr->name);
	curr->name = NULL;
	if (curr->value)
		free(curr->value);
	curr->value = NULL;
	free(curr);
	curr = NULL;
}

void	lstremove(t_env **lst, char *var)
{
	t_env	*curr;
	t_env	*curr_next;

	curr = *lst;
	while (curr)
	{
		curr_next = curr->next;
		if (ft_strncmp(var, curr->name, ft_strlen(var) + 1) == 0)
			rm_node(curr, lst);
		curr = curr_next;
	}
	init_i_sort(lst);
}

void	init_i_sort(t_env **lst)
{
	t_env	*curr;

	curr = *lst;
	if (!curr)
		return ;
	if (!curr->i_sort)
		return ;
	while (curr)
	{
		curr->i_sort = 0;
		curr = curr->next;
	}
}

void	free_lst_env(t_env **env)
{
	t_env	*next;

	next = (*env)->next;
	lstremove(env, (*env)->name);
	while (next)
	{
		*env = next;
		next = (*env)->next;
		lstremove(env, (*env)->name);
	}
	*env = NULL;
}
