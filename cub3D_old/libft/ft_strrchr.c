/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:54:28 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:54:44 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate character in string (last occurence)
**
** DESCRIPTION:
** 		The strrchr() function locates the last occurrence of c (converted to a
**	char) in the string s.  If c is `\0', strrchr() locates the terminating
**	`\0'.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	l;

	l = ft_strlen(s);
	s += l;
	i = 0;
	while (*s != (char)c && i++ < l)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//const char str1[100] = "Ecole 42 !";
	char str2[100] = "SKOOL 42";
	char str3[100] = "SKOOL 42";
	
	printf("Result: %s\n", strrchr(str2, 'M'));
//	printf("Dest1: %s\n", str2);
	printf("Result: %s\n", ft_strrchr(str3, 'M'));
//	printf("Dest2: %s\n", str3);
}*/