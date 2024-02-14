/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:46:51 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/29 17:16:59 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	if (second->next != NULL)
		second->next->prev = first;
	first -> prev = second;
	first -> next = second -> next;
	second -> next = first;
	second -> prev = NULL;
	*head = second;
}

void	sa(t_node **a, int flag)
{
	swap(a);
	if (flag == 0)
		ft_printf("sa\n");
}

void	sb(t_node **b, int flag)
{
	swap(b);
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b, int flag)
{
	swap(a);
	swap(b);
	if (flag == 0)
		ft_printf("ss\n");
}
