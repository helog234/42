/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:45:28 by mremenar          #+#    #+#             */
/*   Updated: 2024/06/04 13:15:19 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw(t_data *data)
{
	int			y;
	t_texture	*wall;

	wall = data->wall;
	wall->line_half_height = (int)((SCREEN_HEIGHT / data->ray->cam_pln_dist) \
							/ 2);
	wall->start = HALF_SCREEN_H - wall->line_half_height;
	if (wall->start < 0)
		wall->start = 0;
	wall->end = HALF_SCREEN_H + wall->line_half_height;
	if (wall->end >= SCREEN_HEIGHT)
		wall->end = SCREEN_HEIGHT - 1;
	y = -1;
	while (++y < wall->start)
		wall->data[y * SCREEN_WIDTH + data->ray->ray_px] = wall->ceiling;
	y = data->wall->start - 1;
	texture(data);
	draw_wall(data);
	y = data->wall->end -1;
	while (++y < SCREEN_HEIGHT)
		wall->data[y * SCREEN_WIDTH + data->ray->ray_px] = data->wall->floor;
}

void	texture(t_data *data)
{
	t_texture	*wall;
	t_ray		*ray;

	wall = data->wall;
	ray = data->ray;
	if (data->dda->grid == GRID_X)
		wall->wall_x = data->pos->p_y + ray->cam_pln_dist * ray->rdir_y;
	else
		wall->wall_x = data->pos->p_x + ray->cam_pln_dist * ray->rdir_x;
	wall->wall_x -= floorf(data->wall->wall_x);
	set_texture(data);
	wall->tex_x = (int)(wall->wall_x * (float)wall->tex_width);
	if ((data->dda->grid == GRID_X && data->ray->rdir_x > 0) || \
		(data->dda->grid == GRID_Y && data->ray->rdir_y < 0))
		data->wall->tex_x = data->wall->tex_width - data->wall->tex_x - 1;
	wall->tex_step = 1.0 * wall->tex_height / (wall->line_half_height * 2);
	wall->tex_pos = (wall->start - HALF_SCREEN_H + \
						wall->line_half_height) * wall->tex_step;
}

// sets the texture to draw depending on the wall we are drawing ( N, S, E or W)
void	set_texture(t_data *data)
{
	if (data->dda->grid == GRID_X && data->ray->rdir_x < 0)
	{
		data->wall->tex_width = data->wall->no_w;
		data->wall->tex_height = data->wall->no_h;
	}
	else if (data->dda->grid == GRID_X && data->ray->rdir_x > 0)
	{
		data->wall->tex_width = data->wall->so_w;
		data->wall->tex_height = data->wall->so_h;
	}
	else if (data->dda->grid == GRID_Y && data->ray->rdir_y < 0)
	{
		data->wall->tex_width = data->wall->we_w;
		data->wall->tex_height = data->wall->we_h;
	}
	else if (data->dda->grid == GRID_Y && data->ray->rdir_y > 0)
	{
		data->wall->tex_width = data->wall->ea_w;
		data->wall->tex_height = data->wall->ea_h;
	}
}

void	draw_wall(t_data *data)
{
	t_texture	*wall;
	int			color;
	int			y;

	wall = data->wall;
	y = wall->start - 1;
	while (++y <= wall->end)
	{
		wall->tex_y = (int)wall->tex_pos & (wall->tex_height - 1);
		wall->tex_pos += wall->tex_step;
		if (data->dda->grid == GRID_X && data->ray->rdir_x < 0)
			color = wall->north[wall->tex_height * wall->tex_y + wall->tex_x];
		else if (data->dda->grid == GRID_X && data->ray->rdir_x > 0)
			color = wall->south[wall->tex_height * wall->tex_y + wall->tex_x];
		else if (data->dda->grid == GRID_Y && data->ray->rdir_y < 0)
			color = wall->west[wall->tex_height * wall->tex_y + wall->tex_x];
		else if (data->dda->grid == GRID_Y && data->ray->rdir_y > 0)
			color = wall->east[wall->tex_height * wall->tex_y + wall->tex_x];
		wall->data[y * SCREEN_WIDTH + data->ray->ray_px] = color;
	}
}
