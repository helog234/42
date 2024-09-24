/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:06:17 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate byte in byte string
**
** DESCRIPTION:
** 		The memchr() function locates the first occurrence of c (converted to an
**	unsigned char) in string s.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- && *(unsigned char *)s != (unsigned char)c)
		s++;
	if ((int)n >= 0 && *(unsigned char *)s == (unsigned char)c)
		return ((unsigned char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//const char str1[100] = "EcOle 42 !";
	char str2[100] = "SKOOL 42";
	char str3[100] = "SKOOL 42";
	
	printf("Result: %s\n", (unsigned char *)memchr(str2, 'O', 2));
	printf("Dest1: %s\n", str2);
	printf("Result: %s\n", (unsigned char *)ft_memchr(str3, 'O', 2));
	printf("Dest2: %s\n", str3);
}*/