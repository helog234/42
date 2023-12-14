/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:15:20 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/29 12:18:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
	return (-1);
}

int	end_check(int end)
{
	if (end < 0)
		end = 0;
	return (end);
}

static int	find_end(char const *s1, char const *set, int end)
{
	int		i;
	int		flag;

	end = end - 1;
	end = end_check(end);
	while (s1[end] && end > 0)
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
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	length;

	if (s1 == NULL)
		return (NULL);
	if (s1 == 0)
		return (ft_strdup(""));
	start = find_string(s1, set, 0);
	end = find_end(s1, set, ft_strlen(s1));
	if (start > end && end < 0)
		return (ft_strdup(""));
	length = end - start + 1;
	return (ft_substr(s1, start, length));
}
/*
#include <stdio.h>
int	main(void)
{
	//char	str1[] = "";
	//char	str2[] = "";
	char *s;
	char s2[] = "";
	printf("New string : %s\n", ft_strtrim("", ""));
	s = ft_strtrim("", "");
	printf("s2 = %s\n", s2);
	printf("Différence : %d\n", strcmp(s, ""));
	return (0);
}
*/