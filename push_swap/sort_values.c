/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:21:09 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/09 17:45:48 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_node **node, t_node **b)
{
	
}

t_node	*find_cheapest(t_node **a, t_node **b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*best_fit;
	long	cost;
		
	current_a = *a;
	current_b = *b;
	cost = INT_MAX;
	while (current_a)
	{
		current_b = current_a -> target;
		if (current_a -> index + current_b -> index < cost)
		{
			cost = current_a -> index + current_b -> index;
			if (cost == 0)
				break;
			best_fit = current_a;
		}
		current_a -> cheapest = false;
		current_a = current_a -> next;
	}
	best_fit -> cheapest = true;
	return (best_fit -> index);
}

t_node	*closest_smaller(t_node **node, t_node **b)
{
	int		diff;
	t_node	*max;
	t_node	*min;
	t_node	*b_stack;
	
	diff = (*node) -> value - (*b) -> value;
	b_stack = *b;
	max = NULL;
	min = NULL;
	while (b_stack)
	{
		if (b_stack -> value > max -> value || max == NULL)
			max = b_stack;
		if (b_stack -> value < min -> value && 	b_stack -> value < min -)
			min = b_stack;
		b_stack = b_stack -> next;
	}
	if (min == NULL)
		return (max);
	else
		return (min);
}

void	define_target(t_node **a, t_node **b)
{
	int		i;
	t_node	*a_stack;
	
	i = indexing(b);
	a_stack = *a;
	while (a_stack)
	{
		if (i == 0)
			break;
		a_stack -> target = closest_smaller(&a_stack, b);
		a_stack = a_stack -> next;
	}
}

void	clear_a(t_node **a, t_node **b)
{
	int		i;
	t_node	*to_move;
	int		round;
	
	i = indexing(a);
	round = 0;
	while (i >= 3)
	{
		if (round == 0 && i >= 5)
		{
			pb(a, b);
			pb(a, b);
			define_target(a, b);
			i--;
		}
		else if (round == 0)
		{
			pb(a, b);
			define_target(a, b);
		}
		else
		{
			define_target(a, b);
			to_move = find_cheapest(a, b);
			move_to_b(&to_move, b);
		}
		i--;
		round++;
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
	return (i--);
}

void	sort_values(t_node **a, t_node **b)
{
	move_to_b

	
	
	
}