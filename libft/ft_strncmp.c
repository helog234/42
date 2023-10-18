/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:52:08 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/18 11:58:33 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (str1[i - 1] - str2[i - 1]);
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