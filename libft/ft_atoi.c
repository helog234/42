/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:22:24 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/18 11:49:14 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			if (str[i] == '-' && result == 0)
				sign *= -1;
			else if (!(str[i] == '+' || (str[i] == ' ' && result != 0)))
				break ;
		}
		if (ft_isdigit(str[i]))
			result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "b7k95";
	printf("str is : %d\n", ft_atoi(str));
	printf("str is : %d\n", atoi(str));
	return (0);
}
*/