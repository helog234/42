/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:46:06 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 11:43:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_map(t_node *current, t_node *next, t_map **game)
{
	next->img_asset = (*game)->player->position->img_asset;
	if (next->type == 'C')
	{
		(*game)->player->candy_col += 1;
		next->type = '0';
		mlx_put_image_to_window((*game)->mlx, (*game)->win, \
		current->img_bg, current->x * BPX, current->y * BPX);
	}
	if (next == (*game)->exit && \
		(*game)->player->candy_col == (*game)->candy_nbr)
		the_end(game);
	if (current->type == 'E')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, \
		(*game)->door, current->x * BPX, current->y * BPX);
	else
		mlx_put_image_to_window((*game)->mlx, (*game)->win, \
		current->img_bg, current->x * BPX, current->y * BPX);
	(*game)->player->position = next;
	mlx_put_image_to_window((*game)->mlx, (*game)->win, \
	(*game)->player->position->img_asset, (*game)->player->position->x * BPX, \
	(*game)->player->position->y * BPX);
}

int	explore_map(int keycode, t_map **game)
{
	t_node	*current;
	t_node	*next;
	t_node	*prev;

	prev = NULL;
	current = (*game)->player->position;
	if (keycode == KEY_ESC)
		mlx_hook((*game)->win, 3, KEY_ESC, close_w, (*game));
	if (keycode > 0)
	{
		if ((keycode == KEY_RIGHT && current->adj[0]->type == '1') || \
		(keycode == KEY_LEFT && current->adj[2]->type == '1') || \
		(keycode == KEY_UP && current->adj[3]->type == '1') || \
		(keycode == KEY_DOWN && current->adj[1]->type == '1'))
			return (0);
		if (keycode == KEY_ESC)
			return (0);
		next = key_handler(keycode, current);
		prev = (*game)->player->position;
		refresh_map(current, next, game);
		(*game)->player->move += 1;
		ft_printf("Current number of move : %i\n", (*game)->player->move);
	}
	return (0);
}
