/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:15:20 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/19 17:29:50 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"
#include <stdlib.h>
#include <string.h>

static int	memallocate (char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str3;

	i = 0;
	while (s1[i])
	{
		j = 0;
		if (s1[i] == set[j] && )
		{
			while (set[j])
				
		}
	}
}
char *ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str3;
	
	i = 0;
	while (s1[i])
	{
		j = 0;
		if (s1[i] == set[j])
		{
			
		}
	}
	str3 = (char *)malloc()
}

int	main(void)
{
	char	str1[] = "   Ok on y va   ";
	char	str2[] = " ";
	printf("New string : %s\n", ft_strtrim(str1, str2));
	return (0);
}