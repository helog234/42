/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:56:58 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/11 10:41:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	int				i;

	i = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (len > 0)
	{
		dst_temp[i] = src_temp[i];
		len--;
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	dst[] = "Hello world !";
	char	src[] = "ABC";
	
	printf("dest is : %s\n", ft_memmove(&dst, src, 3));
	printf("dest is : %s\n", memmove(&dst, src, 3));
	return (0);
}
*/