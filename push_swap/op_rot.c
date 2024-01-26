/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:08:41 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/25 14:42:09 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **head)
{
	t_node	*to_rotate;
	t_node	*new_head;
	t_node	*last_node;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	to_rotate = *head;
	new_head = (*head)-> next;
	last_node = find_last(head);
	to_rotate -> prev = last_node;
	last_node -> next = to_rotate;
	to_rotate -> next = NULL;
	new_head -> prev = NULL;
	*head = new_head;
	indexing(head);
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
