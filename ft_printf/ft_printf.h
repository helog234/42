/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:47:38 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/07 13:34:18 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		va_arg_c(va_list args);
int		va_arg_di(va_list args);
int		va_arg_prce(void);
int		va_arg_p(va_list args);
int		va_arg_s(va_list args);
int		va_arg_u(va_list args);
int		va_arg_x(va_list args, char c);
int		ft_count_hexa(unsigned long hexa);
int		ft_count_digit(int n);
int		ft_putstr(char *str);
void	ft_num_str(char *str, int len, unsigned int number);
void	ft_p_hexa_str(char *str, int len, unsigned long n, int temp);
void	ft_x_hexa_str(char *str, int len, unsigned long n, char format);
int		ft_count_u_digit(unsigned int n);

#endif
