/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:24:52 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/26 17:18:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	new_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
/*
#include <stdio.h>
char	f(unsigned int i, char str)
{
	printf("test = %d and %c\n", i, str);
	return (str);
}

int	main(void)
{
	char s[] = "Hello World";
	printf("new string : %s\n", ft_strmapi(s, f));
	return (0);
}
*/