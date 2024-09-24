/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:00:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 14:06:44 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (0);
	while (str[i])
		i++;
	if (str[i - 4] != '.')
		return (1);
	if (str[i - 3] != 'c')
		return (1);
	if (str[i - 2] != 'u')
		return (0);
	if (str[i - 1] != 'b')
		return (1);
	return (0);
}

int	valid_file_and_init_map(char *str, t_map **map, t_data *mlx)
{
	char	*line;

	init_map(mlx, map, str);
	line = NULL;
	while (1)
	{
		line = get_next_line((*map)->fd_origin);
		if (line == NULL)
			break ;
		if (line[0] != '\n' && (*map)->path_no && (*map)->path_so \
		&& (*map)->path_we && (*map)->path_ea \
		&& (*map)->floor_rgb >= 0 && (*map)->ceiling_rgb >= 0)
		{
			if (get_map_from_fd_o_to_fd_map(line, *map) == 1)
				return (free(line), 1);
			(*map)->rows++;
		}
		else if ((line[0] != '\n' && !(*map)->map \
		&& look_for_valid_settings_data(*map, line) == 1) \
		|| (line[0] == '\n' && (*map)->rows))
			return (free(line), 1);
		free(line);
	}
	(*map)->rows--;
	return (0);
}

int	valid_map(t_map *map, t_data *mlx)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	close(map->fd_map);
	map->fd_map = open(".tmp_map", O_RDWR, 0644);
	if (map->fd_map == -1)
		return (error_mngmt(2, "Could not open file.\n", mlx), 1);
	map->map = malloc((map->rows + 2) * sizeof(char *));
	if (!map->map)
		return (error_mngmt(2, "Could not open file.\n", mlx), 1);
	if (get_map_into_int_array(map, &i, line) < 3)
	{
		if (i == 0)
		{
			free(map->map);
			error_mngmt(2, "Unvalid map.\n", mlx);
		}
		error_mngmt(3, "Unvalid map.\n", mlx);
	}
	if (check_for_limits_and_valid_data(map, 0) == 1)
		return (1);
	return (0);
}

int	init_structs(t_map *map, t_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error_mngmt(3, "Error initiazing pointer.\n", mlx);
	mlx->ray = malloc(sizeof(t_ray));
	mlx->dda = malloc(sizeof(t_dda));
	mlx->pos = malloc(sizeof(t_pos));
	mlx->wall = malloc(sizeof(t_texture));
	mlx->mini = malloc(sizeof(t_mini));
	if (!mlx->ray || !mlx->dda || !mlx->pos || !mlx->wall || !mlx->mini)
		return (1);
	mlx->ray->cam_pln_dist = 0;
	init_dda(mlx);
	init_pos(map, mlx);
	init_wall(map, mlx);
	init_mini(mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH, \
		SCREEN_HEIGHT, "cub3D");
	if (!mlx->mlx_win)
		error_mngmt(7, "Problem creating window.\n", mlx);
	return (0);
}

int	map_checker_and_init(int argc, char *argv[], t_data *mlx)
{
	if (argc != 2)
		error_mngmt(0, "Wrong number of arguments.\n", mlx);
	if (map_format(argv[1]) != 0)
		error_mngmt(0, "Wrong map format.\n", mlx);
	init_mlx(mlx);
	if (valid_file_and_init_map(argv[1], &mlx->map, mlx) != 0)
		error_mngmt(2, "File unvalid or error while init.\n", mlx);
	if (valid_map(mlx->map, mlx) != 0)
		error_mngmt(3, "Unvalid map or error malloc.\n", mlx);
	if (init_structs(mlx->map, mlx) != 0)
		error_mngmt(4, "Error initializing structs\n", mlx);
	return (0);
}
