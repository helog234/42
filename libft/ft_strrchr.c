/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:54:19 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/19 11:41:12 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	while (s[i])
	{
		if (s[i] == (char) c)
			result = (char *) &s[i];
		i++;
	}
	if (s[i] == (char) c)
		result = (char *) &s[i];
	return (result);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] ="Hello World !";
	char	c = 'H';
	printf("s is : %p\n", ft_strrchr(s, c));
	printf("s is : %p\n", strrchr(s, c));
	return (0);
}
*/