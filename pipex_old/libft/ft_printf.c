/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:53:45 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/12 08:54:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

static int	check_char(const char *str, int i, int count, va_list args)
{
	if (str[i] == 'c')
		count = va_arg_c(args);
	else if (str[i] == 's')
		count = va_arg_s(args);
	else if (str[i] == 'p')
		count = va_arg_p(args);
	else if (str[i] == 'X' || str[i] == 'x')
		count = va_arg_x(args, str[i]);
	else if (str[i] == 'd' || (str[i] == 'i'))
		count = va_arg_di(args);
	else if (str[i] == 'u')
		count = va_arg_u(args);
	else if (str[i] == '%')
		count = va_arg_prce();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		tmp_count;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			tmp_count = check_char(str, ++i, count, args);
		else
			tmp_count = write(1, &str[i], 1);
		if (tmp_count < 0)
		{
			va_end(args);
			return (tmp_count);
		}
		count += tmp_count;
		i++;
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
//char	*str = "42";
//int	i = 0;
//char	letter = '0';
//ft_printf("%d years old", i);
printf("count final = %d\n", ft_printf("%u", 0));
printf("count final = %d\n", printf("%u", 0));
//printf(" %s\n", str);
return (0);
} */