/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:26:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/22 17:17:49 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_nodes(long i, char *new_argv[], t_node **a)
{
	int	j;

	while (new_argv[i])
	{	
		j = 0;
		while (new_argv[i][j])
		{
			if (ft_isdigit(new_argv[i][j]) == 0 && \
			new_argv[i][j] != '-' && new_argv[i][j] != '+')
				errors(1);
			if ((new_argv[i][j] == '-' || new_argv[i][j] == '+') && \
			ft_isdigit(new_argv[i][j + 1]) == 0)
				errors(1);
			if (new_argv[i][j + 1] == 0 && \
			(new_argv[i][j] == '-' || new_argv[i][j] == '+'))
				errors(1);
			j++;
		}
		init_stack_a(ft_atoi(new_argv[i]), a);
		i++;
	}
}

void	values_array(int argc, char *argv[], t_node **a)
{
	char	**new_argv;
	long	*node_array;
	long	i;

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
	if (!node_array || new_argv[0] == NULL)
		errors(4);
	i = 0;
	create_nodes(i, new_argv, a);
}

bool	is_sorted(t_node **stack_check)
{
	t_node	*stack;

	stack = *stack_check;
	while (stack && stack->next)
	{
		if (stack -> value > stack-> next -> value)
			return (false);
		stack = stack -> next;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (ft_strlen(argv[1]) == 0)
		errors(0);
	values_array(argc, argv, &a);
	if (is_sorted(&a) || indexing(&a) == 0)
	{
		free_stack(&a);
		return (0);
	}
	if (indexing(&a) == 1)
		sa(&a);
	else if (indexing(&a) == 2)
		sort_three(&a);
	else
		sort_values(&a, &b);
	free_stack(&a);
	return (0);
}
