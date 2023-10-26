/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:54:30 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/26 09:29:33 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned long	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*putstr(int i, char digit, int length, int n)
{
	char	*str;
	int		j;
	char	sign;

	str = ft_calloc(i + 2, 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	sign = digit;
	while (length <= -10 || length >= 10)
	{
		digit = (length % 10) + '0';
		str[i - j] = digit;
		j++;
		length = length / 10;
	}
	str[i - j] = n + '0';
	j++;
	if (sign == '-')
		str[0] = sign;
	return (str);
}

char	*ft_itoa(int n)
{
	char	digit;
	char	*str;
	int		i;
	int		length;

	i = 0;
	if (n < 0)
	{
		i++;
		digit = '-';
		n = -n;
	}
	length = n;
	while (n < -9 || n > 9)
	{
		i++;
		n = n / 10;
	}
	if (length == -2147483648)
	{
		str = ft_calloc(i + 2, 1);
		return (str = ft_strcpy(str, "-2147483648"));
	}
	str = putstr(i, digit, length, n);
	return (str);
}
/*
#include <limits.h>
#include <stdio.h>
int	main (void)
{
	int	n;
	n = 156;
	printf("string : %s\n", ft_itoa(n));
	
	return (0);
}
*/