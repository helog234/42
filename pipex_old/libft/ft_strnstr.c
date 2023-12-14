/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:03:56 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/27 16:21:29 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (needle[i] == 0 || needle[j] == 0)
		return ((char *)&hstack[i]);
	while (hstack[i] && i < len)
	{
		j = 0;
		while (needle[j] && needle[j] == hstack[i + j] && i + j < len)
			j++;
		if (needle[j] == 0)
			return ((char *)&hstack[i]);
		i++;
	}
	return (0);
}
/*

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	haystack[] = "lorem ipsum dolor sit amet";
	char	needle[] = "dolor";
	
	printf("Returned value : %p\n", ft_strnstr(haystack, needle, 15));
	printf("Returned value : %p\n", strnstr(haystack, needle, 15));
	return (0);
}
*/