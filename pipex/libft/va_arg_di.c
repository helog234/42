/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:38:10 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/11 17:13:36 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	va_arg_di(va_list args)
{
	int		number;
	int		len;
	char	*str;

	number = va_arg(args, int);
	len = ft_count_digit(number);
	str = malloc((len + 1) * sizeof(int));
	if (!str)
		return (-1);
	if (number == 0)
		str[0] = '0';
	str[len] = 0;
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	ft_num_str(str, len, number);
	len = ft_putstr(str);
	free(str);
	return (len);
}
