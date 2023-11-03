/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:47:38 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/03 15:02:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...);
int	va_arg_c(va_list args);
int	va_arg_di(va_list args);
int	va_arg_prce(va_list args);
int	va_arg_px(va_list args);
int va_arg_s(va_list args);
int	va_arg_u(va_list args);

#endif
