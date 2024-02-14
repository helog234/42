/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:12:29 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/25 11:39:48 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int i;
	i = 0;
	while (i < 256)
	{
		if (ft_tolower(i) != tolower(i))
		{
			printf("i = %d\n", i);
			printf("my function is : %c\n", ft_tolower(i));
			printf("real : %c\n", tolower(i));
		}
		i++;
	}
	return (0);
}
*/