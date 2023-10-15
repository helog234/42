/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:06:27 by hgandar           #+#    #+#             */
/*   Updated: 2023/10/15 19:13:31 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	
}

#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	unsigned int	count;
	unsigned int	size;
	count = 4;
	size = 2;
	printf("Result: %p\n", ft_calloc(count, size));
	printf("Result: %p\n", calloc(count, size));
	return (0);
}