/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:26:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/10 15:54:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	exit(EXIT_FAILURE);
}

int	*values_array(char *argv[])
{
	char	**new_argv;
	int		*node_array;
	long		i;

	i = 1;
	while (i)
	{
		new_argv = ft_split(argv[i], ' ');
		if (new_argv == NULL)
			errors(1);
		i++;
	}
	i = 0;
	while (i)
	{
		node_array[i] = ft_atoi(new_argv[i]);
		i++;
	}
	return (node_array);
}

int	main(int argc, char *argv[])
{
	long			*values;
	struct t_node	*a;
	struct t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		errors(0);
	values = values_array(argv);
	init_stack(values, &a);
	//free(values ??)
	sort_values 
	return (0);
}
