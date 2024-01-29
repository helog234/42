/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:21 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/25 11:41:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		else
			i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	*s;
	char s[] = "tripouille";
	//char	c[] = "";
	printf("s is : %d\n", ft_strchr(s, 't' + 256) == s);
	printf("s is : %d\n", strchr(s, 't' + 256) == s);
	return (0);
}
*/