/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:19:34 by mremenar          #+#    #+#             */
/*   Updated: 2023/11/06 09:55:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description
** Applies the function ’f’ to each character of the
** string ’s’, and passing its index as first argument
** to create a new string (with malloc(3)) resulting
** from successive applications of ’f’.
** Return value: The string created from the successive applications
** of ’f’. Returns NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret_str;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s);
	ret_str = malloc(len + 1);
	if (!ret_str)
		return (0);
	ret_str[len] = 0;
	i = 0;
	while (i < len)
	{
		ret_str[i] = f(i, s[i]);
		i++;
	}
	return (ret_str);
}
/*
int	main(void)
{
	char	*s = "hello world";
	char	*s2;

	s2 = ft_strmapi(s, upper);	
	printf("Result: %s\n", s2);
}

static char upper(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ft_toupper(c);
	return (c);
}*/