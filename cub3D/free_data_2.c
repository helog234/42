/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:09:39 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 13:10:46 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_mlx_map(t_data *data)
{
	close(data->map->fd_origin);
	close(data->map->fd_map);
	free(data->map);
	data->map = NULL;
}

void	free_mlx(t_data *mlx)
{
	free(mlx);
	mlx = NULL;
}

void	free_mlx_img(t_data *data)
{
	free(data->wall->img);
	data->wall->img = NULL;
	free(data->wall->data);
	data->wall->data = NULL;
}

void	free_window(t_data *data)
{
	free(data->mlx_win);
	data->mlx_win = NULL;
}
