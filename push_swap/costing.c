/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:45:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/29 17:47:33 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_index(t_node *node_a, t_node *node_b)
{
	int	a;
	int	b;

	a = node_a -> index;
	b = node_b -> index;
	if (a < b)
		return (b);
	else
		return (a);
}

void	set_cost_a(t_node **a, int len_a, int len_b)
{
	t_node	*current_a;

	current_a = *a;
	while (current_a)
	{
		if (current_a->above_median && current_a->target->above_median && \
		current_a->index > 0 && current_a -> target > 0)
			current_a -> cost = move_index(current_a, current_a -> target);
		else if (current_a->above_median && current_a->target->above_median)
			current_a->cost = current_a->index + current_a->target->index;
		else if (!(current_a->above_median) && \
		!(current_a->target->above_median))
			current_a->cost = len_a - (current_a->index) + 1 \
			+ len_b - (current_a -> target -> index) + 1;
		else if (current_a->above_median && !(current_a->target->above_median))
			current_a->cost = current_a->index + \
			(len_b - (current_a->target->index));
		else if (!(current_a->above_median) && current_a->target->above_median)
			current_a->cost = len_a - (current_a->index) + \
			current_a->target->index;
		current_a = current_a -> next;
	}
}

t_node	*find_cheapest(t_node **stack_a)
{
	t_node	*current;
	t_node	*best_fit;
	long	cheapest;

	cheapest = LLONG_MAX;
	current = *stack_a;
	while (current)
	{
		if (current -> cost < cheapest)
		{
			best_fit = current;
			cheapest = current -> cost;
		}
		current -> cheapest = false;
		current = current -> next;
	}
	best_fit -> cheapest = true;
	return (best_fit);
}
