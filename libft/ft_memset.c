/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:55:25 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/11 10:29:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	*str_temp;

	i = 0;
	c = (unsigned char)c;
	str_temp = (unsigned char *)str;
	while (len > 0)
	{
		str_temp[i] = c;
		len--;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "Il faut que je me souvienne de ce que j'avais fait";
	
	ft_memset(&str, '-', 5);
	puts(str);
	memset(&str, '-', 5);
	puts(str);
	return (0);
}
*/