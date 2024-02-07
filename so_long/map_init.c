/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:41:19 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/07 17:49:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	valid_map(char *str, t_map **game)
{
	int		y;
	int		x;
	int		control;
	char	*str;

	
	//mettre toutes les valeur de la map a 0 ou NULL au debut
	//et allouer map
	while (1)
	{
		(*game)->full_map[y] = get_next_line((*game)->fd);
		if ((*game)->full_map[y] == NULL)
			error_mngmt(1);
		(*game)->row = ft_strlen((*game)->full_map[y]);
		y++;
	}
	(*game)->col = y;
	x = 0;
	y = 0;
	control = 0;
	while ((*game)->full_map[y])
	{
		while ((*game)->full_map[y][x])
		{
			if (y == 0 || y == (*game)->col || x == 0 || x == (*game)->row && \
			x != '1')
				error_mngmt(1);
			//ajouter control duplicate exit ou start
			if ((*game)->full_map[y][x] == 'P' || (*game)->full_map[y][x] == 'E' \
			|| (*game)->full_map[y][x] == 'C')
				control++;
			x++;
		}
		if ((*game)->row != 0 && x != (*game)->row)
			error_mngmt(1);
		(*game)->row = x;
		y++;
	}
	if (control < 3)
		error_mngmt(1);
	return (1);
}

int	valid_game(t_map **game)
{
	int		x;
	int		y;
	t_map	*current;

	y = 0;
	current = *game;
	while (current->full_map[y])
	{
		x = 0;
		while (current->full_map[y][x])
		{
			current->nodes[y][x] = add_node(y, x, (int)current->full_map[y][x]);
			x++;
		}
		y++;
	}
	y = 0;
	x = 0;
	while (current->nodes[y])
	{
		while (current->nodes[y][x])
		{
			if (current->nodes[y][x]->current->nodes[y][x + 1]->type != '1')
			{
				current->nodes[y][x]->adj[0];
				current->nodes[y][x]->adj_nbr++;
			}
			if (current->nodes[y][x]->current->nodes[y + 1][x]->type != '1')
			{
				current->nodes[y][x]->adj[1];
				current->nodes[y][x]->adj_nbr++;
			}
			if (current->nodes[y][x]->current->nodes[y][x - 1]->type != '1')
			{
				current->nodes[y][x]->adj[2];
				current->nodes[y][x]->adj_nbr++;
			}
			if (current->nodes[y][x]->current->nodes[y - 1][x]->type != '1')
			{
				current->nodes[y][x]->adj[3];
				current->nodes[y][x]->adj_nbr++;
			}
			if (current->nodes[y][x]->type == 'P')
				current->p_start = current->nodes[y][x];
			else if (current->nodes[y][x]->type == 'E')
				current->exit = current->nodes[y][x];
			//trouver un moyen pour iterer sur tous les candy
			else if (current->nodes[y][x]->type == 'C')
				current->candy[4] = current->nodes[y][x];
			
			x++;
		}
		y++;
	}
	current->candy_nbr = //trouver comment recuperer donnee
	// recommencer ici pour faire l'algo DFS
	return (1);
}

int	is_playable(t_map **game)
{
	
}