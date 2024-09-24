/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:38:57 by mremenar          #+#    #+#             */
/*   Updated: 2024/05/28 14:30:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
** SYNOPSIS: convert ASCII string to integer
**
** DESCRIPTION:
** 		The atoi() function converts the initial portion of the string pointed
**	to by str to int representation.
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 1;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\f'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	n = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		n *= 10;
		n += nptr[i] - '0';
		i++;
	}
	if (nptr[i])
		return (-1);
	return (n * s);
}
/*
#include <stdio.h>

int main(void)
{
	char ptr[] = "	\
	 -7";
	int	n1;
	int	n2;

	n1 = atoi(ptr);
	printf("Result1: %d\n", n1);
	n2 = ft_atoi(ptr);
	printf("Result2: %d\n", n2);
	return 0;    
}
*/