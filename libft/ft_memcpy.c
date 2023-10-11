/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:56:30 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/11 16:20:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void	*dst, const void *src, unsigned long n)
{
	int				i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		n--;
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[] = "KOKOKOKOKOKO";
	char	src[] = "ABCDEF";
	//int	n = 2;

	printf("dest is : %s\n",ft_memcpy(&dst, src, 4));
	printf("dest is : %s\n",memcpy(&dst, src, 4));
	return (0);
}
*/