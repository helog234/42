/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:21 by mremenar          #+#    #+#             */
/*   Updated: 2024/06/04 13:14:28 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_frame(t_data *data)
{
	play(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->mlx_win, data->wall->img, 0, 0);
	return (0);
}

int	play(t_data *data)
{
	data->ray->ray_px = -1;
	move(data);
	while (++data->ray->ray_px < SCREEN_WIDTH)
	{
		cast_ray(data->pos, data->ray);
		set_step(data->pos, data->ray, data->dda);
		perform_dda(data->ray, data->dda, data);
		draw(data);
	}
	return (0);
}

// calc ray position, direction and length between grids
void	cast_ray(t_pos *p, t_ray *r)
{
	p->cam = (2 * r->ray_px / (float) SCREEN_WIDTH) - 1;
	r->rdir_x = p->dir_x + p->plane_x * p->cam;
	r->rdir_y = p->dir_y + p->plane_y * p->cam;
	if (!r->rdir_x)
		r->dist_btw_x = 1e30;
	else
		r->dist_btw_x = fabsf(1 / r->rdir_x);
	if (!r->rdir_y)
		r->dist_btw_y = 1e30;
	else
		r->dist_btw_y = fabsf(1 / r->rdir_y);
}

// calc step direction and length to first grid
void	set_step(t_pos *p, t_ray *r, t_dda *dda)
{
	dda->map_x = (int)p->p_x;
	dda->map_y = (int)p->p_y;
	if (r->rdir_x < 0)
	{
		dda->step_x = -1;
		r->dist_to_x = (p->p_x - dda->map_x) * r->dist_btw_x;
	}
	else
	{
		dda->step_x = 1;
		r->dist_to_x = (dda->map_x + 1 - p->p_x) * r->dist_btw_x;
	}
	if (r->rdir_y < 0)
	{
		dda->step_y = -1;
		r->dist_to_y = (p->p_y - dda->map_y) * r->dist_btw_y;
	}
	else
	{
		dda->step_y = 1;
		r->dist_to_y = (dda->map_y + 1 - p->p_y) * r->dist_btw_y;
	}
}

void	perform_dda(t_ray *r, t_dda *dda, t_data *data)
{
	dda->wall_hit = WALL_NOT_HIT;
	while (!dda->wall_hit)
	{
		if (r->dist_to_x < r->dist_to_y)
		{
			r->dist_to_x += r->dist_btw_x;
			dda->map_x += dda->step_x;
			dda->grid = GRID_X;
		}
		else
		{
			r->dist_to_y += r->dist_btw_y;
			dda->map_y += dda->step_y;
			dda->grid = GRID_Y;
		}
		if (data->map->map[dda->map_x][dda->map_y] == '1')
			dda->wall_hit = WALL_HIT;
	}
	if (dda->grid == GRID_X)
		r->cam_pln_dist = r->dist_to_x - r->dist_btw_x;
	else
		r->cam_pln_dist = r->dist_to_y - r->dist_btw_y;
}
