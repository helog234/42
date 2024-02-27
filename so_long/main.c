/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:18:42 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/27 13:23:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_grid(&game);
	ft_printf("Bye !\n");
	exit(0);
	return (0);
}

int	close_w(int keycode, t_map *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_grid(&game);
		ft_printf("Bye !\n");
		exit(0);
	}
	return (0);
}

int	map_test(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (0);
	while (str[i])
		i++;
	if (str[i - 4] != '.')
		return (0);
	if (str[i - 3] != 'b')
		return (0);
	if (str[i - 2] != 'e')
		return (0);
	if (str[i - 1] != 'r')
		return (0);
	return (1);
}

int	map_checker(int argc, char *argv[], t_map **game)
{
	if (argc != 2)
		error_mngmt(0, game);
	if (map_test(argv[1]) != 1)
		error_mngmt(0, game);
	if (valid_map(argv[1], game, 0) != 1)
		error_mngmt(1, game);
	if (check_limits(game) != 1)
		error_mngmt(3, game);
	if (valid_game(game) != 1)
		error_mngmt(4, game);
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
		game->player->move = 0;
		draw_map(&game);
		mlx_hook(game->win, 2, 1L << 0, explore_map, &game);
		mlx_loop(game->mlx);
	}
	return (0);
}
