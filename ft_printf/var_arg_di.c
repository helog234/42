/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_arg_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:38:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 14:00:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int	count_digit(int n)
{
	int	i;
	
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
}

int	var_arg_di(va_list args)
{
	int		number;
	int		len;
	int		count;
	char	*str;
	
	number = va_arg(args, int);
	len = count_digit(number);
	count = len;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	if (number < 0)
		str[0] = '-';
	while (number)
	{
		if (number < 0)
			str[len] = (number % 10) + '0';
		else 
			str[len] = - (number % 10) + '0';
		len--;
	}
	return (count);
}