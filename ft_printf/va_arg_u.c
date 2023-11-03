/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:10:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 18:06:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	count_digit(int n)
{
	int	i;
	
	i = 0;
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
		write(1, &str[i], 1);
		i++;
	}
}

int	va_arg_u(va_list args)
{
	unsigned int	number;
	int				len;
	unsigned int	count;
	char			*str;
	
	number = va_arg(args, int);
	len = count_digit(number);
	count = len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		write(1, "null\n", 4);
		return (-1);
	}
	str[len] = 0;
	while (number)
	{
		str[len - 1] = (number % 10) + '0';
		len--;
		number = number / 10;
	}
	putstr(str);
	va_end(args);
	return (count);
}