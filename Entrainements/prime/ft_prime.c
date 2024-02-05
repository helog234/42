/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:04:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/05 15:27:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_prime(int prime)
{
	int	i;

	i = 2;
	while (i <= prime)
	{
		if (prime % i != 0)
			return (0);
		i++;
	}
	return (1);
}

void	fprime(int nbr)
{
	int	i;
	int cpy;

	i = 2;
	cpy = nbr;
	while (i <= nbr)
	{
		if (is_prime(i) == 0)
		{
			while (nbr % i == 0 && nbr >= i)
			{
				if (cpy == nbr)
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
