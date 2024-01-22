/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_a_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:28:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/22 16:59:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_node **node, t_node **b, t_node **a)
{
	t_node	*to_push;

	to_push = (*node);
	while ((to_push -> index > 0 || to_push -> target -> index > 0) && b)
	{
		if (to_push -> above_median == true && \
		to_push -> target -> above_median == true && \
		to_push->index > 0 && to_push -> target -> index > 0)
			rr(a, b);
		else if (to_push -> above_median == true && \
		to_push->index > 0 && to_push -> target -> index > 0)
			ra(a);
		else if (to_push -> target -> above_median == true)
			rb(b);
		else if (to_push -> above_median == false && \
		to_push -> target -> above_median == false)
			rrr(a, b);
		else if (to_push -> above_median == false)
			rra(a);
		else if (to_push -> target -> above_median == false)
			rrb(b);
		indexing(a);
		indexing(b);
	}
	pb(a, b);
}

void	sort(t_node **a)
{
	t_node	*min_node;
	t_node	*current;

	current = *a;
	while (current)
	{
		if (is_sorted(a) == true)
			break ;
		indexing(a);
		min_node = find_min(a);
		if (current -> value > min_node -> value && \
		min_node -> above_median == true)
		{
			ra(a);
			current = *a;
		}
		else if (current -> value > min_node -> value && \
		min_node -> above_median == false)
		{
			rra(a);
			current = *a;
		}
		else
			current = current -> next;
	}
}

bool	sort_a(t_node **a, t_node **b)
{
	t_node	*cheapest;
	t_node	*to_push;

	to_push = *b;
	while (to_push && b)
	{
		indexing(a);
		define_target(b, a, 1);
		cheapest = find_cheapest(b, a);
		move_to_a(&cheapest, a, b);
		indexing(a);
		to_push = *b;
	}
	sort(a);
	if (is_sorted(a))
		return (true);
	return (false);
}

void	clear_a(t_node **a, t_node **b, int round)
{
	int		i;
	t_node	*to_move;

	i = indexing(a);
	while (i > 2)
	{
		if (round == 0 && i >= 5)
		{
			pb(a, b);
			pb(a, b);
			i--;
		}
		else if (round == 0)
			pb(a, b);
		else
		{
			define_target(a, b, 0);
			to_move = find_cheapest(a, b);
			move_to_b(&to_move, b, a);
		}
		i--;
		round++;
		indexing(a);
		indexing(b);
	}
}
