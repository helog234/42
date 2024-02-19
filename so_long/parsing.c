/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:19:45 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/19 11:42:22 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_realloc(void *to_resized, size_t new_size)
{
	void	*pointer;

	if (new_size == 0)
	{
		if (to_resized != NULL)
			free(to_resized);
		return (NULL);
	}
	if (to_resized == NULL)
		return (malloc(new_size));
	pointer = malloc(new_size);
	if (pointer == NULL)
		return (NULL);
	ft_memcpy(pointer, to_resized, new_size);
	free(to_resized);
	return (pointer);
}

t_node	*add_node(int y, int x, int type)
{
	t_node	*new_node;
	int		i;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	i = 0;
	new_node->y = y;
	new_node->x = x;
	new_node->type = type;
	new_node->visited = false;
	new_node->img_asset = NULL;
	new_node->img_bg = NULL;
	while (i < 4)
	{
		new_node->adj[i] = NULL;
		i++;
	}
	new_node->adj_nbr = 0;
	return (new_node);
}

void	control_data(int flag, t_map **game, int y, int x)
{
	if (flag == 'C')
	{
		(*game)->candy_nbr++;
	}
	else if (flag == 'E' && (*game)->exit == NULL)
		(*game)->exit = (*game)->nodes[y][x];
	else if (flag == 'P' && (*game)->p_start == NULL)
		(*game)->p_start = (*game)->nodes[y][x];
}

int	loop_node(t_map **game, char *str, int y)
{
	int	x;

	x = 0;
	while (str[x] != '\n' && str[x])
	{
		(*game)->nodes[y][x] = add_node(y, x, (int)str[x]);
		if ((*game)->nodes[y][x] == NULL)
			return (0);
		if (str[x] != '0' && str[x] != '1' && \
		str[x] != 'C' && str[x] != 'E' && str[x] != 'P')
			return (0);
		if (str[x] == 'C' || str[x] == 'E' || str[x] == 'P')
			control_data(str[x], game, y, x);
		x++;
	}
	if (y == 0)
	(*game)->col = x;
	return (x);
}

int	parsing(char *str, t_map **game, int y)
{
	int		x;
	t_node	***new;

	new = ft_realloc((*game)->nodes, (y + 1) * sizeof(t_node *));
	if (new == NULL)
		return (0);
	(*game)->nodes = new;
	(*game)->nodes[y] = malloc(sizeof(t_node *) * ft_strlen(str));
	if ((*game)->nodes == NULL || (*game)->nodes[y] == NULL)
		return (0);
	x = loop_node(game, str, y);
	if (y > 0 && x != (*game)->col)
		return (0);
	return (1);
}
