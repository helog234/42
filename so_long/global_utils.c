/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:19:45 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/16 17:59:48 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_realloc(void *to_resized, size_t new_size)
{
	void	*pointer;

	if (new_size == 0)
	{
		if (to_resized != NULL)
			free(to_resized);
		return (NULL);
	}
	if (to_resized == NULL)
		return (malloc(new_size));
	pointer = malloc(new_size);
	if (pointer == NULL)
		return (NULL);
	pointer = ft_memcpy(pointer, to_resized, new_size);
	if (pointer == NULL)
	{
		free(pointer);
		return (NULL);
	}
	return (pointer);
}

