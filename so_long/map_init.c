/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:41:19 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 13:04:49 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char *str, t_map **game, int y)
{
	char	*to_node;

	create_map(str, game);
	to_node = get_next_line((*game)->fd);
	while (to_node)
	{
		if (parsing(to_node, game, y) == 0)
		{
			free(to_node);
			return (0);
		}
		free(to_node);
		to_node = get_next_line((*game)->fd);
		y++;
	}
	(*game)->row = y;
	if ((*game)->candy_nbr == 0 || (*game)->exit == NULL \
	|| (*game)->p_start == NULL)
		return (0);
	create_grid(game);
	return (1);
}

int	check_limits(t_map **game)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*game)->row)
	{
		x = 0;
		while (x < (*game)->col)
		{
			if ((x == 0 && (*game)->nodes[y][x]->type != '1') ||
			(x + 1 == (*game)->col && (*game)->nodes[y][x]->type != '1') \
			|| (y == 0 && (*game)->nodes[y][x]->type != '1') || \
			(y + 1 == (*game)->row && (*game)->nodes[y][x]->type != '1'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_playable(t_player *player, t_map **game, t_node *current_p)
{
	int		i;

	i = 0;
	if (current_p == NULL)
		return (0);
	if (current_p == (*game)->exit && player->candy_col == (*game)->candy_nbr)
		return (1);
	if (current_p == (*game)->exit && player->candy_col < (*game)->candy_nbr)
		(*game)->escap = true;
	if (current_p->type == 'C' && current_p->visited == false)
		player->candy_col++;
	if ((*game)->escap == true && player->candy_col == (*game)->candy_nbr)
		return (1);
	current_p->visited = true;
	while (i < current_p->adj_nbr)
	{
		if (current_p->adj[i] != NULL && current_p->adj[i]->visited \
		== false && current_p->adj[i]->type != '1')
		{
			if (is_playable(player, game, current_p->adj[i]) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}	

int	valid_game(t_map **game)
{
	(*game)->player = malloc(sizeof(t_player));
	if ((*game)->player == NULL)
		return (0);
	(*game)->player->candy_col = 0;
	(*game)->player->position = (*game)->p_start;
	if (is_playable((*game)->player, game, (*game)->player->position) == 1)
		return (1);
	return (0);
}
