/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:21:09 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/10 16:19:59 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a()
{
	t_node *cheapest;
	
	indexing(a);
	indexing(b);
	define_target_a();
	cheapest = find_cheapest_a(a, b);
	
}

void	sort_three()
{
	
}

void	move_to_b(t_node **node, t_node **b, t_node **a)
{
	t_node	*to_push;

	to_push = (*node);
	while (to_push -> index > 0 || to_push -> target.index > 0)
	{
		if (to_push -> above_median == true && \
		to_push -> target.above_median == true)
			rr(a, b);
		else if (to_push -> above_median == true)
			ra(a);
		else if (to_push -> target.above_median == true)
			rb(b);
		else if (to_push -> above_median == false && \
		to_push -> target.above_median == false)
			rrr(a, b);
		else if (to_push -> above_median == false)
			rra(a);
		else if (to_push -> target.above_median == false)
			rrb(b);
		indexing(a);
		indexing(b);
	}
	pb(a, b);
}


void	clear_a(t_node **a, t_node **b)
{
	int		i;
	t_node	*to_move;
	int		round;
	int		lengh;

	i = indexing(a);
	round = 0;
	lengh = i;
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
			define_target_b(a, b);
		}
		else
		{
			define_target(lengh, a, b);
			to_move = find_cheapest_b(a, b);
			move_to_b(&to_move, b, a);
		}
		i--;
		round++;
	}
}

void	sort_values(t_node **a, t_node **b)
{
	clear_a(a, b);
	sort_three();
	move_to_a();

	
	
	
}