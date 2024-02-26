/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:00 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/26 12:12:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdbool.h>

# define BPX 32
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125
# define CLOSE 17
# define GRASS "img/grass.xpm"
# define FENCE_1 "img/Big-wooden-fence-1.xpm"
# define FENCE_2 "img/Big-wooden-fence-2.xpm"
# define FENCE_3 "img/Big-wooden-fence-3.xpm"
# define FENCE_4 "img/Big-wooden-fence-4.xpm"
# define TREE "img/Tree.xpm"
# define CAT "img/new_cat.xpm"
# define DOOR "img/door.xpm"
# define CANDY "img/Chest.xpm"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}				t_img;

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
	int		move;
}				t_player;

typedef struct s_map
{
	int			fd;
	void		*mlx;
	void		*win;
	t_node		***nodes;
	t_node		*p_start;
	int			row;
	int			col;
	bool		escap;
	t_node		*exit;
	int			candy_nbr;
	t_player	*player;
	void		*door;
}				t_map;

void	error_mngmt(int i, t_map **game);
int		close_w(int keycode, t_map *game);
int		valid_map(char *str, t_map **game, int y);
int		is_playable(t_player *player, t_map **game, t_node *current_p);
int		valid_game(t_map **game);
void	*ft_realloc(void *to_resized, size_t new_size);
void	create_map(char *str, t_map **game);
int		parsing(char *str, t_map **game, int y);
void	control_data(int flag, t_map **game, int y, int x);
t_node	*add_node(int y, int x, int type);
void	create_grid(t_map **game);
void	link_adj(t_map **game, int y, int x);
void	free_grid(t_map **game);
void	draw_background(t_map **game, int x, int y);
void	draw_sprites(t_map **game, int x, int y);
void	draw_map(t_map **game);
t_node	*key_handler(int keycode, t_node *current_p);
int		check_key(int keycode, t_map **game);
int		explore_map(int keycode, t_map **game);
void	lets_play(t_map **game);
void	refresh_map(t_node *current, t_node *next, t_map **game);
void	the_end(t_map **game);
void	error_map(t_map **game);
int		on_destroy(t_map *game);
void	vizualizer(t_map **game);
int	check_limits(t_map **game);

#endif
