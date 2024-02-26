/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:34:03 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 14:53:58 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_prime(int nb)
{
	int	i;

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
	int	cpy;

	i = 2;
	cpy = nbr;
	while (i <= nbr)
	{
		if (is_prime(i) == 1)
		{
			while (nbr % i == 0)
			{
				if (nbr == cpy)
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
	printf("\n");
	return (0);
}
