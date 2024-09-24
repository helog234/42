/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:01:32 by mremenar          #+#    #+#             */
/*   Updated: 2024/06/04 14:06:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "libft/printf/ft_printf.h"
# include "libft/gnl/get_next_line_bonus.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define HALF_SCREEN_H 384
# define MINI 10
# define MINI_HEIGHT 150
# define MINI_PXL 128

# define ON_DESTROY 17
# define KEY_PRESS 2
# define ESC 53
# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define TURN_LEFT 123
# define TURN_RIGHT 124

# define GRID_X 0
# define GRID_Y 1
# define WALL_NOT_HIT 0
# define WALL_HIT 1

typedef struct s_texture
{
	int		*north;
	int		no_w;
	int		no_h;
	int		*south;
	int		so_w;
	int		so_h;
	int		*east;
	int		ea_w;
	int		ea_h;
	int		*west;
	int		we_w;
	int		we_h;
	int		ceiling;
	int		floor;
	int		line_half_height;
	int		start;
	int		end;
	float	wall_x;
	int		tex_x;
	int		tex_y;
	int		tex_width;
	int		tex_height;
	float	tex_pos;
	float	tex_step;
	void	*img;
	int		*data;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_pos
{
	float	p_x;
	float	p_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	cam;
}	t_pos;

typedef struct s_mini
{
	void	*img_mini;
	char	*img_pxl_ptr;
	int		*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		scale_y;
	int		scale_x;
	int		color;
}	t_mini;

typedef struct s_ray
{
	int		ray_px;
	float	rdir_x;
	float	rdir_y;
	float	dist_to_x;
	float	dist_to_y;
	float	dist_btw_x;
	float	dist_btw_y;
	float	cam_pln_dist;
}	t_ray;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		grid;
	int		wall_hit;
}	t_dda;

typedef struct s_map
{
	int				fd_origin;
	int				fd_map;
	int				rows;
	int				cols;
	bool			ctr;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	int				floor_rgb;
	int				ceiling_rgb;
	char			**map;
	int				*pos;
	char			dir;
}				t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map		*map;
	int			dir_up_down;
	int			dir_left_right;
	int			dir_roatate;
	t_pos		*pos;
	t_ray		*ray;
	t_dda		*dda;
	t_texture	*wall;
	t_mini		*mini;
}				t_data;


// map_checker.c
int		map_format(char *str);
int		valid_file_and_init_map(char *str, t_map **map, t_data *mlx);
int		valid_map(t_map *map, t_data *mlx);
int		init_structs(t_map *map, t_data *mlx);
int		map_checker_and_init(int argc, char *argv[], t_data *mlx);

// valid_and_init.c
void	init_map(t_data *mlx, t_map **map, char *str);
void	set_player_position(int y, int x, t_map *map);
int		look_for_valid_settings_data(t_map *map, char *line);
int		check_for_limits_and_valid_data(t_map *map, int ctr);
int		get_map_into_int_array(t_map *map, int *i, char *line);

// get_data_from_file.c
int		get_texture_paths_from_file(char *line, t_map *map);
int		get_colors_from_file(char *line, t_map *map);
int		get_map_from_fd_o_to_fd_map(char *line, t_map *map);

// parsing_utils.c
int		atoi_loop_for_rgb(char **split, int *rgb);
void	malloc_row(t_map *map, char *line, int i);
void	set_direction_n_s(t_map *map, t_data *mlx);
void	set_direction_e_w(t_map *map, t_data *mlx);

// valid_map.c
int		check_valid_data(int i, int j, char c, t_map *map);
void	get_len_col_above_and_below(int *col_above, \
		int *col_below, int i, t_map *map);
int		is_border(int i, int j, t_map *map);
int		check_inner_cell(int i, int j, int col, t_map *map);
int		valid_data_array(int i, int j, int col, t_map *map);

// init_structs.c
int		*load_img(t_data *mlx, char *path, int *width, int *height);
void	init_pos(t_map *map, t_data *mlx);
void	init_dda(t_data *mlx);
void	init_wall(t_map *map, t_data *mlx);
void	from_map_to_pxl(t_map *map, t_data *mlx);

// init_structs_2.c
void	init_mini(t_data *data);
void	init_img(t_data *data);

// free_data.c
void	free_array(char **str);
void	free_texture(t_data *mlx);
void	free_map_data(t_data *mlx);
void	free_structs(t_data *mlx);
void	free_mlx(t_data *mlx);
void	free_mlx_img(t_data *data);
void	free_mlx_map(t_data *data);
void	free_imgs_loads(t_data *data);
void	free_window(t_data *data);
void	free_mini_img(t_data *data);

// errors_and_msg.c
void	error_mngmt(int flag, char *str, t_data *mlx);

// main_m.c
int		key_press(int keycode, t_data *mlx);
int		key_release(int keycode, t_data *mlx);
void	init_mlx(t_data *mlx);

// ctr_mlx.c
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		close_mlx(t_data *mlx);

// plac.c
int		render_frame(t_data *data);
int		play(t_data *data);
void	cast_ray(t_pos *p, t_ray *r);
void	set_step(t_pos *p, t_ray *r, t_dda *dda);
void	perform_dda(t_ray *r, t_dda *dda, t_data *data);

// move.c
void	move(t_data *data);
void	change_pos(t_data *mlx, float step_x, float step_y, float speed);
void	rotate(t_data *mlx, float old_dir_x, float old_plane_x, float angle);

// draw.c
void	draw(t_data *data);
void	texture(t_data *data);
void	set_texture(t_data *data);
void	draw_wall(t_data *data);

// minimap.c
void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color);
int		set_color(t_data *data, int y, int x);
void	draw_tile_pxl(t_data *data, int y, int x, t_mini *mini);
void	rescale_and_set(t_data *data, int y, int x);
int		draw_minimap(t_data *mlx);

// exit.c
void	mlx_error1(char *msg, t_data *data);
void	mlx_error2(int code, t_data *mlx, char *msg);
void	mlx_error3(int code, t_data *mlx, char *line, char *msg);
int		close_mlx(t_data *mlx);
//void	free_mlx(t_data *mlx, int code);

#endif