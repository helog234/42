/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_b_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:04:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/16 16:57:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_node **node, t_node **a, t_node **b)
{
	t_node	*to_push;
	int		i;

	if (*b == NULL)
		return ;
	if (node == NULL)
		to_push = (*a) -> target;
	else
		to_push = (*node);
	i = indexing(a);
	while (*b && to_push && to_push->target && (to_push->index > 0 || to_push->target->index < i))
	{
		printf("move to a\n");
		printf("to_push %ld\n", to_push -> value);
		printf("to_push target %ld\n", to_push -> target -> value);
		print_stack(a, b);
		sleep(2);
		if (to_push -> target -> index == 0 || to_push -> target -> above_median == true )
			ra(a);
		else if (to_push -> target -> above_median == false && to_push -> target -> index < i)
			rra(a);
		else if (to_push -> above_median == false)
			rrb(b);
		else if (to_push -> above_median == true && to_push -> index > 0)
			rb(b);
		//to_push = *b;
		i = indexing(a);
		indexing(b);
	}
	pa(a, b);
	print_stack(a, b);
}
