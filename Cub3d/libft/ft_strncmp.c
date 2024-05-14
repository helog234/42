/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:52:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/08 15:14:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		if (*str1 == 0)
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "Hello World !";
	char	str2[] = "Oi";
	
	printf("strncmp result : %d\n", ft_strncmp(str1, str2, 6));
	printf("strncmp result : %d\n", strncmp(str1, str2, 6));
	return (0);
}
*/