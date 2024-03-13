/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:45:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/03/13 16:31:53 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	put_str(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str) str = "(null)";
	while (str[i])
	{
		*len += write(1, &str[i], 1);
		i++;
	}
}

void	put_base(long long int number, int base, char *digits, int *len)
{
	if (number < 0)
	{
		*len += write(1, "-", 1);
		number = - number;
	}
	if (number >= base)
		put_base(number / base, base, digits, len);
	*len += write(1, &digits[number % base], 1);
}

int ft_printf(const char *format, ... )
{
	int		len;
	va_list	args;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'x'))
		{
			i++;
			if (format[i] == 's')
				put_str(va_arg(args, char *), &len);
			else if (format[i] == 'd')
				put_base(va_arg(args, int), 10, "0123456789", &len);
			else if (format[i] == 'x')
				put_base(va_arg(args, unsigned int), 16, "0123456789abcdef", &len);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	printf(" n: %d\n", ft_printf("Hexadecimal for %d is %x\n", 42, 42));
	printf(" n: %d\n", printf("Hexadecimal for %d is %x\n", 42, 42));
}
