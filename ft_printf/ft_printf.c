/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:53:45 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/06 17:04:01 by hgandar          ###   ########.fr       */
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
		count = va_arg_c(args);
	else if (str[i] == 's')
		count = va_arg_s(args);
	else if (str[i] == 'p' || str[i] == 'x')
		count = va_arg_p(args);
	else if (str[i] == 'X')
		count = va_arg_xma(args);
	else if (str[i] == 'd' || (str[i] == 'i'))
		count = va_arg_di(args);
	else if (str[i] == 'u')
		count = va_arg_u(args);
	else if (str[i] == '%')
		count = va_arg_prce(args);
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
			count += check_char(str, i, count, args);
			i++;
		}
		else
		{
			count += write(1, &str[i], 1);
			i++;
		}
	}
	return (count);
}

int	main(void)
{
char	*str = "42";
//int	i = 0;
//char	letter = '0';
//ft_printf("%d years old", i);
printf("count final = %d\n", ft_printf(" %p ", str));
printf("count final = %d\n", printf(" %p ", str));
//printf(" %s\n", str);
return (0);
}