/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:05:13 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/29 17:43:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len, size_t i)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if (start + len > (size_t)ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	if (start > (unsigned int) ft_strlen_gnl(s))
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

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str3;

	i = 0;
	j = 0;
	str3 = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
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

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*free_str(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
	return (NULL);
}
