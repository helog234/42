/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:57:07 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 13:12:07 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mini(t_data *data)
{
	data->mini->img_pxl_ptr = mlx_get_data_addr(data->wall->img, \
	&data->mini->bpp, &data->mini->ll, &data->mini->endian);
	if (!data->mini->img_pxl_ptr)
	{
		free(data->mini->img_mini);
		data->mini->img_mini = NULL;
		error_mngmt(6, "Error initializing mini ptr\n", data);
	}
}

void	init_img(t_data *data)
{
	data->wall->img = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!data->wall->img)
		error_mngmt(5, "Problem creating image.\n", data);
	data->wall->data = (int *)mlx_get_data_addr(data->wall->img, \
	&data->wall->bits_per_pixel, &data->wall->line_len, \
	&data->wall->endian);
	if (!data->wall->data)
	{
		free(data->wall->img);
		data->wall->img = NULL;
		error_mngmt(5, "Problem creating image.\n", data);
	}
}
