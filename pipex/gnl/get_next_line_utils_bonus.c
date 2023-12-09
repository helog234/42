/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:05:13 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/09 18:10:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*ft_substr_l(char const *s, unsigned int start, size_t len, size_t i)
{
	char	*str;

	if (start + len > (size_t)ft_strlen(s))
		len = ft_strlen(s) - start;
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

char	*ft_strjoin_l(char *s1, char const *s2)
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
	free (s1);
	return (str3);
}

char	*free_str(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*init(char *stock, int fd)
{
	stock = malloc(1);
	if (stock == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	stock[0] = '\0';
	if (fd == -1 || fd >= FD_MAX)
		return (NULL);
	return (stock);
}