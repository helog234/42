/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:26:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/14 18:29:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*values_array(int argc, char *argv[])
{
	char	**new_argv;
	long	*node_array;
	long	i;

	i = 1;
	new_argv = NULL;
	argv = &argv[i];
	if (argc == 1)
	{
		while (argv[i])
	{
		new_argv = ft_split(argv[i], ' ');
		//printf("argv %ld: %s\n",i, argv[i]);
		if (new_argv == NULL)
			errors(1);
		//j++;
		i++;
	}
	}
	else
		new_argv = argv;
	//new_argv = ft_split(argv[i], ' ');
	i = 0;
	while (new_argv[i])
	{
		//printf("argv %ld: %s\n",i, argv[i]);
		i++;
	}
	node_array = malloc((i + 1) * sizeof(long));
	if (!node_array)
		errors(1);
	i = 0;
	while (new_argv[i])
	{
		node_array[i] = (long)ft_atoi(new_argv[i]);
		//printf("node %ld: %ld\n",i, node_array[i]);
		i++;
	}
	node_array[i] = 0;
	return (node_array);
}

bool	is_sorted(t_node **stack)
{
	t_node *current_node;
	
	current_node = *stack;
	indexing(stack);
	/* if (current_node == NULL || current_node->next == NULL) 
		return (true); */
	while (current_node)
	{
		if (current_node -> value > current_node -> next -> value)
			return (false);
		/* else if (current_node -> next -> value == NULL)
			return (true); */
		current_node = current_node -> next;
	}
	printf("true\n");
	return (true);
}

int	main(int argc, char *argv[])
{
	long			*values;
	t_node	*a;
	t_node	*b;
	long	i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc < 2)
		errors(0);
	values = values_array(argc, argv);
	while (values[i])
	{
		//printf("value %ld: %ld\n", i, values[i]);
		//probleme quand 0 a la fin car stop
		i++;
	}
	init_stack_a(values, &a);
	if (is_sorted(&a))
		return (0);
	else if (indexing(&a) == 3)
		sort_three(&a);
	//free(values ??)
	else
		sort_values(&a, &b);
	return (0);
}
