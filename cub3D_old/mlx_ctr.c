/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ctr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:47:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/03 15:26:55 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_mlx(data);
	if (keycode == UP)
		data->dir_up_down = 1;
	if (keycode == DOWN)
		data->dir_up_down = -1;
	if (keycode == RIGHT)
		data->dir_left_right = 1;
	if (keycode == LEFT)
		data->dir_left_right = -1;
	if (keycode == TURN_RIGHT)
		data->dir_roatate = -1;
	if (keycode == TURN_LEFT)
		data->dir_roatate = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN)
		data->dir_up_down = 0;
	if (keycode == RIGHT || keycode == LEFT)
		data->dir_left_right = 0;
	if (keycode == TURN_RIGHT || keycode == TURN_LEFT)
		data->dir_roatate = 0;
	return (0);
}

int	close_mlx(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	error_mngmt(9, NULL, mlx);
	exit (0);
}
