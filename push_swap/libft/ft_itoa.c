/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:54:30 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 07:44:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	n_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;

	len = n_size(n);
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[len] = 0;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		if (n > 0)
			str[len - 1] = (n % 10) + '0';
		else
			str[len - 1] = -(n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (str);
}

/* #include <limits.h>
#include <stdio.h>
int	main (void)
{
	int	n;
	n = -623;
	printf("string : %s\n", ft_itoa(n));
	
	return (0);
} */
