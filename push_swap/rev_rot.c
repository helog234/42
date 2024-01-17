/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:26:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/17 14:58:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*to_move;
	t_node	*init_head;
	t_node	*new_last;

	if (!*head)
		return ;
	to_move = find_last(*head, INT_MAX + 1);
	init_head = *head;
	new_last = to_move -> prev;
	to_move -> next = init_head;
	init_head -> prev = to_move;
	new_last -> next = NULL;
	to_move -> prev = NULL;
	*head = to_move;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
