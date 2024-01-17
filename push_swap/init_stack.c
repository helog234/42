/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:25:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/17 20:41:58 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *a, long values)
{
	while (a -> next)
	{
		if (values == 2147483648 || check_duplicates(a, values) == 1)
		{
			//free_all(values);
			free_stack(&a);
			errors(3);
		}
		a = a -> next;
	}
	return (a);
}

void	add_back(t_node **a, long i)
{
	t_node	*last;
	t_node	*new_node;

	//printf("add: %ld\n", i);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node -> next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node -> prev = NULL;
	}
	else
	{
		last = find_last(*a, i);
		last -> next = new_node;
		new_node -> prev = last;
	}
	new_node -> value = i;
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
/* void	init_stack_b(t_node **b)
{
	t_node *new_node;
	
	//new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node -> prev = NULL;
	if (*b == NULL)
	{
		*b = new_node;
		new_node -> next = NULL;
	}
	else
	{
		(*b) -> prev = new_node;
		new_node -> next = (*b);
		*b = new_node;
	} 
	indexing(b);
} */

void	init_stack_a(long values, t_node **a)
{
	//printf("%ld\n", values);
	if (values < INT_MIN || values > INT_MAX)
	{
		//free_all(values);
		free_stack(a);
		errors(2);
	}
	//printf("node (init a) %ld: %ld\n",i, values[i]);
	add_back(a, values);

}
