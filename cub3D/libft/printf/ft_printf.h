/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:27:26 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/30 14:49:23 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);

int		write_arg(char t, va_list args);

int		write_c(char c);

int		write_s(char *s);

int		write_p(unsigned long p);

int		write_x(unsigned long x, char c);

int		write_hex(unsigned long n, char *hex_ref);

int		write_di(int n);

int		write_u(unsigned int n);

void	ft_putunbr(unsigned int n);

#endif