/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_a_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:28:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/14 12:01:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_node **node, t_node **b, t_node **a)
{
	t_node	*to_push;

	to_push = (*node);
	while (to_push -> index > 0 || to_push -> target -> index > 0)
	{
		print_stack(a, b);
		if (to_push -> above_median == true && \
		to_push -> target -> above_median == true)
			rr(a, b);
		else if (to_push -> above_median == true)
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
	//init_stack_b(b);
	pb(a, b);
	print_stack(a, b);
}

bool	sort_a(t_node **a, t_node **b)
{
	t_node	*cheapest;
	t_node	*to_push;
	
	to_push = *b;
	while (to_push && b)
	{
		define_target(b, a);
		cheapest = find_cheapest(a, b);
		//if (is_sorted(a))
		move_to_a(&cheapest, a, b);
		to_push = to_push -> next;
	}
	if (is_sorted(a))
		return (true);
	return (false);	
}

void	clear_a(t_node **a, t_node **b)
{
	int		i;
	t_node	*to_move;
	int		round;

	i = indexing(a);
	round = 0;
	while (i > 3)
	{
		//printf("i : %d\n", i);
		print_stack(a, b);
		init_stack_b(b);
		printf("ici");
		if (round == 0 && i >= 5)
		{
			pb(a, b);
			init_stack_b(b);
			pb(a, b);
			define_target(a, b);
			i--;
		}
		else if (round == 0)
		{
			printf("ici");
			pb(a, b);
			print_stack(a, b);
			define_target(a, b);
		}
		else
		{
			define_target(a, b);
			to_move = find_cheapest(a, b);
			move_to_b(&to_move, b, a);
			//free(to_move);
		}
		i--;
		round++;
	}
}
