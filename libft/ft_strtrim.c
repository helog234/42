/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:15:20 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/27 17:23:40 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	find_string(char const *s1, char const *set, int start)
{
	int		i;
	int		flag;

	while (s1[start])
	{
		i = 0;
		flag = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
			return (start);
		start++;
	}
	return (0);
}

static int	find_end(char const *s1, char const *set, int end)
{
	int		i;
	int		flag;

	end = end - 1;
	while (s1[end])
	{
		i = 0;
		flag = 0;
		while (set[i])
		{
			if (s1[end] == set[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
		{
			return (end);
		}
		end--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		lenght;
	char	*str3;

	i = 0;
	if (s1 == set)
		return ((char *)s1);
	start = find_string(s1, set, i);
	end = find_end(s1, set, ft_strlen(s1));
	lenght = end - start + 1;
	if (lenght <= 0 || start >= ft_strlen(s1) || s1 == 0)
		return (ft_strdup(""));
	str3 = ft_substr(s1, start, lenght);
	if (str3 == NULL)
		return (NULL);
	return (str3);
}
/*
#include <stdio.h>
int	main(void)
{
	//char	str1[] = "";
	//char	str2[] = "";
	char *s;
	char s2[] = "";
	printf("New string : %s\n", ft_strtrim("   xxx   xxx", " x"));
	s = ft_strtrim("   xxx   xxx", " x");
	printf("s2 = %s\n", s2);
	printf("Différence : %d\n", strcmp(s, ""));
	return (0);
}
*/