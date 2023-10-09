/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:50:31 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/09 16:20:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("Lenght of the string : %d\n", ft_strlen(argv[1]));
		printf("Lenght of the string : %lu\n", strlen(argv[1]));
	}
	return (0);
}