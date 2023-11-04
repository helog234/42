/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:10:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:16:45 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_u(va_list args)
{
	unsigned int	number;
	int				len;
	unsigned int	count;
	char			*str;

	number = va_arg(args, int);
	len = ft_count_digit(number);
	count = len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		write(1, "null\n", 4);
		return (-1);
	}
	ft_num_str(str, len, number);
	ft_putstr(str);
	va_end(args);
	return (count);
}
