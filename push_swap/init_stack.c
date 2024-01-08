/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:25:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/08 12:34:45 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sign(t_node *node, long i)
{
	if (i < 0)
	{
		node -> negativ = true;
		node -> value = -i;
	}
	else
	{
		node -> negativ = false;
		node -> value = i;
	}
}

t_node	*find_last(t_node *a)
{
	while (a -> next)
		a = a -> next;
	return (a);
}

void	add_back(t_node **a, long i)
{
	t_node	*last;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node -> next = NULL;
	check_sign(&new_node, i);
	if (*a == NULL)
	{
		*a = new_node;
		new_node -> prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last -> next = new_node;
		new_node -> prev = last;
	}	
}

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

int	check_duplicates(t_node *stack, long new_value)
{
	while (stack)
	{
		if (stack -> value == new_value)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

void	init_stack(long *values, t_node **a)
{
	int		i;

	i = 0;
	while (values[i])
	{
		if (values[i] < INT_MIN || values[i] > INT_MAX)
		{
			free_array(values);
			free_stack(a);
			errors(2);
		}
		if (check_duplicates(*a, values[i]))
		{
			free_array(values);
			free_stack(a);
			errors(3);
		}
		add_back(a, values[i]);
	}
}