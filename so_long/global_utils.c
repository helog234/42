/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:19:45 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/10 11:09:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_realloc(size_t old_size, t_node **to_resized, size_t new_size)
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
	new_size = ((old_size) * new_size);
	ft_memcpy(pointer, to_resized, new_size);
	free(to_resized);
	if (pointer == NULL)
	{
		free(pointer);
		return (NULL);
	}
	return (pointer);
}

/* int *init_checker(int flag)
{
	int array[4];
	
	if (flag == 1)
	{
		array[0] = 1;  
		array[1] = 0;
		array[2] = -1;
		array[3] = 0;
	}
	else
	{
		array[0] = 0;
		array[1] = 1;
		array[2] = 0;
		array[3] = -1;
	}
	return (array);
} */
