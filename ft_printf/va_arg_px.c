/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:16 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:16:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_px(va_list args)
{
	unsigned int	n;
	size_t			len;
	int				temp;
	char			*str;

	str = NULL;
	n = va_arg(args, unsigned int);
	len = ft_count_hexa(n);
	temp = 0;
	str = malloc(((len + 1) * sizeof(char)));
	if (!str)
	{
		write(1, "null\n", 4);
		return (-1);
	}
	ft_hexa_str(str, len, n, temp);
	write(1, "0x1", 3);
	ft_putstr(str);
	va_end(args);
	return (len);
}
