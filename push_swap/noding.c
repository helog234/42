/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:18:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/27 19:21:35 by hgandar          ###   ########.fr       */
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
	long	i;
	int		flag;

	i = 1;
	flag = 0;
	new_argv = NULL;
	argv = &argv[i];
	if (argc == 2)
	{
		new_argv = ft_split(argv[0], ' ');
		flag = 1;
		if (new_argv == NULL)
			errors(1);
	}
	else
		new_argv = argv;
	if (new_argv[0] == NULL)
		errors(4);
	i = 0;
	create_nodes(i, new_argv, a);
	if (flag == 1)
		free_split(new_argv);
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
