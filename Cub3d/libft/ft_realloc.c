/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:22:42 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/25 16:30:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size, size_t current_size)
{
	void	*new_ptr;
	size_t	size_to_copy;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (new_size > current_size)
		size_to_copy = current_size;
	else
		size_to_copy = new_size;
	ft_memcpy(new_ptr, ptr, size_to_copy);
	free(ptr);
	return (new_ptr);
}
