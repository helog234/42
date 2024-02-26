/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:59:49 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 10:06:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		if (tab[i - 1] > tab[i])
		{
			while (/* condition */)
			{
				/* code */
			}
			
			tmp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = tmp;
		}
		i++;
	}
	
}

int	main(void)
{
	int	*tab = {1, 4, 3, 3, 2, 6, 0};
	
}