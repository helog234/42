/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:26:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/27 19:19:01 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
