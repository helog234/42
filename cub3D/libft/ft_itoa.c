/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:49:23 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description 
** Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
** Return value: The string representing the integer.
** NULL if the allocation fails.
*/

#include "libft.h"

static int	nbr_len(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = 1;
	len = nbr_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = 0;
	if (n == 0)
	{
		str[len] = '0';
		return (str);
	}
	if (n < 0)
		sign = -1;
	while (n)
	{
		str[len--] = (sign * (n % 10)) + '0';
		n /= 10;
	}
	if (len == 0)
		str[len] = '-';
	return (str);
}

static int	nbr_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
/*
int main(void)
{
	char *ptr;
	int	n = -2147483648;

	ptr = ft_itoa(n);
	printf("Result: %s\n", ptr);
	return 0;    
}*/