/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:37:17 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/26 10:17:01 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	unsigned char	*char_temp;

	char_temp = (unsigned char *)str;
	i = 0;
	while ((unsigned int) i < n)
	{
		if (char_temp[i] == (unsigned char) c)
			return ((void *)&char_temp[i]);
		i++;
		n--;
	}
	if (char_temp[i] == (unsigned char) c && (unsigned int) i != 0)
		return (&char_temp[i]);
	return (NULL);
}
/*
#include <string.h>
int	main(void)
{
	//const char	str[] = "Hello World !";
	char *str1 = "/|\x12\xff\x09\x42\042\42|\\";
	char *str2 = "/|\x12\xff\x09\x42\042\42|\\";
	int	 size = 10;
	//char	c = '!'
	printf("First occurence : %p\n", ft_memchr(str1, '\200', size));
	printf("First occurence : %p\n", memchr(str2, '\200', size));
	
	//printf("First occurence : %p\n", ft_memchr("bonjour" -1, 7));
	//printf("First occurence : %p\n", memchr("bonjour", -1, 7));
	return (0);
}
*/