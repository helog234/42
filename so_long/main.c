/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:18:42 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/05 15:02:18 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* int	close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
} */

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
	mlx = NULL;
	vars.mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
/* 	while (x <= 40 && y <= 40)
	{
		if (x - y == r)
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		y++;
	}
	y = 40; */
	/* while (x > 10)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x--;
	} */
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
