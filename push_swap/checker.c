/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:20:53 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/28 15:46:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	executer(char *str, t_node **a, t_node **b)
{
	if (ft_strncmp(str, "pb\n", 3))
		pb(a, b);
	else if (ft_strncmp(str, "pa\n", 3))
		pa(a, b);
	else if (ft_strncmp(str, "rr\n", 3))
		rr(a, b);
	else if (ft_strncmp(str, "ra\n", 3))
		ra(a);
	else if (ft_strncmp(str, "rb\n", 3))
		rb(b);
	else if (ft_strncmp(str, "rrr\n", 4))
		rrr(a, b);
	else if (ft_strncmp(str, "rra\n", 4))
		rra(a);
	else if (ft_strncmp(str, "rrb\n", 4))
		rrb(b);
	else if (ft_strncmp(str, "ss\n", 3))
		ss(a, b);
	else if (ft_strncmp(str, "sa\n", 3))
		sa(a);
	else if (ft_strncmp(str, "sb\n", 3))
		sb(b);
}

void	checker(int argc, t_node **a, t_node **b)
{
	char	**instructions;
	int		len;
	int		i;
	
	len = 0;
	i = 0;
	//comment connaitre nombre op avant de pouvoir les analyser...
	instructions = malloc(argc - 1);
	if (instructions == NULL)
		errors(1);
	instructions[i] = get_next_line(STDIN_FILENO);
	while (instructions[i])
	{
		if (indexing(a) == 2)
			sort_three(a);
		else
			sort_values(a, b);
		//printf("ici\n");
		//sleep(2);
		instructions[i] = get_next_line(STDIN_FILENO);
		len++;
	}
	while (i < len)
	{
		executer(instructions[i], a, b);
		i++;
	}
	free_split(instructions);
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
	checker(argc, &a, &b);
	if (is_sorted(&a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	free_stack(&a);
	return (0);
}
