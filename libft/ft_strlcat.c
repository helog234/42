/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:24:37 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/11 16:19:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned long	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (i >= dstsize)
		return (dstsize + j);
	j = 0;
	while (src[j] && i < (dstsize - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	while (src[j])
		j++;
	return (i + j);
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[20] = "Hello World !";
	char	dst1[20] = "CouCou";
	char	dst2[20] = "CouCou";
	
	printf("dest is: %lu\n", ft_strlcat(dst1, src, 10));
	printf("%s\n", dst1);
	printf("dest is: %lu\n", strlcat(dst2, src, 10));
	printf("%s\n", dst2);
	return (0);
}