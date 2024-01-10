/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:25:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/10 15:19:09 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *a)
{
	while (a -> next)
		a = a -> next;
	return (a);
}

void	add_back(t_node **a, long i)
{
	t_node	*last;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node -> next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node -> prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last -> next = new_node;
		new_node -> prev = last;
	}
	new_node -> value = i;
}

int	check_duplicates(t_node *stack, long new_value)
{
	while (stack)
	{
		if (stack -> value == new_value)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

void	init_stack(long *values, t_node **a)
{
	int		i;

	i = 0;
	while (values[i])
	{
		if (values[i] < INT_MIN || values[i] > INT_MAX)
		{
			free_array(values);
			free_stack(a);
			errors(2);
		}
		if (check_duplicates(*a, values[i]))
		{
			free_array(values);
			free_stack(a);
			errors(3);
		}
		add_back(a, values[i]);
	}
}
