/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <mremenar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:10:37 by mremenar          #+#    #+#             */
/*   Updated: 2024/05/28 15:56:51 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move(t_data *data)
{
	if (data->dir_up_down)
		change_pos(data, data->pos->dir_x * data->dir_up_down, \
					data->pos->dir_y * data->dir_up_down, 0.05);
	if (data->dir_left_right)
		change_pos(data, data->pos->plane_x * data->dir_left_right, \
					data->pos->plane_y * data->dir_left_right, 0.05);
	if (data->dir_roatate)
		rotate(data, data->pos->dir_x, data->pos->plane_x, \
				0.05 * data->dir_roatate);
}

void	change_pos(t_data *data, float step_x, float step_y, float speed)
{
	t_pos	*p;

	p = data->pos;
	if (data->map->map[(int)(p->p_x + step_x * speed)][(int)p->p_y] == '0')
		p->p_x += step_x * speed;
	if (data->map->map[(int)p->p_x][(int)(p->p_y + step_y * speed)] == '0')
		p->p_y += step_y * speed;
}

void	rotate(t_data *data, float old_dirx, float old_planex, float angle)
{
	t_pos	*p;

	p = data->pos;
	p->dir_x = old_dirx * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dirx * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = old_planex * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_planex * sin(angle) + p->plane_y * cos(angle);
}
