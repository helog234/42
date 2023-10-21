/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:31:48 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/21 10:30:29 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
/*
char	fill_str(char const *str, c)
{
	
}
*/
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = 0;
	k = 0;
	str = malloc((count_c(s, c)+ 1)  * sizeof(char*));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
		{
			if (j != 0)
				str[j][k] = 0;
			str[j] = malloc(i - j + 1);
			j++;
			i++;
			k = 0;
			printf("New string : %s\n", str[j]);
		}
		else
		{
			str[j][k] = s[i];
			i++;
			k++;
		}	
	}
	str[j + 1] = NULL;
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