/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:38:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 16:22:30 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	va_arg_di(va_list args)
{
	int		number;
	int		len;
	int		count;
	char	*str;

	number = va_arg(args, int);
	printf("number = %d\n", number);
	len = ft_count_digit(number);
	count = len;
	str = malloc((len + 1) * sizeof(int));
	if (!str)
	{
		write(1, "null\n", 4);
		return (-1);
	}
	if (number < 0)
		str[0] = '-';
	ft_num_str(str, len, number);
	ft_putstr(str);
	va_end(args);
	return (count);
}
