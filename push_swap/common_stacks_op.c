/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_stacks_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/13 21:19:01 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_median(t_node **stack, int length)
{
	t_node	*to_set;
	int		median;

	to_set = *stack;
	median = length / 2;
	while (to_set)
	{
		if (to_set -> index <= median)
			to_set -> above_median = true;
		else
			to_set -> above_median = false;
		to_set = to_set -> next;
	}
}

int	indexing(t_node **stack)
{
	t_node	*to_index;
	int		i;

	to_index = *stack;
	i = 0;
	while (to_index)
	{
		to_index -> index = i;
		i++;
		to_index = to_index -> next;
	}
	set_median(stack, i - 1);
	return (i--);
}

t_node	*find_cheapest(t_node **stack_from, t_node **stack_to)
{
	t_node	*current_from;
	t_node	*current_to;
	t_node	*best_fit;
	long	cost;

	current_from = *stack_from;
	current_to = *stack_to;
	cost = INT_MAX;
	best_fit = malloc(sizeof(t_node));
	while (current_from)
	{
/* 		current_b = current_a -> target;
		if (current_a -> index == 0 && current_b -> index == 0)
		{
			best_fit = currrent_a;
			break;
		}
		current_a = current_a -> next; */

		current_to = current_from -> target;
		if (current_from -> index + current_to -> index < cost)
		{
			cost = current_from -> index + current_to -> index;
			best_fit = current_to;
			if (cost == 0)
				break ;
		}
		current_from -> cheapest = false;
		current_from = current_from -> next;
	}
	best_fit -> cheapest = true;
	return (best_fit);
}

void	closest_smaller(t_node **node, t_node **b)
{
	long	diff;
	t_node	*b_stack;
	t_node	*best_target;

	diff = INT_MAX;
	b_stack = *b;
	while (b_stack)
	{
		if (b_stack -> value < (*node)-> value && (*node)-> value > diff)
		{
			diff = b_stack -> value;
			best_target = b_stack;
		}
		b_stack = b_stack -> next;
	}
	if (diff == INT_MAX)
		(*node)-> target = find_max(b);
	else
		(*node)-> target = best_target;
}

void	define_target(t_node **stack_from, t_node **stack_to)
{
	int		i;
	t_node	*a_stack;

	i = indexing(stack_to);
	a_stack = *stack_from;
	while (a_stack)
	{
		if (i == 0)
			break ;
		closest_smaller(&a_stack, stack_to);
		a_stack = a_stack -> next;
	}
}
