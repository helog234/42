/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:56:58 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/29 17:07:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	char		*dst_temp;
	const char	*src_temp;
	int			i;

	if (len < 0 || dst == src)
		return (dst);
	dst_temp = (char *)dst;
	src_temp = (const char *)src;
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			dst_temp[i] = src_temp[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst1[1];
	char	dst2[1];

	(void) dst2;
	char	*src = "A";
	//char	*src = "thi\xc3!\r\n";
	int size = 10;
	//char dst[] =  "lorem ipum dolor sit a";
	
	//char *src = dst + 2;
	printf("dest is : %p\n", memmove(dst1, src, size));
	printf("dest is : %p\n", ft_memmove(dst2, src, size));	
	return (0);
} 
*/