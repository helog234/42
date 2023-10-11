/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:54:19 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/11 18:34:59 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*c_last;

	i = 0;
	c_last = 0;
	while (s[i])
	{
		if (s[i] == c)
			c_last = &s[i];
		i++;
	}
	//if (c == 0)
		///return (0);
	return (c_last);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] ="Hello World !";
	//Bug avec 0 en argument
	char	c = 0;
	printf("s is : %p\n", ft_strrchr(s, c));
	printf("s is : %p\n", strrchr(s, c));
	return (0);
}
