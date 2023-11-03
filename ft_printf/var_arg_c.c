/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_arg_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:25:31 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 12:52:54 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	var_arg_c(va_list args)
{
	char	c;
	
	c = va_arg(args, char);
	write(1, args, 1);
	return (1);
}