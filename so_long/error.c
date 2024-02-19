/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:43:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/19 10:02:56 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_mngmt(int i, t_map **game)
{
	if (i == 0)
	{
		free(game);
		ft_printf("No valid map. Try again !");
	}
	if (i == 1)
	{
		free_grid(game);
		ft_printf("No valid map while parsing. Try again !");
	}
	if (i == 3)
	{
		free_grid(game);
		ft_printf("No valid map. Try again !");
	}
	if (i == 4)
	{
		free_grid(game);
		ft_printf("Map not playable. Try again !");
	}
	exit(1);
}

void	error_map(t_map **game)
{
	free_grid(game);
	ft_printf("Error loading image. Try again !");
	exit(1);
}


void	free_grid(t_map **game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*game)->row)
	{
		j = 0;
		while (j < (*game)->col)
		{
			if ((*game)->nodes[i][j] != NULL)
			{
				free((*game)->nodes[i][j]);
				(*game)->nodes[i][j] = NULL;
			} 
			j++;
		}
		free((*game)->nodes[i]);
		i++;
	}
	close((*game)->fd);
	free(game);
}
