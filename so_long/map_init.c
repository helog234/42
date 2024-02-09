/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:41:19 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/09 18:48:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char *str, t_map **game)
{
	int		y;
	char	*to_node;

	create_map(str, game);
	y = 0;
	while (1)
	{
		to_node = get_next_line((*game)->fd);
		if (to_node == NULL)
		{
			free_grid(game);
			error_mngmt(1);
		}
		if (parsing(to_node, game, y) == 0)
		{
			free(to_node);
			free_grid(game);
			error_mngmt(1);
		}
		free(to_node);
		y++;
	}
	(*game)->row = y;
	if ((*game)->candy[0] == NULL || (*game)->exit == NULL || (*game)->p_start == NULL)
	{
		free_grid(game);
		error_mngmt(1);
	}
	create_grid(game);
	return (1);
}
int	is_playable(t_player **player, t_map **game)
{
	int		i;
	t_node	*original_position;
	t_node	*new_position;
	int		candy_count;

	i = 0;
	if ((*player)->position == NULL || (*player)->position->visited == true)
		return (0);
	(*player)->position->visited = true;
	if ((*player)->position == (*game)->exit && (*player)->candy_col == (*game)->candy_nbr)
		return (1);
	if ((*player)->position->type == 'C')
		(*player)->candy_col++;
	original_position = (*player)->position;
	candy_count = (*player)->candy_col;
	while (i < (*player)->position->adj_nbr)
	{
		new_position = (*player)->position->adj[i];
		if (new_position != NULL && new_position->visited == false && new_position->type != '1')
		{
			(*player)->position = new_position;
			if (is_playable(player, game) == 1)
				return (1);
			new_position = original_position;
			(*player)->candy_col = candy_count;
		}
		i++;
	}
	return (0);
}	

int	valid_game(t_map **game)
{
	t_player *player;
	
	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (0);
	player->candy_col = 0;
	player->position = (*game)->p_start;
	if (is_playable(&player, game) == 1)
		return (1);
	return (0);
}

