/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:49:41 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/13 16:10:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    unsigned char   c;
    c = '9';
    
    printf("c is : %d\n", ft_isdigit(c));
    printf("c is : %d\n", isdigit(c));
}
*/