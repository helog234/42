/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:00 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/15 16:54:59 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* # include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h> */
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
#include <stdbool.h>

# define BPX 32
# define WIN_W 50
# define WIN_H 40
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125

typedef struct	s_img 
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*path;
	int		img_width;
	int		img_height;
}				t_img;

/* typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}				t_img; */

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*adj[4];
	int				adj_nbr;
	int				type;
	void			*img_bg;
	void			*img_asset;
	bool			visited;
}				t_node;

typedef struct s_player
{
	t_node	*position;
	int		candy_col;
}				t_player;

typedef struct s_map
{
	int		fd;
	void	*mlx;
	void	*win;
	t_node	***nodes;
	t_node	*p_start;
	int		row;
	int		col;
	t_node	*exit;
	int		candy_nbr;
	t_player	*player;
	//t_img	*map;
}			t_map;


typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;



void	error_mngmt(int i);
int	close_w(int keycode, t_map *game);
int	valid_map(char *str, t_map **game);
int	is_playable(t_player *player, t_map **game, t_node *current_p);
int	valid_game(t_map **game);
//int *init_checker(int flag);
void	*ft_realloc(void *to_resized, size_t new_size);
void	create_map(char *str, t_map **game);
int		parsing(char *str, t_map **game, int y);
void	control_data(int flag, t_map **game, int y, int x);
t_node	*add_node(int y, int x, int type);
void	create_grid(t_map **game);
void	link_adj(t_map **game, int y, int x);
void	free_grid(t_map **game);
void	draw_background(t_map **game);
void	draw_sprites(t_map **game);
void	draw_map(t_map **game);
t_node *key_handler(int keycode, t_node *current_p);
int	check_key(int keycode, t_map **game);
int	explore_map(int keycode, t_map **game);
void	lets_play(t_map **game);
void	refresh_map(t_node *next, t_map **game);

#endif
