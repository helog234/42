/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:19:09 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/04 13:12:57 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_valid_data(int i, int j, char c, t_map *map)
{
	if (c == '0' || c == '1' || c == ' ')
		return (0);
	if (((c == 'N' || c == 'S' || c == 'E' || c == 'W')) \
	&& !map->pos && map->dir == 0)
	{
		map->pos = malloc(2 * sizeof(int));
		if (!map->pos)
			return (-1);
		set_player_position(i, j, map);
		map->dir = c;
		return (1);
	}
	return (-1);
}

void	get_len_col_above_and_below(int *col_above, \
int *col_below, int i, t_map *map)
{
	(*col_above) = ft_strlen(map->map[i - 1]);
	(*col_below) = ft_strlen(map->map[i + 1]);
}

int	is_border(int i, int j, t_map *map)
{
	if (i == 0 || i == map->rows)
		return (0);
	if (map->map[i][j] != ' ' && map->ctr == false)
	{
		map->ctr = true;
		return (0);
	}
	if ((map->ctr == true && map->map[i][j + 1] && map->map[i][j + 1] == ' ' ) \
	|| !(map->map[i][j + 1]))
	{
		map->ctr = false;
		return (0);
	}
	if (map->map[i][j] == ' ' && map->ctr == false)
		return (0);
	return (1);
}

int	check_inner_cell(int i, int j, int col, t_map *map)
{
	int	col_above;
	int	col_below;
	int	check;

	check = check_valid_data(i, j, map->map[i][j], map);
	if (check < 0)
		return (1);
	if (map->map[i][j] == '0' || check > 0)
	{
		get_len_col_above_and_below(&col_above, &col_below, i, map);
		if (col_above < col && j >= col_above)
			return (1);
		if (col_below < col && j >= col_below)
			return (1);
		if ((col_below == col || col_above == col) \
		&& (map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' ' \
		|| map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' '))
			return (1);
	}
	if (map->map[i][j] == ' ' \
	&& map->map[i][j - 1] != '1' && map->map[i][j + 1] != '1' \
	&& map->map[i - 1][j] != '1' && map->map[i + 1][j] != '1')
		return (1);
	return (0);
}

int	valid_data_array(int i, int j, int col, t_map *map)
{
	if (is_border(i, j, map) == 0)
	{
		if (map->map[i][j] == '1')
			return (0);
		if (map->ctr == false && map->map[i][j] == ' ')
			return (0);
		return (1);
	}
	if (map->map[i][j] != '1')
		return (check_inner_cell(i, j, col, map));
	return (0);
}
