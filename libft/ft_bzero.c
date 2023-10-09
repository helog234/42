/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:50:12 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/09 18:14:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	int				i;
	unsigned char	*str_temp;

	i = 0;
	str_temp = (unsigned char*) str;
	while (n > 0)
	{
		str_temp[i] = '\0';
		n--;
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "Allez, ça doit pas être si compliqué";
	char	str2[] = "Allez, ça doit pas être si compliqué";
	ft_bzero(&str, 4);
	puts(str);
	bzero(&str2, 4);
	puts(str2);
	return (0);
}
*/