/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:05:05 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: split string, with specified character as delimiter, into an
**			array of strings
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns an array of strings
**	obtained by splitting ’s’ using the character ’c’ as a delimiter.
**	The array must be ended by a NULL pointer.
*/

#include "libft.h"
#include <stdio.h>

static int	count_strs(char const *s, char c);

static char	**cpy_str(char *s, char c, int no_arr, char **arr);

static void	free_arr(char **arr, int i);

char	**ft_split(char const *s, char c)
{
	char	*str;
	int		no_arr;
	char	**ret_arr;
	char	set[2];

	set[0] = c;
	set[1] = 0;
	str = ft_strtrim(s, (const char *)set);
	if (!str)
		return (NULL);
	no_arr = count_strs(str, c);
	ret_arr = (char **)malloc((no_arr + 1) * sizeof(char *));
	if (!ret_arr)
	{
		free(str);
		return (NULL);
	}
	ret_arr = cpy_str(str, c, no_arr, ret_arr);
	if (str)
		free(str);
	return (ret_arr);
}
/*
#include <stdio.h>

int main(void)
{
	char *s = "hello!";
	//char c = 0;
	char **result = ft_split(s, ' ');
	int i = 0;

	while (result[i] != 0)
	{
		printf("%s", result[i]);
		printf("\n");
		i++;
	}
}*/

static int	count_strs(char const *s, char c)
{
	int	count;

	count = 1;
	s = ft_strchr(s, c);
	if (!c)
		return (count);
	while (s && *s == c)
		s++;
	if (s && *s)
		count += count_strs(s, c);
	return (count);
}

static char	**cpy_str(char *s, char c, int no_arr, char **arr)
{
	int		i;
	int		len;
	int		p;

	i = 0;
	p = 0;
	while (i < no_arr && s[p])
	{
		len = p;
		while (s[len] != c && s[len])
			len++;
		len -= p;
		arr[i] = ft_substr(s, p, len);
		if (!arr[i])
			no_arr = 0;
		p += len;
		while (s[p] == c && s[p])
			p++;
		i++;
	}
	arr[i] = 0;
	if (no_arr == 0)
		free_arr (arr, i--);
	return (arr);
}

static void	free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		free (arr[i]);
		i--;
	}
	free (arr);
	arr = NULL;
}
