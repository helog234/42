/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:28:51 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/19 14:05:32 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	the_end(t_map **game)
{
	mlx_destroy_window((*game)->mlx, (*game)->win);
	ft_printf("Kitty manage to escape !\n");
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
