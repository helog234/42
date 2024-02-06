/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:59:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/06 14:31:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check(int *tab, int size)
{
	int	i;

	i = size - 1;
	while (i > 0)
	{
		if (tab[i] < tab[i - 1])
			return (i);
		i--;
	}
	return (-1);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	tmp;
	int	i;
	int	j;

	while (check(tab, size) >= 0)
	{
		i = check(tab, size);
		tmp = tab[i];
		tab[i] = tab[i - 1];
		tab[i - 1] = tmp;
	}
	i = 0;
	while (i < size)
	{
		printf("%i\n", tab[i]);
		i++;
	}
}

int	main(void)
{
	int tab[4] = {2, 1, 7, 3};

	sort_int_tab(tab, 4);
	return (0);
}
