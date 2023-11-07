/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:45:55 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/07 14:07:59 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_x(va_list args, char format)
{
	unsigned int	n;
	size_t			len;
	char			*str;

	str = NULL;
	n = va_arg(args, unsigned long);
	len = ft_count_hexa(n);
	if (n == 0)
		return (write(1, "0", 1));
	str = malloc(((len + 1) * sizeof(char)));
	if (!str)
		return (len = write(1, "(null)", 6));
	ft_x_hexa_str(str, len, n, format);
	len = ft_putstr(str);
	free(str);
	return (len);
}
