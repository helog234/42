/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:54:30 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/20 18:06:19 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*putstr(int i, char digit, int lenght, int n)
{
	char	*str;
	int		j;
	char	sign;

	str = ft_calloc(i + 2, 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	sign = digit;
	while (lenght < -10 || lenght > 10)
	{
		digit = (lenght % 10) + '0';
		str[i - j] = digit;
		j++;
		lenght = lenght / 10;
	}
	str[i - j] = n + '0';
	j++;
	if (sign == '-')
		str[i - j] = sign;
	return (str);
}

char	*ft_itoa(int n)
{
	char	digit;
	char	*str;
	int		i;
	int		lenght;

	i = 0;
	if (n < 0)
	{
		i++;
		digit = '-';
		n = -1 * n;
	}
	lenght = n;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	str = putstr(i, digit, lenght, n);
	return (str);
}
/*
#include <limits.h>
#include <stdio.h>
int	main (void)
{
	int	n;
	
	n = 12345;
	printf("string : %s\n", ft_itoa(n));
	return (0);
}
*/