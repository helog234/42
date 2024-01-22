/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_b_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:04:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/22 12:02:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	not_above_medium(t_node **a, t_node **b, t_node **to_push)
{
	if ((*to_push)->target -> above_median == false && \
	(*to_push)->above_median == false)
		rrr(a, b);
	else if ((*to_push)-> target -> above_median == false && \
	(*to_push)-> above_median == true)
		rra(a);
	else if ((*to_push)-> target -> above_median == true && \
	(*to_push)-> above_median == false)
		rrb(b);
}

void	above_medium(t_node **a, t_node **b, t_node **to_push)
{
	if ((*to_push)->target -> index > 0 && (*to_push)->index > 0)
		rr(a, b);
	else if ((*to_push)->target -> index > 0 && (*to_push)-> index == 0)
		ra(a);
	else if ((*to_push)->index > 0 && (*to_push)-> target -> index == 0)
		rb(b);
}

void	move_to_a(t_node **node, t_node **a, t_node **b)
{
	t_node	*to_push;

	if (*b == NULL)
		return ;
	to_push = (*node);
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
	pa(a, b);
}
