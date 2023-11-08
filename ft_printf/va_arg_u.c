/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:10:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/08 08:59:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_count_u_digit(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	va_arg_u(va_list args)
{
	unsigned int	number;
	int				len;
	char			*str;

	number = va_arg(args, unsigned int);
	len = ft_count_u_digit(number);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	ft_num_str(str, len, number);
	len = ft_putstr(str);
	free(str);
	return (len);
}
