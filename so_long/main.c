/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:18:42 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/14 20:26:52 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
} */

int	close_w(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
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
	int		esc_key;
	//t_img	vars;
	//void	*img;

	esc_key = 53;
	game = NULL;
	//ajouter NULL à img dans nodes
	if (map_checker(argc, argv, &game) == 1)
	{
		printf("Bien joué !\n");
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->col * WIN_H, game->row * WIN_W, "So Long");
		draw_map(&game);
		//img = mlx_new_image(vars.mlx, 10, 10);
		//img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
		//if (img == NULL)
			//printf("bon\n");
		//mlx_put_image_to_window(vars.mlx, vars.win, img, 20, 20);
		printf("Bravo!\n");
	}
	else
		printf("Cool !\n");
	mlx_hook(game->win, 3, esc_key, close_w, &game);
	mlx_loop(game->mlx);
}

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
