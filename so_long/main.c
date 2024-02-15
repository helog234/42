/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:18:42 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/15 17:38:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
} */

int	close_w(int keycode, t_map *game)
{
	// printf("%i\n", keycode);
	if (keycode == KEY_ESC || keycode == 1L << 5)
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
		error_mngmt(0);
	if (valid_map(argv[1], game) != 1)
		error_mngmt(0);
	if (valid_game(game) != 1)
	{
		//trouver solution pour free grid car segfault
		free_grid(game);
		error_mngmt(0);
	}
	//ajouter une fonction pour réinitiliser les visited
	return (1);
}

int	main(int argc, char*argv[])
{
	t_map	*game;

	game = NULL;
	//ajouter NULL à img dans nodes
	if (map_checker(argc, argv, &game) == 1)
	{
		printf("Bien joué !\n");
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->col * WIN_W, game->row * WIN_H, "So Long");
		draw_map(&game);
		//lets_play(&game);
		mlx_hook(game->win, 2, 1L << 0, explore_map, &game);
		if (game->player->position == game->exit && \
		game->player->candy_col <= game->candy_nbr)
			printf("Bravo!\n");
		mlx_loop(game->mlx);
	}
	else
		printf("Cool !\n");
	// mlx_hook(game->win, 2, 1L << 0, close_w, &game);
	// mlx_hook(game->win, 2, KEY_ESC, close_w, &game);
	//mlx_loop(game->mlx);
}

/* int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close_w, &vars);
	mlx_loop(vars.mlx);
} */

/* 
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	t_data	img;
	t_vars	vars;

	x = 10;
	y = 10;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	while (x <= 40 && y <= 40)
	{
		if (x - y == r)
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		y++;
	}
	y = 40;
	while (x > 10)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x--;
	} 
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}*/
