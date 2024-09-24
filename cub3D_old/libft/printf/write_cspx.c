/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cspx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:57 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/15 15:52:29 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	write_s(char *s)
{
	int		count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count])
	{
		ft_putchar_fd(s[count], 1);
		count++;
	}
	return (count);
}

int	write_p(unsigned long p)
{
	int		count;
	char	*hex_ref;

	hex_ref = "0123456789abcdef";
	count = write_s("0x");
	count += write_hex(p, hex_ref);
	return (count);
}

int	write_x(unsigned long x, char c)
{
	int		count;
	char	*hex_ref;

	if (c == 'x')
		hex_ref = "0123456789abcdef";
	else
		hex_ref = "0123456789ABCDEF";
	count = 0;
	count += write_hex(x, hex_ref);
	return (count);
}

int	write_hex(unsigned long n, char *hex_ref)
{
	int		count;

	count = 1;
	if (n > 15)
		count += write_hex(n / 16, hex_ref);
	ft_putchar_fd(hex_ref[n % 16], 1);
	return (count);
}
