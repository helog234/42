/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:16 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/06 17:05:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_p(va_list args)
{
	unsigned int	n;
	size_t			len;
	int				temp;
	char			*str;

	str = NULL;
	n = va_arg(args, void *);
	len = ft_count_hexa(n);
	temp = 0;
	str = malloc(((len + 1) * sizeof(char)));
	if (!str)
		return (len = write(1, "(null)", 6));
	ft_s_hexa_str(str, len, n, temp);
	len = write(1, "0x", 2);
	len += ft_putstr(str);
	va_end(args);
	return (len);
}
