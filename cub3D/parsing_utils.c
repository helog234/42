/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:28:50 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 13:37:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	atoi_loop_for_rgb(char **split, int *rgb)
{
	int	nbr;
	int	tmp[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		nbr = ft_atoi(split[i]);
		if (nbr < 0 || nbr > 255)
			return (-1);
		tmp[i] = nbr;
		i++;
	}
	*rgb = (tmp[0] << 16) | (tmp[1] << 8) | tmp[2];
	return (0);
}

void	malloc_row(t_map *map, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
		j++;
	map->map[i] = malloc((j + 1) * sizeof(int));
	if (j > map->cols)
		map->cols = j;
}

void	set_direction_n_s(t_map *map, t_data *mlx)
{
	if (map->dir == 'N')
	{
		mlx->pos->dir_x = -1;
		mlx->pos->dir_y = 0;
		mlx->pos->plane_y = 0.66;
		mlx->pos->plane_x = 0;
	}
	else if (map->dir == 'S')
	{
		mlx->pos->dir_x = 1;
		mlx->pos->dir_y = 0;
		mlx->pos->plane_y = -0.66;
		mlx->pos->plane_x = 0;
	}
}

void	set_direction_e_w(t_map *map, t_data *mlx)
{
	if (map->dir == 'E')
	{
		mlx->pos->dir_x = 0;
		mlx->pos->dir_y = 1;
		mlx->pos->plane_y = 0;
		mlx->pos->plane_x = 0.66;
	}
	else if (map->dir == 'W')
	{
		mlx->pos->dir_x = 0;
		mlx->pos->dir_y = -1;
		mlx->pos->plane_y = 0;
		mlx->pos->plane_x = -0.66;
	}
}
