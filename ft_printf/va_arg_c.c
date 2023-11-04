/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:25:31 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:44:46 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	va_arg_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (c == 0)
		return (0);
	write(1, &c, 1);
	va_end(args);
	return (1);
}
