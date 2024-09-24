/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:20:44 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/29 08:22:58 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*trim_line(char *line)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] && (line[i] == ' '))
		i++;
	if (ft_strnstr(line, "NO", i + 2) == 0 \
	|| ft_strnstr(line, "SO", i + 2) == 0 \
	|| ft_strnstr(line, "WE", i + 2) == 0 \
	|| ft_strnstr(line, "EA", i + 2) == 0)
		i = i + 2;
	while (line[i] && (line[i] == ' '))
		i++;
	new = ft_substr(line, i, ft_strlen(line) - i);
	if (!new)
		return (NULL);
	return (new);
}

int	get_texture_paths_from_file(char *line, t_map *map)
{
	char	*path;

	path = trim_line(line);
	if (!path)
		return (1);
	if (!map->path_no && \
	ft_strnstr(line, "NO", ft_strlen(line) - ft_strlen(path)) != NULL)
		map->path_no = path;
	else if (!map->path_so && \
	ft_strnstr(line, "SO", ft_strlen(line) - ft_strlen(path)) != NULL)
		map->path_so = path;
	else if (!map->path_we && \
	ft_strnstr(line, "WE", ft_strlen(line) - ft_strlen(path)) != NULL)
		map->path_we = path;
	else if (!map->path_ea && \
	ft_strnstr(line, "EA", ft_strlen(line) - ft_strlen(path)) != NULL)
		map->path_ea = path;
	return (0);
}

int	get_colors_from_file(char *line, t_map *map)
{
	char	*str;
	char	**split;
	int		rgb;
	int		i;

	i = 0;
	while (line[i] && (line[i] == 'F' || line[i] == 'C' || line[i] == ' '))
		i++;
	str = ft_substr(line, i, ft_strlen(line) - 1);
	if (!str)
		return (1);
	split = ft_split(str, ',');
	if (!split)
		return (free(str), 1);
	if (atoi_loop_for_rgb(split, &rgb) == -1)
		return (free_array(split), free(str), 1);
	if (map->floor_rgb == -1 \
	&& ft_strnstr(line, "F", ft_strlen(line) - ft_strlen(str)) != NULL)
		map->floor_rgb = rgb;
	else if (map->ceiling_rgb == -1 \
	&& ft_strnstr(line, "C", ft_strlen(line) - ft_strlen(str)) != NULL)
		map->ceiling_rgb = rgb;
	else
		return (free_array(split), free(str), 1);
	return (free_array(split), free(str), 0);
}

int	get_map_from_fd_o_to_fd_map(char *line, t_map *map)
{
	if (write(map->fd_map, line, ft_strlen(line)) == -1)
		return (1);
	return (0);
}
