/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:18:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/05 09:52:51 by hgandar          ###   ########.fr       */
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

char	**parsing(char *str)
{
	char	**new_argv;

	if (ft_strchr(str, ' ') != NULL)
	{
		new_argv = ft_split(str, ' ');
		if (new_argv == NULL)
			errors(1);
	}
	else
	{
		new_argv = malloc(2 * sizeof(char *));
		new_argv[0] = str;
		new_argv[1] = 0;
	}	
	return (new_argv);
}

void	values_array(int argc, char *argv[], t_node **a)
{
	char	**new_argv;
	long	i;
	int		flag;

	i = 0;
	argv = &argv[1];
	while (argv[i] && i <= argc - 2)
	{
		flag = 0;
		new_argv = parsing(argv[i]);
		if (ft_strchr(argv[i], ' ') != NULL)
			flag = 1;
		create_nodes(0, new_argv, a);
		if (flag == 1)
			free_split(new_argv);
		else
			free(new_argv);
		i++;
	}
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
