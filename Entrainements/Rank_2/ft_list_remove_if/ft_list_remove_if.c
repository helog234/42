/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:00:49 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/22 10:15:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
	struct s_list *next;
	void *data;
} t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *temp;
	t_list *prev = NULL;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	current = *begin_list;
	while (current)
	{
		if (!cmp(current->data, data_ref))
		{
			if (prev)
			{
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
t_list *find_last(t_list **stack)
{
	t_list *last;

	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void creat_node(t_list **stack)
{
	t_list *new;
	t_list *last;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		last = find_last(stack);
		last->next = new;
	}
}

int is_prime(int nbr)
{
	int i;

	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void add_value(t_list **stack)
{
	t_list *current;
	int i;
	int *data;
	
	current = *stack;
	i = 2;
	while (current)
	{
		data = malloc(sizeof(int));
		if (data == NULL)
			exit(1) ;
		if (is_prime(i) == 1)
		{
			*data = i;
		}
		else
			*data = 6;
		current->data = data;
		i++;
		current = current->next;
	}
}
int cmp_int(void *data1, void *data_ref)
{
	return (*(int *)data1 == *(int *)data_ref) ? 0 : 1;
}
void	print_stack(t_list **stack)
{
	t_list	*current;
	
	current = *stack;
	while (current)
	{
		int *data = (int *)current->data;
		printf("data %i\n", *data);
		current = current->next;
	}
}

int main(void)
{
	t_list *stack;
	int i;
	int data_ref;

	stack = NULL;
	i = 0;
	data_ref = 6;
	while (i < 10)
	{
		creat_node(&stack);
		i++;
	}
	add_value(&stack);
	print_stack(&stack);
	printf("--------\n");
	ft_list_remove_if(&stack, &data_ref, cmp_int);
	print_stack(&stack);
}
