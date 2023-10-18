/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:09:03 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/18 11:53:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(int argc, char ** argv)
{
   // unsigned char   c;
    //c = 128;
    if (argc == 2)
    {
        printf("argv is : %d\n", ft_isascii(*argv[1]));
        printf("argv is : %d\n", isascii(*argv[1]));
    }
        return 0;
}
*/