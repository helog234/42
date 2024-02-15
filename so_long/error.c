/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:43:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/15 16:52:48 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_mngmt(int i)
{
	if (i == 0)
		printf("No valid map. Try again !");
	if (i == 1)
		printf("No valid map while parsing. Try again !");
	exit(1);
}
/* void	free_node(t_node **node)
{
	int	i;

	i = 0;
	
} */
/* void	free_node(t_node *node)
{
	int	i;

	i = 0;
	while (i <)
	{
	
	}
	
} */

void	free_grid(t_map **game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*game)->row)
	{
		j = 0;
		while (j < (*game)->col)
		{
			if ((*game)->nodes[i][j] != NULL)
			{
				free((*game)->nodes[i][j]);
				(*game)->nodes[i][j] = NULL;
			}
			j++;
		}
		i++;
	}
	/*i = 0
	 while (i < (*game)->candy_nbr)
	{
		free(*game)->candy)
	} */
	
	close((*game)->fd);
}
