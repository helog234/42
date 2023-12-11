/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:25:00 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/11 17:13:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	ft_x_hexa_str(char *str, int len, unsigned long n, char format)
{
	int				temp;

	temp = 0;
	str[len] = 0;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			str[len - 1] = temp + '0';
		else if (format >= 'a' && format <= 'z')
			str[len - 1] = temp - 10 + 'a';
		else
			str[len - 1] = temp - 10 + 'A';
		len--;
		n = n / 16;
	}
}

void	ft_p_hexa_str(char *str, int len, unsigned long n, int temp)
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

int	ft_count_hexa(unsigned long hexa)
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
