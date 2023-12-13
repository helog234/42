/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:47:09 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/29 11:20:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	s_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start + len > s_len)
		len = s_len - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	i = 0;
	len = s_len(s, start, len);
	if (len < 0)
		return ((char *) s);
	if (start > (unsigned int) ft_strlen(s))
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		*str = 0;
		return (str);
	}
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	i = 0;
	str = malloc(len + 1);
	if (str == NULL || len > SIZE_MAX)
		return (NULL);
	if (len < 0)
		return ((char *) s);
	str[i] = 0;
	if ((int) start >= (int) strlen(s))
		return (str);
	while (s[start] && i < len && (int) start <= (int) strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

#include <stdio.h>
int	main(void)
{
	//char	s[] = "";
	//unsigned int	start = 1;
	char * s = ft_substr("", 5, 3);
	printf("returned : %s\n", s);
	return (0);
}
*/