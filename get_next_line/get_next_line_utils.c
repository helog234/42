/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:36:43 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/08 16:54:28 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

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

unsigned long	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = i + j;
	if (i >= dstsize)
		return (dstsize + j);
	j = 0;
	while (src[j] && (i + 1 < dstsize))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (k);
}

char	*ft_strdup(const char *str1)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = (char *) malloc (ft_strlen(str1) + 1);
	if (str2 == NULL)
		return (NULL);
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
