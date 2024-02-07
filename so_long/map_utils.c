/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:44:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/07 17:55:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_adj(t_node **nodes, int y, int x)
{
	int		i;
	int		j;
	t_node	*to_init;

	i = 0;
	j = 0;
	to_init = *nodes;
	if (to_init->adj[y][x + 1]->type != '1')
		to_init
}

t_node	*add_node(int y, int x, int type)
{
	t_node	*new_node;
	int		i;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		error_mngmt(1);
	i = 0;
	new_node->y = y;
	new_node->x = x;
	new_node->type = type;
	while (i <= 4)
	{
		new_node->adj[i] = NULL;
		i++;
	}
	new_node->adj_nbr = 0;
	return (new_node);
}

void	create_map( char *str, t_map **game)
{
	int	i;
	game = malloc(sizeof(t_map));
	(*game)->fd = open(str, O_RDONLY);
	if ((*game)->fd == -1)
	{
		//free map fonction
		error_mngmt(1);
	}
	i = 0;
	(*game)->full_map = NULL;
	(*game)->nodes = NULL;
	(*game)->p_start = NULL;
	(*game)->row = 0;
	(*game)->col = 0;
	(*game)->exit = NULL;
	while (i <= 4)
	{
		(*game)->candy[i] = NULL;
		i++;
	}
	(*game)->candy_nbr = 0;
}
