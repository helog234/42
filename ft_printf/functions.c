/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:04:54 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/06 16:36:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str && str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (len);
}

int	ft_count_digit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_num_str(char *str, int len, unsigned int number)
{
	str[len] = 0;
	if (number == 0)
		str[0] = '0';
	while (number)
	{
		if (number > 0)
			str[len - 1] = (number % 10) + '0';
		else
			str[len - 1] = - (number % 10) + '0';
		len--;
		number = number / 10;
	}
}
