/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:31:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/26 10:21:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
	str2 = malloc(n + 1 * sizeof(char));
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

static void	*free_c(char **str, int j)
{
	while (j > 0)
	{
		free(str[j - 1]);
		j--;
	}
	free(str);
	return (NULL);
}

static char	**fill_str(char const *s, char c, char **str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		k = count_str(s + i, c, 0);
		str[j] = ft_strndup(s + i, k);
		if (str[j] == NULL)
			return (free_c(str, j));
		i += k;
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = malloc((ft_strlen(s)+ 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str = fill_str(s, c, str);
	if (str == NULL)
		return (NULL);
	return (str);
}
/*
int	main(void)
{
	char	str1[] = "  tripouille  42  ";
	char	c = ' ';
	ft_split(str1, c);
	//printf("New string : %s\n", ft_split(str1, sizeof(char *) * 3));
	return (0);
}
*/