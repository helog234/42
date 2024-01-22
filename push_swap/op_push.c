/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:08:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/22 12:06:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **target, t_node **origin)
{
	t_node	*to_push;

	if (origin == NULL)
		return ;
	to_push = *origin;
	*origin = (*origin)-> next;
	to_push -> prev = NULL;
	if (*target == NULL)
	{
		*target = to_push;
		to_push -> next = NULL;
	}
	else
	{
		(*target)-> prev = to_push;
		to_push -> next = *target;
		*target = to_push;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
