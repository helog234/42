/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:10:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/13 16:38:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_map **game)
{
	int	y;
	int	x;
	int		img_width;
	int		img_height;
	char	*relative_path;
	void	*img;

	y = 0;
	while (y <(*game)->row)
	{
		x = 0;
		while (x < (*game)->col)
		{
			if ((x == 0 && y == 0) || (x == 0 && y + 1 == (*game)->row))
			{
				relative_path = "img/Big-wooden-fence-1.xpm";
				(*game)->nodes[y][x]->img_bg = mlx_xpm_file_to_image((*game)->mlx, relative_path, &img_width, &img_height);
			}
			else if ((y == 0 && x + 1 == (*game)->col) || (y + 1 == (*game)->col && x + 1 == (*game)->col))
			{
				relative_path = "img/Big-wooden-fence-3.xpm";
				(*game)->nodes[y][x]->img_bg = mlx_xpm_file_to_image((*game)->mlx, relative_path, &img_width, &img_height);
			}
			else if (y == 0 || y + 1 == (*game)->row)
			{
				relative_path = "img/Big-wooden-fence-2.xpm";
				(*game)->nodes[y][x]->img_bg = mlx_xpm_file_to_image((*game)->mlx, relative_path, &img_width, &img_height);
			}
			else if ((*game)->nodes[y][x]->type == '1')
			{
				relative_path = "img/grass.xpm";
				(*game)->nodes[y][x]->img_bg = mlx_xpm_file_to_image((*game)->mlx, relative_path, &img_width, &img_height);
			}
			/* else
			{
				
			} */
			if ((*game)->nodes[y][x]->img_bg == NULL)
					printf("bon\n");
			x++;
		}
		y++;
	}
}

void	draw_sprites(t_map **game)
{
	int	y;
	int	x;
	int		img_width;
	int		img_height;
	char	*relative_path;
	
	y = 1;
	while (y < (*game)->row - 1)
	{
		x = 1;
		while (x < (*game)->col - 1)
		{
			if ((*game)->nodes[y][x]->type == 'P')
			{
				relative_path = "img/new_cat.xpm";
				(*game)->nodes[y][x]->img_asset = mlx_xpm_file_to_image((*game)->mlx, relative_path, &img_width, &img_height);
			}
			else if ((*game)->nodes[y][x]->type == 'E')
			{
				relative_path = "img/door.xpm";
				(*game)->nodes[y][x]->img_asset = mlx_xpm_file_to_image((*game)->mlx, relative_path, &img_width, &img_height);
			}
			else if ((*game)->nodes[y][x]->type == 'C')
			{
				relative_path = "img/Chest.xpm";
				(*game)->nodes[y][x]->img_asset = mlx_xpm_file_to_image((*game)->mlx, relative_path, &img_width, &img_height);
			}
			x++;
		}
		
		y++;
	}
}

void	drap_map(t_map **game)
{
	int	y;
	int	x;

	y = 0;
	draw_background(game);
	draw_sprites(game);
	while (y < (*game)->row)
	{
		x = 0;
		while (x < (*game)->col)
		{
			mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->nodes[y][x]->img_bg, (*game)->nodes[y], (*game)->nodes[y][x]);
			if ((*game)->nodes[y][x]->img_asset != NULL)
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->nodes[y][x]->img_asset, (*game)->nodes[y], (*game)->nodes[y][x]);
			x++;
		}
		y++;
	}
}
