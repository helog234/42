/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/27 16:20:56 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

unsigned long	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	dst1[] = "^@rrrrr^@^@^@^@^@^@^@^@^@";
	char	dst2[] = "^@rrrrr^@^@^@^@^@^@^@^@^@";
	char	src[] = "Hello";

	printf("dest is :%lu long\n", ft_strlcpy(dst1, src, 15));
	printf("%s\n", dst1);
	printf("dest is :%lu long\n", strlcpy(dst2, src, 15));
	printf("%s\n", dst2);
	return (0);
}
*/