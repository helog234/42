/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:06:27 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/27 16:16:17 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*pointer;

	pointer = malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 0, (count * size));
	return (pointer);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	unsigned int	count;
	unsigned int	size;
	count = 3;
	size = 3;
	printf("Result: %p\n", ft_calloc(count, size));
	printf("Result: %p\n", calloc(count, size));
	//free(ft_calloc);
	return (0);
}
*/