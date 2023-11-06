/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:25:00 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/06 16:26:26 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_c_hexa_str(char *str, int len, unsigned int n, int temp)
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
}

void	ft_s_hexa_str(char *str, int len, unsigned int n, int temp)
{
	str[len] = 0;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			str[len - 1] = temp + '0';
		else
			str[len - 1] = temp - 10 + 'a';
		len--;
		n = n / 16;
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
	return (i - 1);
}
