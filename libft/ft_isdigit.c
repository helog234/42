/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:49:41 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/09 17:30:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		eturn (1);
	else
		return (0);
}
/*
int main(void)
{
    unsigned char   c;
    c = '9';
    
    printf("c is : %d\n", ft_isdigit(c));
    printf("c is : %d\n", isdigit(c));
}
*/