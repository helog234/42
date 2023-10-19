/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:21:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/19 13:13:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)str1;
	c2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (!(c1[i] == c2[i]))
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>

int	main(void)
{
	char	str1[] = "Bonjour";
	char	str2[] = "Bonjour";
	printf("Strings are : %d\n", ft_memcmp(str1, str2, 3));
	printf("Strings are : %d\n", memcmp(str1, str2, 3));
	return (0);
}
*/