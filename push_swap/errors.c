/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:17:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/10 15:32:09 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(int *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all[i])
		i++;
	while (j < i)
	{
		free(all[j]);
		j++;
	}
	free(all);
}

void	free_stack(t_node **head)
{
	t_node	*current;
	t_node	*tmp;

	current = *head;
	while (current)
	{
		tmp = current -> next;
		free(current);
		current = tmp;
	}
	*head = NULL;
}
