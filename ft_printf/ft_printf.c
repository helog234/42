/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:53:45 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:16:14 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

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

int	check_char(const char *str, int i, int count, va_list args)
{
	if (str[i] == 'c')
		count = count + va_arg_c(args);
	else if (str[i] == 's')
		count = count + va_arg_s(args);
	else if (str[i] == 'p' || str[i] == 'x')
		count = count + va_arg_px(args);
	else if (str[i] == 'X')
		count = count + va_arg_xma(args);
	else if (str[i] == 'd' || (str[i] == 'i'))
		count = count + va_arg_di(args);
	else if (str[i] == 'u')
		count = count + va_arg_u(args);
	else if (str[i] == '%')
		count = count + va_arg_prce(args);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count = check_char(str, i, count, args);
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

/* int	main(void)
{
	//char	*str = "Bon Bah voilà";
	unsigned int	i = 200;
	//char	letter = 'V';
	ft_printf("local : %X\n", i);
	printf("vrai : %X\n", i);
	return (0);
} */