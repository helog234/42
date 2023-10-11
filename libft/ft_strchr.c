/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:21 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/11 17:53:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		else
			i++;
	}
	if (s[i] != c)
		return (0);
	return (&s[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] ="Hello World !";
	char	c = 0;
	printf("s is : %p\n", ft_strchr(s, c));
	printf("s is : %p\n", strchr(s, c));
	return (0);
}
*/