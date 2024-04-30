/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:03:35 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 16:00:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstadd_back(t_env **lst, t_env *new)
{
	t_env	*curr;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	curr = lstlast(*lst);
	curr->next = new;
	new->prev = curr;
}

t_env	*lstnew(char *content)
{
	t_env	*new_node;
	int		i;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	i = 0;
	new_node->equal_flag = 0;
	new_node->value = 0;
	new_node->name = get_substr(content, &i, ST_EQ);
	if (content[i] == '=' && ft_strncmp(new_node->name, "OLDPWD", 6))
	{
		new_node->equal_flag = 1;
		i++;
		new_node->value = get_substr(content, &i, STOP_AT_ENDSTR);
	}
	new_node->i_sort = 0;
	new_node->exported_flag = 1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_env	*lstlast(t_env *lst)
{
	t_env	*curr;

	curr = lst;
	if (!lst)
		return (NULL);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

int	lstsize(void *lst, int type_flag)
{
	int		n;
	t_env	*curr_env;
	t_arg	*curr_arg;

	n = 0;
	if (type_flag == ARG)
	{
		curr_arg = lst;
		while (curr_arg)
		{
			n++;
			curr_arg = curr_arg->next;
		}
		return (n);
	}
	curr_env = lst;
	while (curr_env)
	{
		n++;
		curr_env = curr_env->next;
	}
	return (n);
}
