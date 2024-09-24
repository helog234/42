/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:27:12 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/15 15:47:50 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += write_arg(str[i], args);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	write_arg(char t, va_list args)
{
	int	count;

	count = 0;
	if (t == 'c')
		count = write_c(va_arg(args, int));
	else if (t == 's')
		count = write_s(va_arg(args, char *));
	else if (t == 'p')
		count = write_p((unsigned long)va_arg(args, void *));
	else if (t == 'd' || t == 'i')
		count = write_di(va_arg(args, int));
	else if (t == 'u')
		count = write_u(va_arg(args, unsigned int));
	else if (t == 'x')
		count = write_x((unsigned long)va_arg(args, unsigned int), 'x');
	else if (t == 'X')
		count = write_x((unsigned long)va_arg(args, unsigned int), 'X');
	else if (t == '%')
		count = write_c('%');
	else
		count = 0;
	return (count);
}

/*int main(void)
{
	int i;
	int j;	
	i = printf("%u\n", 15);
	j = ft_printf("%u\n", 15);
	printf("i: %i, j: %i\n", i, j);
	i = printf("%p", (void *)0);
	printf("\n");
	j = ft_printf("%p", (void *)0);
//	 printf("sad sam vani\n");
	 printf("\ni: %i, j: %i\n", i, j);
}*/