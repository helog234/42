/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:58:22 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/19 17:14:50 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str3;

	i = 0;
	j = 0;
	str3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str3 == NULL)
		return (NULL);
	while (s1[i])
	{
		str3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str3[i] = s2[j];
		j++;
		i++;
	}
	str3[i] = 0;
	return (str3);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Allez on va Malloc";
	char	str2[] = "maintenant";
	printf("New string : %s\n", ft_strjoin(str1, str2));
	return (0);
}
*/