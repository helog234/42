/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:20:53 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/29 17:27:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	executer(char *str, t_node **a, t_node **b)
{
	if (!ft_strncmp(str, "pb\n", 3))
		pb(a, b, 1);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(a, b, 1);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(a, b, 1);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(a, 1);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(b, 1);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(a, b, 1);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(a, 1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(b, 1);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(a, b, 1);
	else if (!ft_strncmp(str, "sa\n", 3))
		sa(a, 1);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(b, 1);
	else
		return (false);
	return (true);
}

bool	checker(t_node **a, t_node **b)
{
	char	*instructions;
	int		i;

	i = 0;
	instructions = get_next_line(STDIN_FILENO);
	while (instructions)
	{
		(void)a;
		(void)b;
		if (!executer(instructions, a, b))
		{
			free(instructions);
			return (false);
		}
		free(instructions);
		instructions = get_next_line(STDIN_FILENO);
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
	checker(&a, &b);
	if (is_sorted(&a) && b == NULL)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	free_stack(&a);
	return (0);
}
