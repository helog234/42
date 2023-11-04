/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_xma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:45:55 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:16:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_xma(va_list args)
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
	ft_putstr(str);
	va_end(args);
	return (len);
}
