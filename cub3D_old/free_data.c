/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:06:48 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 13:28:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	free_texture(t_data *mlx)
{
	free(mlx->map->path_no);
	mlx->map->path_no = NULL;
	free(mlx->map->path_so);
	mlx->map->path_so = NULL;
	free(mlx->map->path_we);
	mlx->map->path_we = NULL;
	free(mlx->map->path_ea);
	mlx->map->path_ea = NULL;
}

void	free_map_data(t_data *mlx)
{
	if (mlx->map->pos)
	{
		free(mlx->map->pos);
		mlx->map->pos = NULL;
	}
	free_array(mlx->map->map);
}

void	free_imgs_loads(t_data *data)
{
	free(data->wall->north);
	data->wall->north = NULL;
	free(data->wall->south);
	data->wall->south = NULL;
	free(data->wall->west);
	data->wall->west = NULL;
	free(data->wall->east);
	data->wall->east = NULL;
}

void	free_structs(t_data *mlx)
{
	free(mlx->ray);
	mlx->ray = NULL;
	free(mlx->dda);
	mlx->dda = NULL;
	free(mlx->pos);
	mlx->pos = NULL;
	free(mlx->wall);
	mlx->wall = NULL;
	free(mlx->mini);
	mlx->mini = NULL;
}
