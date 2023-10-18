/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:21:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/18 11:55:17 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)str1;
	c2 = (unsigned char *)str2;
	while (c1[i] == c2[i] && n > 0)
	{
		i++;
		n--;
	}
	return (c1[i] - c2[i]);
}
/*
int	main(void)
{
	char	str1[] = "Hola";
	char	str2[] = "Hello";
	printf("Strings are : %d\n", ft_memcmp(str1, str2, 2));
	printf("Strings are : %d\n", memcmp(str1, str2, 2));
	return (0);
}
*/