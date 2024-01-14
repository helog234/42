/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:17:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/12 09:25:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(long *all)
{
/* 	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all[i])
		i++;
	while (j < i)
	{
		free(all[j]);
		j++;
	} */
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

void	errors(int i)
{
	//Attention, changer pour juste Error\n une fois que c'est bon
	if (i == 0)
		ft_printf("Error : Not enough argument\n");
	else if (i == 1)
		ft_printf("Error : while splitting argv\n");
	else if (i == 2)
		ft_printf("Error : while initiating stack\n");
	else if (i == 3)
		ft_printf("Error : Duplicates are not allowed\n");
	else if (i == 4)
		ft_printf("Error : Could not sort\n");
	exit(EXIT_FAILURE);
}
