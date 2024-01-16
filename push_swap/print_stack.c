/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:19:05 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/16 12:33:18 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node **a, t_node **b)
{
	t_node	*current_a;
	t_node	*current_b;
	//char	*temp;

	current_a = *a;
	current_b = *b;
	ft_printf("a");
	ft_printf(" | ");
	ft_printf("b");
	ft_printf("\n");
	while (current_a || current_b)
	{
		if (current_a == NULL)
		{
			ft_printf("");
			ft_printf(" | ");
		}
		if (current_b == NULL)
		{
			ft_printf("");
		}
		if (current_a != NULL)
		{
			ft_printf(ft_itoa(current_a -> value));
			ft_printf(" | ");
			current_a = current_a -> next;
		}
		if (current_b != NULL)
		{
			ft_printf(ft_itoa(current_b -> value));
			current_b = current_b -> next;
		}
		ft_printf("\n");
	}
}
