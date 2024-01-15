/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_b_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:04:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/15 17:05:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_node **node, t_node **a, t_node **b)
{
	t_node	*to_push;

	if (*b == NULL)
		return ;
	to_push = (*node);
	while (*b && to_push && to_push->target && (to_push->index > 0 || to_push->target->index > 0))
	{
		printf("move to a\n");
		print_stack(a, b);
		if (to_push -> above_median == true && \
		to_push -> target -> above_median == true && to_push->index > 0 && to_push -> target -> index > 0)
			rr(a, b);
		else if (to_push -> above_median == true && to_push->index > 0)
			rb(a);
		else if (to_push -> target -> above_median == true && to_push -> target -> index > 0)
			ra(b);
		else if (to_push -> above_median == false && \
		to_push -> target -> above_median == false)
			rrr(a, b);
		else if (to_push -> above_median == false)
			rrb(b);
		else if (to_push -> target -> above_median == false)
			rra(a);
		indexing(a);
		indexing(b);
	}
	pa(a, b);
	print_stack(a, b);
}
