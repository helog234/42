/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:31:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/20 18:48:36 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
int		count_c(char const *s, char c)
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
*/
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	str = malloc(strlen(s)+ 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
		{
			str[i][j] = s[i - 1];
			str[i][j] = 0;
			i++;
			j = 0;
			printf("New string : %s\n", str[i]);
		}
		else
			i++;
	}
	str[i] = NULL;
	return (str);
}

int	main(void)
{
	char	str1[] = "ababaaaMy name is Simonbbaaabba";
	char	c = 'b';
	ft_split(str1, c);
	//printf("New string : %s\n", ft_split(str1, c));
	return (0);
}