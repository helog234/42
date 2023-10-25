/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:15:20 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/25 10:44:12 by hgandar          ###   ########.fr       */
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
	start = find_string(s1, set, i);
	end = find_end(s1, set, ft_strlen(s1));
	lenght = end - start + 1;
	str3 = ft_substr(s1, start, lenght);
	if (str3 == NULL)
		return (NULL);
	return (str3);
}
/*
int	main(void)
{
	char	str1[] = "ababaaaMy name is Simonbbaaabba";
	char	str2[] = "ab";
	printf("New string : %s\n", ft_strtrim(str1, str2));
	return (0);
}
*/