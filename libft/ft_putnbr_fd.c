/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:46:09 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/27 09:25:33 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	int		min;

	min = -2147483648;
	if (n == min)
	{
		write (fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > -10 && n < 10)
	{
		digit = n + '0';
		write(fd, &digit, 1);
	}
	else if (n <= -10 || n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
/*
int	main(void)
{
	int	nb = -24;
	ft_putnbr_fd(nb, 2);
	return (0);
}
*/