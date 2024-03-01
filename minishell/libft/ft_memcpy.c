/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:56:30 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/11 16:34:48 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, unsigned long n)
{
	int				i;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		n--;
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	//char	dst[100];
	//char	src[] = "42";
	//int	n = 2;
	
	printf("dest is : %s\n", ft_memcpy(((void *)0), ((void *)0), 3));
	printf("dest is : %s\n", memcpy(((void *)0), ((void *)0), 3));
	return (0);
}
*/