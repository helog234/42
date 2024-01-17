/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_b_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:04:58 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/17 12:29:18 by hgandar          ###   ########.fr       */
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
		/* printf("move to a\n");
		printf("to_push %ld\n", to_push -> value);
		printf("to_push target %ld\n", to_push -> target -> value);
		print_stack(a, b);
		sleep(2); */
		/* if (to_push -> next == NULL)
			break; */
		/* if ((*b) -> next != NULL)
		{
			if (to_push -> target -> above_median == true && to_push -> target -> index > 0)
				ra(a);
			if
		} */
		indexing(b);
		if (to_push -> target -> above_median == true && to_push -> above_median == true)
		{
			if (to_push -> target -> index > 0 && to_push -> index > 0)
				rr(a, b);
			else if (to_push -> target -> index > 0 && to_push -> index == 0)
				ra(a);
			else if (to_push -> index > 0 && to_push -> target -> index == 0)
				rb(b);
		}
		else if (to_push -> target -> above_median == false || to_push -> above_median == false)
		{
			printf("check : %i\n", to_push -> above_median);
			if (to_push -> target -> above_median == false && to_push -> above_median == false)
				rrr(a, b);
			else if (to_push -> target -> above_median == false && to_push -> above_median == true)
				rra(a);
			else if (to_push -> target -> above_median == true && to_push -> above_median == false)
				rrb(b);		
		}
		//to_push = *b;
		indexing(b);
		indexing(a);
	}
	pa(a, b);
	print_stack(a, b);
}

/* void	sort_b(t_node **stack_b)
{
	t_node	*b;
	int		max_b;

	b = *stack_b;
	max_b = (*stack_b) -> max;
	while (b)
	{
		if (b -> value < max_b)
	}
	
} */
