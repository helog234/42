/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:54:20 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:31:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len, size_t i)
{
	char	*str;

	if (start + len > (size_t)ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	if (len < 0)
		return ((char *) s);
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
	s1 = NULL;
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
	free(str);
	str = NULL;
	return (NULL);
}

int	control_gnl(char **stock, char *buffer, int i)
{
	int	control;

	buffer[i] = 0;
	*stock = ft_strjoin_gnl(*stock, buffer);
	control = ft_strchr_line(*stock, '\n');
	if (control == -2 && i == 0)
	{
		if (ft_strlen_gnl(*stock) > 0)
			return (1);
		free(*stock);
		return (0);
	}
	if (control >= 0)
		return (1);
	return (-1);
}
