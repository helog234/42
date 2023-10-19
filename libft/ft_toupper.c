/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:50:55 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/19 08:58:19 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int i = 0;
	while (i < 0x100)
	{
		if (ft_toupper(i) != toupper(i)) 
		{
			printf("i = %d\n", i);
			printf("ft_toupper : %c\n", ft_toupper(i));
			printf("returned = %d\n", i);
			printf("touppe : %c\n", toupper(i));
		}
				i++;
	}
	
	char	c = 'n';
	printf("char is : %c\n", ft_toupper(c));
	printf("char is : %c\n", toupper(c));
	return (0);
	
}
*/