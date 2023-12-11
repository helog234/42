/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:26:15 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/11 17:13:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	va_arg_s(va_list args)
{
	int		i;
	char	*str;
	int		temp;

	str = va_arg(args, char *);
	i = 0;
	temp = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		temp = write(1, &str[i], 1);
		if (temp < 0)
			return (-1);
		i++;
	}
	return (i);
}
