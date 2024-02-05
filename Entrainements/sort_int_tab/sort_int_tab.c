/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:59:25 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/05 16:52:54 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] > tab[i +1])
			return (1);
		i++
	}
	return (0);
}

int	value_to_change(int *tab)
{
	int	i;
	
	i = 0;
	while (tab[i])
	{
		if (tab[i] > tab[i + 1]);
			return(tab[i]);
		i++;
	}
	return (0);
}


void sort_int_tab(int *tab, unsigned int size)
{
	int	tmp;
	int	i;
	
	tmp = NULL;
	while (check(tab) == 1)
	{
		i = 0;
		while (tab[i])
		{
			if (tab[i +1] != NULL && tab[i] > tab[i +1])
			{
				tmp = value_to_change(tab);
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
	while (tab[i])
	{
		printf("%i\n", tab[i]);
		i++;
	}
}

int	main(void)
{
	int tab = {2, 1, 7, 3};

	sort_int_tab(tab, 5);
	return (0);
}
