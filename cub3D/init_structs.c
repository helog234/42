/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:01:38 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/03 11:22:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	*load_img(t_data *mlx, char *path, int *width, int *height)
{
	void	*img;
	int		bpp;
	int		ll;
	int		endian;
	int		*i;

	img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, width, height);
	if (!img)
		return (NULL);
	i = (int *)mlx_get_data_addr(img, &bpp, &ll, &endian);
	free(img);
	img = NULL;
	return (i);
}

void	init_pos(t_map *map, t_data *mlx)
{
	mlx->pos->p_x = (float)map->pos[0] + 0.05;
	mlx->pos->p_y = (float)map->pos[1] + 0.05;
	if (map->dir == 'N' || map->dir == 'S')
		set_direction_n_s(map, mlx);
	else if (map->dir == 'E' || map->dir == 'W')
		set_direction_e_w(map, mlx);
	map->map[(int)mlx->pos->p_x][(int)mlx->pos->p_y] = '0';
}

void	init_dda(t_data *mlx)
{
	mlx->dda->grid = 0;
	mlx->dda->map_x = 0;
	mlx->dda->map_y = 0;
	mlx->dda->grid = 0;
	mlx->dda->step_x = 0;
	mlx->dda->step_y = 0;
	mlx->dda->wall_hit = 0;
}

void	init_wall(t_map *map, t_data *mlx)
{
	mlx->wall->tex_x = 0;
	mlx->wall->tex_y = 0;
	mlx->wall->tex_pos = 0;
	mlx->wall->tex_step = 0;
	mlx->wall->north = load_img(mlx, map->path_no, \
	&mlx->wall->no_w, &mlx->wall->no_h);
	mlx->wall->south = load_img(mlx, map->path_so, \
	&mlx->wall->so_w, &mlx->wall->so_h);
	mlx->wall->east = load_img(mlx, map->path_ea, \
	&mlx->wall->ea_w, &mlx->wall->ea_h);
	mlx->wall->west = load_img(mlx, map->path_we, \
	&mlx->wall->we_w, &mlx->wall->we_h);
	mlx->wall->ceiling = map->ceiling_rgb;
	mlx->wall->floor = map->floor_rgb;
	if (!mlx->wall->north || !mlx->wall->south \
	|| !mlx->wall->west || !mlx->wall->east)
		error_mngmt(5, "Problem loading image.\n", mlx);
	init_img(mlx);
}

void	init_mlx(t_data *mlx)
{
	mlx->ray = NULL;
	mlx->dda = NULL;
	mlx->pos = NULL;
	mlx->wall = NULL;
	mlx->dir_up_down = 0;
	mlx->dir_left_right = 0;
	mlx->dir_roatate = 0;
	mlx->map = NULL;
}
