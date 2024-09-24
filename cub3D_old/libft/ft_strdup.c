/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:33:56 by mremenar          #+#    #+#             */
/*   Updated: 2023/12/14 08:55:32 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: save a copy of a string (with malloc)
**
** DESCRIPTION:
** 		The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.  The pointer may
**	subsequently be used as an argument to the function free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = 1 + ft_strlen(s);
	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	while (i < size)
	{
		tmp[i] = s[i];
		i++;
	}
	return (tmp);
}

/*#include<stdio.h>
#include<string.h>
 
int main()
{
    char source[] = "4564ddz 	tdu";
 
    char* target1 = strdup(source); 
 
    printf("Target1: %s\n", target1);
	char* target2 = ft_strdup(source); 
 
    printf("Target2: %s\n", target2);
	free (target1);
	free (target2);
    return 0;
}*/