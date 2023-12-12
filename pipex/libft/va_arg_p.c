/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:16 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/12 08:53:45 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	va_arg_p(va_list args)
{
	unsigned long	n;
	int				len;
	int				temp;
	char			*str;

	str = NULL;
	n = va_arg(args, unsigned long);
	len = ft_count_hexa(n);
	if (n == 0)
		return (write(1, "0x0", 3));
	temp = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	ft_p_hexa_str(str, len, n, temp);
	len = write(1, "0x", 2);
	if (len >= 0)
		temp = ft_putstr(str);
	free(str);
	if (temp < 0 || len < 0)
		return (-1);
	else
		len += temp;
	return (len);
}
