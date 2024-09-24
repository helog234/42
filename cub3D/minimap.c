/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:26:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 16:44:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color)
{
	int	pixel;

	if (x < 0 || y < 0)
		return ;
	pixel = y * mlx->mini->ll + x * (mlx->mini->bpp / 8);
	*((unsigned int *)(mlx->mini->img_pxl_ptr + pixel)) = color;
}

int	set_color(t_data *data, int y, int x)
{
	int	color;

	if (data->map->map[y][x] == '1' || data->map->map[y][x] == ' ')
		color = (0 << 16) | (0 << 8) | 0;
	else
		color = (255 << 16) | (255 << 8) | 255;
	return (color);
}

void	draw_tile_pxl(t_data *data, int y, int x, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (i <= MINI)
	{
		j = 0;
		while (j <= MINI)
		{
			my_mlx_pixel_put(data, x + j, y + i, mini->color);
			j++;
		}
		i++;
	}
}

void	rescale_and_set(t_data *data, int y, int x)
{
	int	flag;

	flag = 0;
	data->mini->color = set_color(data, y, x);
	if (x == (int)data->pos->p_y \
	&& y == (int)data->pos->p_x)
		flag = -1;
	x = x * MINI;
	y = y * MINI;
	draw_tile_pxl(data, y, x, data->mini);
	if (flag == -1)
	{
		data->mini->color = (194 << 16) | (123 << 8) | 160;
		data->mini->scale_y = MINI / 2;
		data->mini->scale_x = MINI / 2;
		draw_tile_pxl(data, y, x, data->mini);
	}
}

int	draw_minimap(t_data *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (mlx->map->map[y])
	{
		x = 0;
		while (mlx->map->map[y][x])
		{
			if (mlx->map->map[y][x] != ' ')
				rescale_and_set(mlx, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
