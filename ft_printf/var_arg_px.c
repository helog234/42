/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_arg_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:16 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 14:27:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int	count_hexa(char *str)
{
	int	i;
	
	i = 0;
	while (&str[i])
		i++;
	return (i);
}

void putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
}

int	var_arg_px(va_list args)
{
	long int	n;
	int			len;
	int			temp;
	char		*str;
	
	n = va_arg(args, char *);
	len = count_hexa(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = 0;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			str[len - 1] = temp + '0';
		else if (temp >= 'a' && temp <= 'z')
			str[len - 1] = temp + 'a';
		else if (temp >= 'A' && temp <= 'Z')
			str[len - 1] = temp + 'A';
		len--;
		n = n / 16;
	}
	putstr(str);
	return (len);
}