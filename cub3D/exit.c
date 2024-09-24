/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:09:26 by mremenar          #+#    #+#             */
/*   Updated: 2024/05/28 16:49:31 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* void	mlx_error1(char *msg, t_data *mlx)
{
	// DEBUG
	free(mlx);
	mlx = NULL;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit (1);
}

void	mlx_error2(int code, t_data *mlx, char *msg)
{
	// DEBUG
	free_mlx(mlx, code);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	mlx_error1(msg, mlx);
}

void	mlx_error3(int code, t_data *mlx, char *line, char *msg)
{
	// DEBUG
	free_mlx(mlx, code);
	free(line);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit (1);
}

int	close_mlx(t_data *mlx)
{
	// DEBUG
	//mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	error_mngmt(6, NULL, mlx);
	exit (0);
}

void	free_mlx(t_data *mlx, int code)
{
	// DEBUG
	int	i;

	if (code == 2 || code == 3)
	{
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
	if (code == 3 && mlx->mlx_win)
		free(mlx->mlx_win);
	if (code == 4)
		free(mlx->wall->img);
	i = -1;
	// if (code == 1 || code == 2)
	// {
		while (mlx->map->map[++i])
			free(mlx->map->map[i]);
		free(mlx->map->map[i]);
		free(mlx->map->map);
	// }
}
 */