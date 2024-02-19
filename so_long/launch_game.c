/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:10:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/19 11:39:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_fence(t_map **game, int x, int y)
{
	int		width;
	int		height;

	if ((x == 0 && y == 0) || (x == 0 && y + 1 == (*game)->row))
	(*game)->nodes[y][x]->img_asset = \
		mlx_xpm_file_to_image((*game)->mlx, FENCE_1, &width, &height);
	else if ((y == 0 && x + 1 == (*game)->col) || \
	(y + 1 == (*game)->col && x + 1 == (*game)->col))
		(*game)->nodes[y][x]->img_asset = \
		mlx_xpm_file_to_image((*game)->mlx, FENCE_3, &width, &height);
	else if (y == 0 || y + 1 == (*game)->row)
	(*game)->nodes[y][x]->img_asset = \
		mlx_xpm_file_to_image((*game)->mlx, FENCE_2, &width, &height);
	else if (x == 0 || x + 1 == (*game)->col)
	(*game)->nodes[y][x]->img_asset = \
		mlx_xpm_file_to_image((*game)->mlx, FENCE_4, &width, &height);
}

void	draw_background(t_map **game, int x, int y)
{
	int		width;
	int		height;

	while (y < (*game)->row)
	{
		x = 0;
		while (x < (*game)->col)
		{
			(*game)->nodes[y][x]->img_bg = \
			mlx_xpm_file_to_image((*game)->mlx, GRASS, &width, &height);
			if (y == 0 || y + 1 == (*game)->row || x == 0 || \
			x + 1 == (*game)->col)
				draw_fence(game, x, y);
			else if ((*game)->nodes[y][x]->type == '1')
				(*game)->nodes[y][x]->img_asset = \
				mlx_xpm_file_to_image((*game)->mlx, TREE, &width, &height);
			else
				(*game)->nodes[y][x]->img_asset = \
				mlx_xpm_file_to_image((*game)->mlx, GRASS, &width, &height);
			x++;
		}
		y++;
	}
}

void	draw_sprites(t_map **game, int x, int y)
{
	int		width;
	int		height;

	while (y < (*game)->row - 1)
	{
		x = 1;
		while (x < (*game)->col - 1)
		{
			if ((*game)->nodes[y][x]->type == 'P')
				(*game)->nodes[y][x]->img_asset = \
				mlx_xpm_file_to_image((*game)->mlx, CAT, &width, &height);
			else if ((*game)->nodes[y][x]->type == 'E')
			{
				(*game)->nodes[y][x]->img_asset = \
				mlx_xpm_file_to_image((*game)->mlx, DOOR, &width, &height);
				(*game)->door = \
				mlx_xpm_file_to_image((*game)->mlx, DOOR, &width, &height);
			}
			else if ((*game)->nodes[y][x]->type == 'C')
				(*game)->nodes[y][x]->img_asset = \
				mlx_xpm_file_to_image((*game)->mlx, CANDY, &width, &height);
			x++;
		}
		y++;
	}
}

void	draw_map(t_map **game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	draw_background(game, x, y);
	draw_sprites(game, 1, 1);
	while (y < (*game)->row)
	{
		x = 0;
		while (x < (*game)->col)
		{
			if ((*game)->nodes[y][x]->img_bg == NULL)
				error_map(game);
			mlx_put_image_to_window((*game)->mlx, (*game)->win, \
			(*game)->nodes[y][x]->img_bg, x * BPX, y * BPX);
			if ((*game)->nodes[y][x]->img_asset != NULL)
				mlx_put_image_to_window((*game)->mlx, (*game)->win, \
				(*game)->nodes[y][x]->img_asset, x * BPX, y * BPX);
			x++;
		}
		y++;
	}
}
