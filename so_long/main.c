/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:18:42 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/19 09:29:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_grid(&game);
	free(game);
	exit(1);
	return (0);
}

int	close_w(int keycode, t_map *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_grid(&game);
		free(game);
		exit(1);
	}
	return (0);
}

int	map_checker(int argc, char *argv[], t_map **game)
{
	if (argc == 1)
		error_mngmt(0, game);
	if (valid_map(argv[1], game, 0) != 1)
		error_mngmt(1, game);
	if (check_limits(game) != 1)
		error_mngmt(3, game);
	if (valid_game(game) != 1)
	{
		//trouver solution pour free grid car segfault
		free_grid(game);
		error_mngmt(4, game);
	}
	return (1);
}

int	main(int argc, char*argv[])
{
	t_map	*game;

	game = NULL;
	if (map_checker(argc, argv, &game) == 1)
	{
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->col * BPX, \
		game->row * BPX, "So Long");
		mlx_hook(game->win, 17, 0L, on_destroy, game);
		game->player->candy_col = 0;
		draw_map(&game);
		mlx_hook(game->win, 2, 1L << 0, explore_map, &game);
		if (game->player->position == game->exit && \
		game->player->candy_col <= game->candy_nbr)
			printf("Bravo!\n");
		mlx_loop(game->mlx);
	}
	else
		printf("Cool !\n");

}

