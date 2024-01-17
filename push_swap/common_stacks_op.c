/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_stacks_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/17 16:14:03 by hgandar          ###   ########.fr       */
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
		//printf("current from index : %i\n", current_from -> index);
		//printf("current to index : %i\n", current_to -> index);
		//printf("cost : %ld\n", cost);
		if (current_from -> index + current_to -> index < cost)
		{
			cost = current_from -> index + current_to -> index;
			best_fit = current_from;
			if (cost == 0)
				break ;
		}
		current_from -> cheapest = false;
		current_from = current_from -> next;
	}
	best_fit -> cheapest = true;
/* 	printf("best_fit : %i\n", best_fit -> index);
	printf("best_fit value: %lu\n", best_fit -> value); */
	return (best_fit);
}

void	closest_bigger(t_node **node, t_node **a)
{
	t_node	*stack_to;
	t_node	*best_target;
	int		diff;

	stack_to = *a;
	//printf("target b\n");
	//print_stack(node, b);
	diff = INT_MAX;
	while (stack_to)
	{
		//printf("b_stack value iteration: %ld\n", stack_to -> value);
		//printf("b_stack value : %ld\n", stack_to -> value);
		//printf("(*node)-> value : %ld\n",(*node)-> value);
		//printf("diff av: %ld\n", diff);
		if ((*node)-> value < stack_to -> min)
		{
			best_target = find_min(&stack_to);
			break;
		}
		else if ((*node)-> value > stack_to -> max)
		{
			best_target = find_min(&stack_to);
			break;
		}
		else if (stack_to -> value > (*node)-> value && stack_to -> value - (*node)-> value < diff)
		{
			//printf("diff : %i\n", diff);
			//printf("diff av: %i\n", diff);
			/* printf("b value : %ld\n",(*node)-> value);
			printf("target in a : %ld\n", stack_to -> value); */
			//printf("(*node)-> value : %ld\n",(*node)-> value);
			diff = stack_to -> value - (*node)-> value;
			//printf(" diff : %i\n", diff);
			best_target = stack_to;
		}
		stack_to = stack_to -> next;
	}
/* 	printf("target b final ----------- \n");
	printf("diff : %i\n", diff);
	printf("node to move to a : %ld\n", (*node)-> value);
	printf("target in a : %ld\n", best_target -> value); */
	(*node)-> target = best_target;
}

void	closest_smaller(t_node **node, t_node **b)
{
	int		diff;
	t_node	*stack_to;
	t_node	*best_target;

	diff = INT_MAX;
	stack_to = *b;
	//printf("target b\n");
	diff = INT_MAX;
	while (stack_to)
	{
		//printf("b_stack value : %ld\n", stack_to -> value);
		//printf("(*node)-> value : %ld\n",(*node)-> value);
		//printf("diff av: %ld\n", diff);
		if ((*node)-> value < stack_to -> min)
		{
			best_target = find_min(&stack_to);
			break;
		}
		else if ((*node)-> value > stack_to -> max)
		{
			best_target = find_max(&stack_to);
			break;
		}
		else if ((*node)-> value < stack_to -> value && stack_to -> value < diff)
		{
		/* 	printf("diff av: %i\n", diff);
			printf("b_stack value : %ld\n", stack_to -> value);
			printf("(*node)-> value : %ld\n",(*node)-> value); */
			diff = stack_to -> value;
			//printf(" diff : %i\n", diff);
			best_target = stack_to;
		}
		stack_to = stack_to -> next;
	}
	(*node)-> target = best_target;
}

void	define_target(t_node **stack_from, t_node **stack_to, int flag)
{
	//int		i;
	t_node	*origin;

	//i = indexing(stack_to);
	origin = *stack_from;
	//print_stack(stack_from, stack_to);
	while (origin)
	{
		if (flag == 0)
			closest_smaller(&origin, stack_to);
		else
			closest_bigger(&origin, stack_to);	
		origin = origin -> next;
	}
}
