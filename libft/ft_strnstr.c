/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:03:56 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/13 18:58:48 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		if (needle[j] == 0)
			return ((char *)&haystack[i]);
		while (needle[j] && needle[j] == haystack[i + j])
			j++;
		if (needle[j] == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	haystack[] = "Salut les moutons. Il fait beau mais froid";
	char	needle[] = "ai";
	
	printf("Returned value : %p\n", ft_strnstr(haystack, needle, 40));
	printf("Returned value : %p\n", strnstr(haystack, needle, 40));
	return (0);
}
*/