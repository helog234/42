/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:54:20 by hgandar           #+#    #+#             */
/*   Updated: 2023/11/14 13:28:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

char	*set_stock(char *stock)
{
	int		i;
	int		j;
	char	*new_stock;

	i = ft_strchr_line(stock, '\n');
	j = ft_strlen(stock);
	if (i >= 0)
		new_stock = ft_substr(stock, i + 1, j);
	else
		return (stock);
	return (new_stock);
}

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

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str3;

	i = 0;
	j = 0;
	str3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str3 == NULL)
		return (NULL);
	while (s1 && s1[i])
		str3[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		str3[j++] = s2[i++];
	str3[j] = 0;
	s1 = ft_strdup(str3);
	free(str3);
	if (s1 == NULL)
		return (NULL);
	return (s1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
