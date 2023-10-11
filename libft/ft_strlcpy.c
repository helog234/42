/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/11 12:07:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned long	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = 0;
	if (src[i] == 0)
		return (i);
	else
	{
		while (src[i])
		{
			while (i < (dstsize - 1) && src[i])
			{
				dst[i] = src[i];
				i++;
			}
			i++;
		}
	}
		dst[i] = 0;
	return (i - 1);
}

int	main(void)
{
	char	dst1[] = "Hello World !";
	char	dst2[] = "Hello World !";
	char	src[] = "COUcou";

	printf("dest is :%lu long\n", ft_strlcpy(dst1, src, 3));
	printf("%s\n", dst1);
	printf("dest is :%lu long\n", strlcpy(dst2, src, 3));
	printf("%s\n", dst2);
	return (0);
}
