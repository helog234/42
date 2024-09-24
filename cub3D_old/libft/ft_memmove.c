/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:44 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: copy byte string
**
** DESCRIPTION:
** 		The memmove() function copies n bytes from string s2 to string s1.  The
**	two strings may overlap; the copy is always done in a non-destructive
**	manner.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!src && !dest)
		return (NULL);
	if (((size_t)dest - (size_t)src) < n)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "lorem ipsum dolor sit amet";
	
	char *str2;
	char *str3;

	str2 = str1 + 1;
	str3 = str1 + 1;
	printf("Result: %s\n", (unsigned char *)memmove(str2, str4, 8));
	printf("Result: %s\n", (unsigned char *)ft_memmove(str3, str1, 8));
}
*/