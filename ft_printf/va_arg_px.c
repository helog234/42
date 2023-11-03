/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:16 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 17:17:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	count_hexa(unsigned int hexa)
{
	int	i;

	i = 0;
	while (hexa)
	{
		i++;
		hexa = hexa / 16;
	}
	return (i);
}

void putstr(char *str)
{
	int	i;
	
	i = 0;
	write(1, "0x", 2);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	va_arg_px(va_list args)
{
	unsigned int	n;
	size_t			len;
	int				temp;
	char			*str;
	
	str = NULL;
	n = va_arg(args, unsigned int);
	len = count_hexa(n);
	str = malloc(((len + 1)* sizeof(char)));
	if (!str)
	{
		write(1, "null\n", 4);
		return (-1);
	}
	str[len] = 0;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			str[len - 1] = temp + '0';
		else
			str[len - 1] = temp - 10 + 'a';
		len--;
		n = n / 16;
	}
	putstr(str);
	va_end(args);
	return (len);
}