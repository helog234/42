/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:53:45 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 09:25:56 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_args(const char *s)
{
	int	i;
	int	args;

	i = 0;
	args = 0;
	while (s[i])
	{
		if (s[i] == '%')
			args++;
		i++;
	}
	return (args);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int	num_letter;
	va_list args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'c')
				printc();
			if (s[i + 1] == 's')
			if (s[i + 1] == 'd' || (s[i + 1] == 'i'))
			if (s[i + 1] == 'u')
			if (s[i + 1] == 'x')
			if (s[i + 1] == 'X')
			if (s[i + 1] == '%')
		}
		i++;
	}
	
}

int	main(void)
{
	
}