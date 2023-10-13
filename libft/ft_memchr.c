/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:37:17 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/13 09:13:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	int	i;
	unsigned char *char_temp;
	
	char_temp = (unsigned char *)str;
	i = 0;
	while (char_temp[i] && n > 0)
	{
		if (char_temp[i] == c)
			return (&char_temp[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	const char	str[] = "Hello World !";
	char	c = 'o';
	
	printf("First occurence : %p\n", ft_memchr(str, c, 3));
	printf("First occurence : %p\n", memchr(str, c, 3));
	return (0);
}