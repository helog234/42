/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:23:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/16 16:07:40 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_node
{
	long			value;
	int				index;
	bool			above_median;
	bool			cheapest;
	bool			min;
	bool			max;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

void	init_stack_a(long *values, t_node **a);
t_node	*find_last(t_node *a);
void	sort_values(t_node **a, t_node **b);
void	clear_a(t_node **a, t_node **b);
void	move_to_b(t_node **node, t_node **b, t_node **a);
void	define_target(t_node **stack_from, t_node **stack_to, int flag);
void	closest_smaller(t_node **node, t_node **b);
t_node	*find_cheapest(t_node **a, t_node **b);
int		indexing(t_node **stack);
void	set_median(t_node **stack, int length);
void	free_all(long *all);
void	free_stack(t_node **head);
bool	is_sorted(t_node *stack);
void	push(t_node **target, t_node **origin);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rotate(t_node **head);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	swap(t_node **head);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	reverse_rotate(t_node **head);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	print_stack(t_node **a, t_node **b);
void	sort_three(t_node **stack);
t_node	*find_min(t_node **stack);
t_node	*find_max(t_node **stack);
void	move_to_a(t_node **node, t_node **a, t_node **b);
bool	sort_a(t_node **a, t_node **b);
void	errors(int i);
void	init_stack_b(t_node **b);
void	sort(t_node **a);
void	closest_bigger(t_node **node, t_node **b);
#endif
