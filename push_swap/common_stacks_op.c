/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_stacks_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/25 12:15:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_median(t_node **stack, int length)
{
	t_node	*to_set;
	int		median;

	to_set = *stack;
	if (to_set -> next == NULL)
	{
		to_set -> above_median = true;
		return ;
	}
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
	t_node	*min_node;
	t_node	*max_node;
	int		i;

	to_index = *stack;
	i = 0;
	if (to_index -> next == NULL)
	{
		to_index -> index = i;
		to_index -> above_median = true;
		return (0);
	}
	min_node = find_min(stack);
	max_node = find_max(stack);
	while (to_index)
	{
		to_index -> index = i;
		to_index -> min = min_node -> value;
		to_index -> max = max_node -> value;
		i++;
		to_index = to_index -> next;
	}
	set_median(stack, i - 1);
	return (--i);
}

void	set_cost_a(t_node **a, t_node **b)
{
	int	len_a;
	int	len_b;
	t_node	*current_a;
	
	len_a = indexing(a);
	len_b = indexing(b);
	current_a = *a;
	while (current_a)
	{
		current_a -> cost = current_a -> index;
		if(!current_a -> above_median)
			current_a -> cost = len_a - (current_a -> index);
		if (current_a -> target -> above_median)
			current_a -> cost += current_a -> target -> index;
		else
			current_a -> cost += len_b - (current_a -> target -> index);
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

void	closest_bigger(t_node **node, t_node **a, long diff)
{
	t_node	*stack_to;
	t_node	*best_target;

	stack_to = *a;
	while (stack_to)
	{
		if ((*node)-> value < stack_to -> min || \
		(*node)-> value > stack_to -> max)
		{
			best_target = find_min(&stack_to);
			break ;
		}
		else if (stack_to -> value > (*node)-> value && \
		stack_to -> value - (*node)-> value < diff)
		{
			diff = stack_to -> value - (*node)-> value;
			best_target = stack_to;
		}
		stack_to = stack_to -> next;
	}
	(*node)-> target = best_target;
}

long	normalize_negativ(long diff)
{
	if (diff > 0)
		diff = - diff;
	return (diff);
}

t_node	*check_min_max(int value, t_node **stack_to)
{
	if (value < (*stack_to)-> min)
		return (find_min(stack_to));
	else if (value > (*stack_to)-> max)
		return (find_max(stack_to));
	else
		return (NULL);
}

void	closest_smaller(t_node **node, t_node **b, long diff)
{
	t_node	*stack_to;
	t_node	*best_target;
	long	current_diff;

	stack_to = *b;
	while (stack_to)
	{
		current_diff = normalize_negativ(((*node)->value - stack_to->value));
		if (check_min_max((*node)-> value, &stack_to) != NULL)
		{
			best_target = check_min_max((*node)-> value, &stack_to);
			break ;
		}
		else if ((*node)-> value < stack_to -> value && \
		stack_to -> value < diff)
		{
			diff = stack_to -> value;
			best_target = stack_to;
		}
		else if ((*node)->value > stack_to -> value && current_diff < diff)
			best_target = stack_to;
		stack_to = stack_to -> next;
	}
	(*node)-> target = best_target;
}

void	define_target(t_node **stack_from, t_node **stack_to, int flag)
{
	t_node	*origin;
	long	diff;

	origin = *stack_from;
	diff = LLONG_MAX;
	while (origin)
	{
		if (flag == 0)
		{
			if ((*stack_to)-> next == NULL)
			{
				while (origin)
				{
					origin -> target = *stack_to;
					origin = origin -> next;
				}
				return ;
			}
			else
				closest_smaller(&origin, stack_to, diff);
		}
		else
			closest_bigger(&origin, stack_to, diff);
		origin = origin -> next;
	}
}

