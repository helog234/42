/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:00:14 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: copy memory area
**
** DESCRIPTION:
** 		The memcpy() function copies n bytes from memory area s2 to memory area
**	s1.  If s1 and s2 overlap, behavior is undefined.  Applications in which
**	s1 and s2 might overlap should use memmove(3) instead.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char str1[100] = "Ecole 45259";
	char str2[10] = "SKOOL 42";
	char str3[10] = "SKOOL 42";
	
	printf("Result: %s\n", (unsigned char*)memcpy(str2, str1, 9));
	printf("Result: %s\n", (unsigned char*)ft_memcpy(str3, str2, 9));
}
*/