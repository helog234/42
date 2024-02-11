/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:44:54 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/11 17:45:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_adj(t_map **game, int y, int x)
{
	/* printf("x : %i\n", x);
	printf("y : %i\n", y); */
	if (x < (*game)->col - 1 && (*game)->nodes[y][x + 1]->type != '1')
	{
		(*game)->nodes[y][x]->adj[0] = (*game)->nodes[y][x + 1];
		(*game)->nodes[y][x]->adj_nbr++;
	}
	if (y < (*game)->row - 1 &&  (*game)->nodes[y + 1][x]->type != '1')
	{
		(*game)->nodes[y][x]->adj[1] = (*game)->nodes[y + 1][x];
		(*game)->nodes[y][x]->adj_nbr++;
	}
	if (x > 0 && (*game)->nodes[y][x - 1]->type != '1')
	{
		(*game)->nodes[y][x]->adj[2] = (*game)->nodes[y][x - 1];
		(*game)->nodes[y][x]->adj_nbr++;
	}
	if (y > 0 && (*game)->nodes[y - 1][x]->type != '1')
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
/* 	printf("col : %i\n", (*game)->col);
	printf("row : %i\n", (*game)->row); */
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
	while (i < 4)
	{
		new_node->adj[i] = 0;
		i++;
	}
	new_node->adj_nbr = 0;
	return (new_node);
}

void	control_data(int flag, t_map **game, int y, int x)
{
	if (flag == 'C')
	{
		if ((*game)->candy_nbr == 0)
			(*game)->candy = malloc(sizeof(t_node*) * ((*game)->candy_nbr +1));
		else if ((*game)->candy_nbr > 0)
			(*game)->candy = ft_realloc((*game)->candy, (((*game)->candy_nbr + 2) * sizeof(t_node*)));
		(*game)->candy[(*game)->candy_nbr] = (*game)->nodes[y][x];
		//(*game)->candy[(*game)->candy_nbr + 1] = NULL;
		(*game)->candy_nbr++;
	}
	else if (flag == 'E' && (*game)->exit == NULL)
		(*game)->exit = (*game)->nodes[y][x];
	else if (flag == 'P' && (*game)->p_start == NULL)
		(*game)->p_start = (*game)->nodes[y][x];
}

int	parsing(char *str, t_map **game, int y)
{
	int	x;

	x = 0;
	if (y == 0)
	(*game)->nodes = malloc(sizeof(t_node*) * (y + 1));
	else
	{
		(*game)->nodes = ft_realloc((*game)->nodes, (y + 2) * sizeof(t_node*));
		//(*game)->nodes = realloc((*game)->nodes, (y + 2) * sizeof(t_node*));
	}
	(*game)->nodes[y] = malloc(sizeof(t_node*) * ft_strlen(str));
	if ((*game)->nodes == NULL || (*game)->nodes[y] == NULL)
		return (0);
	//printf("%s\n", str);
	//printf("%i\n", y);
	while (str[x] != '\n' && str[x])
	{
		//printf("%c\n", str[x]);
		(*game)->nodes[y][x] = add_node(y, x, (int)str[x]);
		if ((*game)->nodes[y][x] == NULL)
			return (0);
		if (str[x] != '0' && str[x] != '1' && \
		str[x] != 'C' && str[x] != 'E' && str[x] != 'P')
		{
			free_grid(game);
			error_mngmt(1);
		}
		if (str[x] == 'C' || str[x] == 'E' || str[x] == 'P')
			control_data(str[x], game, y, x);
		x++;
		//printf("strx %c\n", str[x]);
	}
	if (y == 0)
		(*game)->col = x;
	else if (y > 0 && x != (*game)->col)
	{
		free_grid(game);
		error_mngmt(1);
	}
	return (1);
}

void	create_map(char *str, t_map **game)
{
	*game = malloc(sizeof(t_map));
	if (game == NULL)
		error_mngmt(1);
	(*game)->fd = open(str, O_RDONLY);
	if ((*game)->fd == -1)
	{
		free(game);
		error_mngmt(1);
	}
	(*game)->nodes = NULL;
	(*game)->p_start = NULL;
	(*game)->row = 0;
	(*game)->col = 0;
	(*game)->exit = NULL;
	(*game)->candy = NULL;
	(*game)->candy_nbr = 0;
}
