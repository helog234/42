/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_b_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:04:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/29 17:35:38 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	not_above_medium(t_node **a, t_node **b, t_node **to_push)
{
	if ((*to_push)->target -> above_median == false && \
	(*to_push)->above_median == false)
		rrr(a, b, 0);
	else if ((*to_push)-> target -> above_median == false && \
	(*to_push)-> above_median == true)
		rra(a, 0);
	else if ((*to_push)-> target -> above_median == true && \
	(*to_push)-> above_median == false)
		rrb(b, 0);
}

void	above_medium(t_node **a, t_node **b, t_node **to_push)
{
	if ((*to_push)->target -> index > 0 && (*to_push)->index > 0)
		rr(a, b, 0);
	else if ((*to_push)->target -> index > 0 && (*to_push)-> index == 0)
		ra(a, 0);
	else if ((*to_push)->index > 0 && (*to_push)-> target -> index == 0)
		rb(b, 0);
}

void	move_to_a(t_node **a, t_node **b)
{
	t_node	*to_push;

	if (*b == NULL)
		return ;
	to_push = *b;
	while (*b && to_push && to_push->target && \
	(to_push->index > 0 || to_push->target->index > 0))
	{
		indexing(b);
		if (to_push -> target -> above_median == true && \
		to_push -> above_median == true)
			above_medium(a, b, &to_push);
		else if (to_push -> target -> above_median == false || \
		to_push -> above_median == false)
			not_above_medium(a, b, &to_push);
		to_push = *b;
		indexing(b);
		indexing(a);
	}
	pa(a, b, 0);
}

t_node	*find_last(t_node **b)
{
	t_node	*current;

	current = *b;
	while (current -> next)
	{
		current = current -> next;
	}
	return (current);
}

int	cheapest_b(t_node **b, t_node **a)
{
	t_node	*check_push;
	t_node	*last;
	int		len_a;

	check_push = *b;
	len_a = indexing(a) / 3;
	if (check_push -> next == NULL)
		return (0);
	last = find_last(b);
	if (check_push -> target -> index > len_a && \
	check_push -> next -> target -> index < len_a + 1)
		sb(b, 0);
	else if (check_push -> target -> index > len_a && \
	last -> target -> index < len_a + 1)
	{
		rrb(b, 0);
		return (1);
	}
	return (0);
}
