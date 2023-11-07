/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:16 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/07 14:26:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_p(va_list args)
{
	unsigned long	n;
	size_t			len;
	int				temp;
	char			*str;

	str = NULL;
	n = va_arg(args, unsigned long);
	len = ft_count_hexa(n);
	if (n == 0)
		return (len = write(1, "0x0", 3));
	temp = 0;
	str = malloc(((len + 1) * sizeof(char)));
	if (!str)
		return (len = write(1, "(null)", 6));
	ft_p_hexa_str(str, len, n, temp);
	len = write(1, "0x", 2);
	temp = ft_putstr(str);
	if (temp < 0)
		return (-1);
	else
		len += temp;
	return (len);
}
