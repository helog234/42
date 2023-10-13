/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:03:56 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/13 17:48:49 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	counter;
	char			*haystack_temp;
	char			*needle_temp;
	
	i = 0;
	haystack_temp = (char *)haystack;
	needle_temp = (char *)needle;
	while (haystack_temp[i])
	{
		counter = 0;
		j = 0;
		if (needle_temp[j] == 0)
			return (&haystack_temp[i]);
		while (needle_temp[j] && j < len)
		{
			if (needle_temp[j] == haystack_temp[i] && counter < len)
				counter++;
			if (counter == len)
				return (&needle_temp[j]);
			j++;
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	haystack[] = "Salut les moutons. Il fait beau mais froid";
	char	needle[] = "ai";
	
	printf("Returned value : %p\n", ft_strnstr(haystack, needle, 1));
	printf("Returned value : %p\n", strnstr(haystack, needle, 1));
	return (0);
}