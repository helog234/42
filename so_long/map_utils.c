/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:44:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/19 16:24:27 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_adj(t_map **game, int y, int x)
{
	if (x < (*game)->col - 1)
	{
		(*game)->nodes[y][x]->adj[0] = (*game)->nodes[y][x + 1];
		(*game)->nodes[y][x]->adj_nbr++;
	}
	if (y < (*game)->row - 1)
	{
		(*game)->nodes[y][x]->adj[1] = (*game)->nodes[y + 1][x];
		(*game)->nodes[y][x]->adj_nbr++;
	}
	if (x > 0)
	{
		(*game)->nodes[y][x]->adj[2] = (*game)->nodes[y][x - 1];
		(*game)->nodes[y][x]->adj_nbr++;
	}
	if (y > 0)
	{
		(*game)->nodes[y][x]->adj[3] = (*game)->nodes[y - 1][x];
		(*game)->nodes[y][x]->adj_nbr++;
	}
}

void	create_grid(t_map **game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*game)->row)
	{
		j = 0;
		while (j < (*game)->col)
		{
			link_adj(game, i, j);
			j++;
		}
		i++;
	}
}

void	create_map(char *str, t_map **game)
{
	*game = malloc(sizeof(t_map));
	if (game == NULL)
		error_mngmt(0, game);
	(*game)->fd = open(str, O_RDONLY);
	if ((*game)->fd == -1)
	{
		free(*game);
		error_mngmt(1, game);
	}
	(*game)->nodes = NULL;
	(*game)->p_start = NULL;
	(*game)->row = 0;
	(*game)->col = 0;
	(*game)->exit = NULL;
	(*game)->escap = false;
	(*game)->candy_nbr = 0;
	(*game)->player = NULL;
	(*game)->door = NULL;
}
