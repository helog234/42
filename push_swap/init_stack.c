/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:25:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/26 12:26:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_add(t_node *a, long values)
{
	t_node	*current;

	current = a;
	if (values == 2147483648 || check_duplicates(a, values) == 1)
	{
		free_stack(&a);
		errors(3);
	}
	while (current -> next)
	{
		current = current -> next;
	}
	return (current);
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
		last = find_last_add(*a, i);
		last -> next = new_node;
		new_node -> prev = last;
	}
	new_node -> value = i;
}

int	check_duplicates(t_node *stack, long new_value)
{
	while (stack)
	{
		if (stack-> value == new_value)
			return (1);
		stack = stack-> next;
	}
	return (0);
}

void	init_stack_a(long values, t_node **a)
{
	if (values < INT_MIN || values > INT_MAX)
	{
		free_stack(a);
		errors(2);
	}
	add_back(a, values);
}
