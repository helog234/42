/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:37:17 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/19 12:11:06 by hgandar          ###   ########.fr       */
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
	int str[7] = {0, 1, 2 ,3 ,4 ,5};
	//char	c = '!'
	printf("First occurence : %p\n", ft_memchr(str, 2 + 256, 3));
	printf("First occurence : %p\n", memchr(str, 2 + 256, 3));
	
	//printf("First occurence : %p\n", ft_memchr("bonjour" -1, 7));
	//printf("First occurence : %p\n", memchr("bonjour", -1, 7));
	return (0);
}
*/