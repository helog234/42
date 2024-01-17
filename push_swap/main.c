/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:26:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/17 20:48:56 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	values_array(int argc, char *argv[], t_node **a)
{
	char	**new_argv;
	long	*node_array;
	long	i;
	int		j;

	i = 1;
	new_argv = NULL;
	argv = &argv[i];
	if (argc == 2)
	{
		new_argv = ft_split(argv[0], ' ');
		if (new_argv == NULL)
			errors(1);
	}
	else
		new_argv = argv;
	while (new_argv[i])
		i++;
	node_array = malloc((i + 1) * sizeof(long));
	if (!node_array)
		errors(4);
	i = 0;
	while (new_argv[i])
	{	
		j = 1;
		 while (new_argv[i][j])
		{
			//printf("%c\n", new_argv[i][j]);
			if (ft_isdigit(new_argv[i][j]) == 0)
			{
				//printf("%i\n", ft_isdigit(new_argv[i][j]));
				errors(1);
			}
			j++;
		}
		init_stack_a((long)ft_atoi(new_argv[i]), a) ;
		i++;
	}
}

bool	is_sorted(t_node *stack)
{

	while (stack -> next)
	{
		if (stack -> value > stack -> next -> value)
			return (false);
		stack = stack -> next;
	}
	
/* 	t_node *current_node;
	
	current_node = stack;
	indexing(&stack);
	while (current_node)
	{
		print_stack(&stack, &current_node);
		if (current_node -> value > current_node -> next -> value)
			return (false);
		current_node = current_node -> next;
	} */
	//printf("true\n");
	return (true);
}

int	main(int argc, char *argv[])
{
	//long			*values;
	t_node	*a;
	t_node	*b;
	//long	i;

	
	a = NULL;
	b = NULL;
	//i = 0;
	if (argc < 2)
		errors(0);
	values_array(argc, argv, &a);
	/* while (values[i])
	{
		printf("value %ld: %ld\n", i, values[i]);
		//probleme quand 0 a la fin car stop
		i++;
	} */
	//init_stack_a(values, &a);
	if (is_sorted(a))
		return (0);
	else if (indexing(&a) == 3)
		sort_three(&a);
	//free(values ??)
	else
		sort_values(&a, &b);
	return (0);
}
