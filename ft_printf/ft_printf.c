/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:53:45 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 15:04:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_args(const char *s)
{
	int	i;
	int	args;

	i = 0;
	args = 0;
	while (s[i])
	{
		if (s[i] == '%')
			args++;
		i++;
	}
	return (args);
}

int	ft_printf(const char *str, ...)
{
	int				i;
	int	count;
	va_list 		args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				count = count + va_arg_c(args);
			else if (str[i + 1] == 's')
				count = count + va_arg_s(args);
			else if (str[i + 1] == 'p' || str[i + 1] == 'x' || (str[i + 1] == 'X'))
				count = count + va_arg_px(args);
			else if (str[i + 1] == 'd' || (str[i + 1] == 'i'))
				count = count + va_arg_di(args);
			else if (str[i + 1] == 'u')
				count = count + va_arg_u(args);
			else if (str[i + 1] == '%')
				count = count + va_arg_(args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (count + i);
}

int	main(void)
{
	//char	str[] = "Hélène";
	//int		i = 2;
	char	c = 'H';
	ft_printf("Hello %c", c);
	return (0);
}