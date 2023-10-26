/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:47:09 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/25 18:23:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	i = 0;
	str = (char *)(malloc(len + 1));
	if (str == NULL || len > SIZE_MAX)
		return (NULL);
	if (len < 0)
		return ((char *) s);
	str[i] = 0;
	if ((int) start >= (int) strlen(s))
		return (str);
	while (s[start] && i < len && (int) start <= (int) ft_strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "";
	unsigned int	start = 1;
	printf("returned : %s\n", ft_substr(s, start, 1));
	return (0);
}
*/