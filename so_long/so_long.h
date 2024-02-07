/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:00 by hgandar           #+#    #+#             */
/*   Updated: 2024/02/07 17:38:58 by hgandar          ###   ########.fr       */
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


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
}				t_node;

typedef struct s_map
{
	int				fd;
	char			**full_map;
	struct t_node	**nodes;
	struct t_node	*p_start;
	int				row;
	int				col;
	struct t_node	*exit;
	struct t_node	**candy[4];
	int				candy_nbr;
}			t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

static void	error_mngmt(int i);

#endif
