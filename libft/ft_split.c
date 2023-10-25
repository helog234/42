/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:31:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/25 10:24:53 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	count_c(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

static int	count_str(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strndup(const char *str1, int n)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = (char *) malloc (ft_strlen(str1) + 1);
	if (str2 == NULL)
		return (NULL);
	while (str1[i] && i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	str = (char **)malloc((count_c(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		k = count_str(s + i, c, 0);
		str[j] = ft_strndup(s + i, k);
		if (str[j] == NULL)
			return (NULL);
		i += k;
		j++;
	}
	str[j] = NULL;
	return (str);
}
/*
int	main(void)
{
	char	str1[] = "HelloaWorlda!aHelloaWorlda!";
	char	c = 'a';
	ft_split(str1, c);
	//printf("New string : %s\n", ft_split(str1, c));
	return (0);
}
*/