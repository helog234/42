/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:17:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/23 17:46:22 by hgandar          ###   ########.fr       */
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

void	free_split(char *str[])
{
	int	i;
	
	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
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
	if (i == 0)
		ft_putstr_fd("Error\n", 2);
	else if (i == 1)
		ft_putstr_fd("Error\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
