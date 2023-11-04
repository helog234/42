/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:04:54 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:17:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_count_hexa(unsigned int hexa)
{
	int	i;

	i = 0;
	while (hexa)
	{
		i++;
		hexa = hexa / 16;
	}
	return (i);
}

int	ft_count_digit(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_num_str(char *str, int len, unsigned int number)
{
	str[len] = 0;
	while (number)
	{
		str[len - 1] = (number % 10) + '0';
		len--;
		number = number / 10;
	}
	return (str);
}

char	*ft_hexa_str(char *str, int len, unsigned int n, int temp)
{
	str[len] = 0;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			str[len - 1] = temp + '0';
		else
			str[len - 1] = temp - 10 + 'A';
		len--;
		n = n / 16;
	}
	return (str);
}
