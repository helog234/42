/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:47:38 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/04 15:43:59 by hgandar          ###   ########.fr       */
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
int		va_arg_prce(va_list args);
int		va_arg_px(va_list args);
int		va_arg_s(va_list args);
int		va_arg_u(va_list args);
int		va_arg_xma(va_list args);
int		ft_count_hexa(unsigned int hexa);
int		ft_count_digit(int n);
int		ft_putstr(char *str);
char	*ft_num_str(char *str, int len, unsigned int number);
char	*ft_hexa_str(char *str, int len, unsigned int n, int temp);

#endif
