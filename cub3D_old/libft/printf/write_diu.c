/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:41:19 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/15 15:49:39 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_di(int n)
{
	int	count;

	count = 0;
	ft_putnbr_fd(n, 1);
	if (n < 0 || n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	write_u(unsigned int n)
{
	int	count;

	count = 0;
	ft_putunbr(n);
	if (n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_putunbr(unsigned int n)
{
	if (n > 9)
		write_u((n / 10));
	write_c((n % 10) + '0');
}
