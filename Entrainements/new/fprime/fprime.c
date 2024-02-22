/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:16:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/22 09:56:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 1)
		return (1);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	fprime(int nbr)
{
	int	i;
	int	origin;

	i = 2;
	origin = nbr;
	if (is_prime(nbr) == 1)
	{
		printf("%i", nbr);
		return ;
	}
	while (i <= nbr)
	{
		if (is_prime(i) == 1)
		{
			while (nbr % i == 0)
			{
				if (nbr == origin)
					printf("%i", i);
				else
					printf("*%i", i);
				nbr = nbr / i;
			}
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	return (0);
}
