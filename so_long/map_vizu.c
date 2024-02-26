/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vizu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:53 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 11:56:16 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vizualizer(t_map **game)
{
	int	x;
	int	y;

	y = 0;
	write(1, "----------", 10);
	write(1, "\n", 1);
	while (y < (*game)->row)
	{
		x = 0;
		while (x < (*game)->col)
		{
			if ((*game)->nodes[y][x]->visited == true)
				write(1, "*", 1);
			else
				write(1, &(*game)->nodes[y][x]->type, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
