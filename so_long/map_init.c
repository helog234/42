/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:41:19 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/15 16:45:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int	get_map_size(char *str, t_map **game)
{
	int		y;
	int		x;
	char	*to_node;

	create_map(str, game);
	y = 0;
	to_node = get_next_line((*game)->fd);
	while (to_node)
	{
		(*game)->str[y] = to_node;
		x = 0;
		while (to_node[x] && to_node[x] != '\n')
			x++;
		if (y == 0)
			(*game)->col = x;
		free(to_node);
		to_node = NULL;
		if (y > 0 && x != (*game)->col)
		{
			free(game);
			close((*game)->fd);
			error_mngmt(1);
		}
		to_node = get_next_line((*game)->fd);
		y++;
	}
	(*game)->row = y;
} */

int	valid_map(char *str, t_map **game)
{
	int		y;
	char	*to_node;

	create_map(str, game);
	y = 0;
	to_node = get_next_line((*game)->fd);
	while (to_node)
	{
		//printf("%s\n", to_node);
		if (parsing(to_node, game, y) == 0)
		{
			free(to_node);
			free_grid(game);
			error_mngmt(1);
		}
		free(to_node);
		to_node = get_next_line((*game)->fd);
		y++;
	}
	(*game)->row = y;
	if ((*game)->candy_nbr == 0 || (*game)->exit == NULL || (*game)->p_start == NULL)
	{
		free_grid(game);
		error_mngmt(1);
	}
	create_grid(game);
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
	if (current_p->type == 'C' && current_p->visited == false)
		player->candy_col++;
	current_p->visited = true;
	while (i < current_p->adj_nbr)
	{
		if (current_p->adj[i] != NULL && current_p->adj[i]->visited == false && current_p->adj[i]->type != '1')
		{
			if (is_playable(player, game, current_p->adj[i]) == 1)
				return (1);
		}
		i++;
	}
	current_p->visited = false;
	return (0);
}	

int	valid_game(t_map **game)
{
	//t_player	*player;

	(*game)->player = malloc(sizeof(t_player));
	if ((*game)->player == NULL)
		return (0);
	(*game)->player->candy_col = 0;
	(*game)->player->position = (*game)->p_start;
	//printf("initial x : %i and y : %i\n", player->position->x, player->position->y);
	if (is_playable((*game)->player, game, (*game)->player->position) == 1)
	{
		//printf("exit %i %i\n", (*game)->exit->x, (*game)->exit->y);
		//printf("candy %i\n", (*game)->candy_nbr);
		return (1);
	}
	return (0);
}

