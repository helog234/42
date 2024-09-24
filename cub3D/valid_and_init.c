/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:16:56 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 21:01:53 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_data *mlx, t_map **map, char *str)
{
	*map = malloc(sizeof(t_map));
	if (*map == NULL)
		error_mngmt(0, "Error malloc.\n", mlx);
	(*map)->fd_origin = open(str, O_RDONLY);
	if ((*map)->fd_origin == -1)
		error_mngmt(1, "Could not open file.\n", mlx);
	(*map)->fd_map = open(".tmp_map", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if ((*map)->fd_map == -1)
	{
		close((*map)->fd_origin);
		error_mngmt(1, "Could not open file.\n", mlx);
	}
	(*map)->rows = 0;
	(*map)->cols = 0;
	(*map)->path_no = NULL;
	(*map)->path_so = NULL;
	(*map)->path_we = NULL;
	(*map)->path_ea = NULL;
	(*map)->floor_rgb = -1;
	(*map)->ceiling_rgb = -1;
	(*map)->map = NULL;
	(*map)->pos = NULL;
	(*map)->dir = 0;
}

int	look_for_valid_settings_data(t_map *map, char *line)
{
	char	*trimed;
	int		i;

	trimed = ft_strtrim(line, "\n");
	if (!trimed)
		return (1);
	i = -2;
	if (ft_strnstr(trimed, "NO", ft_strlen(trimed)) != NULL \
	|| ft_strnstr(trimed, "SO", ft_strlen(trimed)) != NULL \
	|| ft_strnstr(trimed, "WE", ft_strlen(trimed)) != NULL \
	|| ft_strnstr(trimed, "EA", ft_strlen(trimed)) != NULL)
		i = get_texture_paths_from_file(trimed, map);
	if (i == -2 && (ft_strnstr(trimed, "F", ft_strlen(trimed)) != NULL || \
	ft_strnstr(trimed, "C", ft_strlen(trimed)) != NULL))
		i = get_colors_from_file(trimed, map);
	free(trimed);
	trimed = NULL;
	if (i != -2)
		return (i);
	return (1);
}

void	set_player_position(int y, int x, t_map *map)
{
	map->pos[0] = y;
	map->pos[1] = x;
	map->map[y][x] = '0';
}

int	check_for_limits_and_valid_data(t_map *map, int ctr)
{
	int	i;
	int	j;
	int	col;

	i = -1;
	while (map->map[++i])
	{
		col = 0;
		while (map->map[i][col])
			col++;
		j = 0;
		map->ctr = false;
		while (map->map[i][j])
		{
			if (valid_data_array(i, j, col, map) == 1)
				return (1);
			if (map->map[i][j] == '0')
				ctr = 1;
			j++;
		}
	}
	if (ctr == 0 || !map->pos)
		return (1);
	return (0);
}

int	get_map_into_int_array(t_map *map, int *i, char *line)
{
	int		j;

	while (1)
	{
		j = 0;
		line = get_next_line(map->fd_map);
		if (line == NULL)
			break ;
		malloc_row(map, line, *i);
		if (!map->map[*i])
			return (free(line), 1);
		while (line[j] && line[j] != '\n')
		{
			map->map[*i][j] = line[j];
			j++;
		}
		map->map[*i][j] = '\0';
		*i += 1;
		free(line);
	}
	if (*i != 0)
		map->map[*i] = NULL;
	return (*i);
}
