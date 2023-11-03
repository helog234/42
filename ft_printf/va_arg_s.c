/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_arg_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:26:15 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 14:54:53 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

int var_arg_s(va_list args)
{
	int	i;
	char	*str;
	
	str = va_arg(args, char *);
	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
	return (i);
}