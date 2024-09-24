/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:58:17 by mremenar          #+#    #+#             */
/*   Updated: 2024/06/05 08:40:07 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("error malloc data"), 1);
	if (map_checker_and_init(argc, argv, data) == 0)
	{
		mlx_hook(data->mlx_win, ON_DESTROY, 0, &close_mlx, data);
		mlx_hook(data->mlx_win, KEY_PRESS, 0, &key_press, data);
		mlx_key_hook(data->mlx_win, &key_release, data);
		mlx_loop_hook(data->mlx_ptr, &render_frame, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
/* void	print_map(t_data *mlx)
{
	int	i = 0;
	int	j;
	close(mlx->map->fd_map);
	mlx->map->fd_map = open(".tmp_map", O_RDWR, 0644);
	if (mlx->map->fd_map == -1)
		error_mngmt(2, "Could not open file.\n", mlx);
	while (mlx->map->map[i] && i <= mlx->map->rows)
	{
		j = 0;
		while (mlx->map->map[i][j])
		{
			printf("%c", mlx->map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
} */