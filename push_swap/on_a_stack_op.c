/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_a_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:28:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/17 12:06:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_node **node, t_node **b, t_node **a)
{
	t_node	*to_push;

	to_push = (*node);
	printf("to push : %ld\n", to_push -> value);
	printf("to push target : %ld\n", to_push -> target -> value);
	while (to_push -> index > 0 || to_push -> target -> index > 0)
	{
		print_stack(a, b);
		if (to_push -> above_median == true && \
		to_push -> target -> above_median == true && to_push->index > 0 && to_push -> target -> index > 0)
			rr(a, b);
		else if (to_push -> above_median == true && to_push->index > 0 && to_push -> target -> index > 0)
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

void	sort(t_node **a)
{
	t_node	*min;
	t_node	*current;

	min = find_min(a);
	printf("%ld\n", min -> value);
	current = *a;
	while (current)
	{
		if (is_sorted(*a) == true)
			break ;
		sleep(3);
		printf("ici\n");
		print_stack(a, &min);
		if (current -> value > min -> value)
		{
			ra(a);
			current = *a;
		}
		else
			current = current -> next;
	}
	printf("fin sort\n");
	printf("%ld\n", current -> value);
}

bool	sort_a(t_node **a, t_node **b)
{
	t_node	*cheapest;
	t_node	*to_push;

	to_push = *b;
	printf("avant while\n");
	print_stack(a, b);
	while (to_push && b)
	{
		indexing(a);
		define_target(b, a, 1);
		cheapest = find_cheapest(b, a);
		sleep(2);
		//printf("cheapest : %ld\n", cheapest -> value);
		//printf("cheapest target : %ld\n", cheapest -> target -> value);
		move_to_a(&cheapest, a, b);
		indexing(a);
		to_push = *b;
	}
	sort(a);
	if (is_sorted(*a))
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
	while (i > 2)
	{
		printf("%i\n", i);
		//printf("i : %d\n", i);
		print_stack(a, b);
		//init_stack_b(b);
		//printf("ici");
		if (round == 0 && i >= 5)
		{
			//printf("ici\n");
			pb(a, b);
			//init_stack_b(b);
			pb(a, b);
			//define_target(a, b);
			i--;
		}
		else if (round == 0)
		{
			//printf("ici\n");
			//printf("i : %d\n", i);
			pb(a, b);
			print_stack(a, b);
			define_target(a, b, 0);
		}
		else
		{
			//printf("else");
			//sort_b(b);
			define_target(a, b, 0);
			to_move = find_cheapest(a, b);
			move_to_b(&to_move, b, a);
			//free(to_move);
		}
		i--;
		round++;
		indexing(a);
		indexing(b);
		print_stack(a, b);
		/* printf("%i\n", i);
		printf("%i\n", round); */
	}
}
