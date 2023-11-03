/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:53:45 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 18:02:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
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
			i++;
			/* if (str[i] == 'c')
				count = count + va_arg_c(args);
			else if (str[i] == 's')
				count = count + va_arg_s(args);
			else if (str[i] == 'p' || str[i] == 'x' || (str[i] == 'X'))
				count = count + va_arg_px(args);
			else if (str[i] == 'd' || (str[i] == 'i'))
				count = count + va_arg_di(args);*/
			if (str[i] == 'u')
				count = count + va_arg_u(args);
			/*else if (str[i] == '%')
				count = count + va_arg_prce(args); */
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
	//char	*str = "Bon Bah voilà";
	unsigned int	i = 200;
	//char	letter = 72;
	ft_printf("local : %u\n", i);
	printf("vrai : %u\n", i);
	return (0);
}