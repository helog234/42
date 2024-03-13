/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:11:26 by hgandar           #+#    #+#             */
/*   Updated: 2024/03/13 15:44:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	put_str(char *str, int *length)
{
	int	i;

	i = 0;
	while (str[i])
	{
		*length += write(1, &str[i], 1);
		i++;
	}
}

void	put_base(long long int number, int base, char *digits, int *length)
{
	if (number < 0)
	{
		length += write(1, "-", 1);
		number = - number;
	}
	if (number >= base)
		put_base(number / base, base, digits, length);
	*length += write(1, &digits[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
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
//char	*str = "42";
//int	i = 0;
//char	letter = '0';
//ft_printf("%d years old", i);
printf("count final = %d\n", ft_printf("Magic %s is %d", "number", 42));
printf("count final = %d\n", printf("Magic %s is %d", "number", 42));
//printf(" %s\n", str);
return (0);
}
