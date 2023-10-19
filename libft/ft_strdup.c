/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:08:39 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/19 15:37:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = (char *) malloc (strlen(str1 + 1));
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	return (str2);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "lorem ipsum dolor sit amet !";
	char	*str_dup;
	printf("Copy : %p\n", ft_strdup(str));
	printf("%s\n", ft_strdup(str));
	printf("Copy : %p\n", strdup(str));
	printf("%s\n", strdup(str));
	return (0);
}
*/