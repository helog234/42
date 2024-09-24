/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:29:04 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 13:10:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_mngmt(int flag, char *str, t_data *mlx)
{
	if (flag >= 6)
		free_mlx_img(mlx);
	if (flag >= 5)
		free_imgs_loads(mlx);
	if (flag >= 4)
		free_structs(mlx);
	if (flag >= 3)
		free_map_data(mlx);
	if (flag >= 2)
		free_texture(mlx);
	if (flag >= 1)
		free_mlx_map(mlx);
	if (flag >= 0)
		free_mlx(mlx);
	if (flag > 8)
		return ;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}
