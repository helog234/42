/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:24:37 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/18 13:45:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = i + j;
	if (i >= dstsize)
		return (dstsize + j);
	j = 0;
	while (src[j] && (i + 1 < dstsize))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (k);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[20] = "Hello World !";
	char	dst1[20] = "CouCouCouCouCou";
	char	dst2[20] = "CouCouCouCouCou";
	
	printf("dest is: %lu\n", ft_strlcat(dst1, src, 4));
	printf("%s\n", dst1);
	printf("dest is: %lu\n", strlcat(dst2, src, 4));
	printf("%s\n", dst2);
	return (0);
}
*/