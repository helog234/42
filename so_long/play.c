/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:46:06 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/15 17:08:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_map(t_node *next, t_map **game)
{
	char	*relative_path;

	relative_path = "img/new_cat.xpm";
	next->img_asset = (*game)->player->position->img_asset;
	if (next->type == 'C')
	{
		(*game)->player->candy_col += 1;
		next->type = '0';
		relative_path = "img/new_cat.xpm";
		next->img_asset = NULL;
		mlx_put_image_to_window((*game)->mlx, (*game)->win, \
		(*game)->player->position->img_bg, \
		(*game)->player->position->x * WIN_W, \
		(*game)->player->position->y * WIN_H);
	}
	(*game)->player->position = next;
	mlx_put_image_to_window((*game)->mlx, (*game)->win, \
	(*game)->player->position->img_asset, (*game)->player->position->x * WIN_W, \
	(*game)->player->position->y * WIN_H);
}

int	explore_map(int keycode, t_map **game)
{
	t_node	*current;
	t_node	*next;
	//int		keycode;

	current = (*game)->player->position;
	// keycode = mlx_hook((*game)->mlx, 2, 1L << 0, check_key, game);
	if (keycode == KEY_ESC)
		mlx_hook((*game)->win, 2, KEY_ESC, close_w, &game);
	printf("%i\n", keycode);
	if (keycode > 0)
	{
		if ((keycode == KEY_RIGHT && current->adj[0]->type == '1') || \
		(keycode == KEY_LEFT && current->adj[2]->type == '1') || \
		(keycode == KEY_UP && current->adj[3]->type == '1') || \
		(keycode == KEY_DOWN && current->adj[1]->type == '1'))
			return (0);
		if (keycode == KEY_ESC)
			return (1);
		next = key_handler(keycode, current);
		refresh_map(next, game);
	}
	return (0);
}

/* void	lets_play(t_map **game)
{
	 ((*game)->player->position == (*game)->exit && \
	(*game)->player->candy_col <= (*game)->candy_nbr)
		return ;
		
	//mlx_hook((*game)->win, 4, 1L << 0, explore_map, &game);
	//mlx_loop((*game)->mlx);
	//sleep(1);
} */
