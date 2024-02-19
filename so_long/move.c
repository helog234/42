/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:28:51 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/19 10:00:19 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	the_end(t_map **game)
{
	mlx_destroy_window((*game)->mlx, (*game)->win);
	// free_grid(game);
	exit(1);
}

t_node	*key_handler(int keycode, t_node *current_p)
{

	if (keycode == KEY_RIGHT)
		current_p = current_p->adj[0];
	else if (keycode == KEY_LEFT)
		current_p = current_p->adj[2];
	else if (keycode == KEY_UP)
		current_p = current_p->adj[3];
	else if (keycode == KEY_DOWN)
		current_p = current_p->adj[1];
	return (current_p);
}

int	check_key(int keycode, t_map **game)
{
	(void)game;
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT || \
	keycode == KEY_UP || keycode == KEY_DOWN)
		return (keycode);
	return (-1);
}


