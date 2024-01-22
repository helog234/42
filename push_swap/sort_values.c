/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:21:09 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/22 12:50:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_node **stack)
{
	t_node	*current;
	t_node	*max_node;
	int		max;

	max = INT_MIN;
	current = *stack;
	while (current)
	{
		if (current -> value > max)
		{
			max_node = current;
			max = current -> value;
		}
		current = current -> next;
	}
	return (max_node);
}

t_node	*find_min(t_node **stack)
{
	t_node	*current;
	t_node	*min_node;
	int		min;

	min = INT_MAX;
	current = *stack;
	while (current)
	{
		if (current -> value < min)
		{
			min_node = current;
			min = current -> value;
		}
		current = current -> next;
	}
	return (min_node);
}

void	sort_three(t_node **stack)
{
	t_node	*min;
	t_node	*max;

	min = find_min(stack);
	max = find_max(stack);
	while (is_sorted(stack) == false)
	{
		indexing(stack);
		if (max -> index == 0)
			ra(stack);
		else if (min -> index == 2 || max -> index == 1)
			rra(stack);
		else if (min -> index == 1)
			sa(stack);
		min = find_min(stack);
		max = find_max(stack);
	}
}

void	sort_values(t_node **a, t_node **b)
{
	int		round;

	round = 0;
	clear_a(a, b, round);
	sort_three(a);
	indexing(a);
	if (sort_a(a, b) == false)
	{
		print_stack(a, b);
		free_stack(a);
		free_stack(b);
		errors(4);
	}
}
