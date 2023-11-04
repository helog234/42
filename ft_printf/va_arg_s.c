/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:26:15 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:16:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	va_arg_s(va_list args)
{
	int		i;
	char	*str;

	str = va_arg(args, char *);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}
