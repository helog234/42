/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:45:55 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/08 09:00:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_x(va_list args, char format)
{
	unsigned long	n;
	int				len;
	int				temp;
	char			*str;

	str = NULL;
	temp = 0;
	n = va_arg(args, unsigned long);
	len = ft_count_hexa(n);
	if (n == 0)
		return (write(1, "0", 1));
	str = malloc(((len + 1) * sizeof(char)));
	if (!str)
		return (-1);
	ft_x_hexa_str(str, len, n, format);
	len = ft_putstr(str);
	free(str);
	return (len);
}
