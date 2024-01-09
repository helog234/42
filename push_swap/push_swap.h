/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:23:27 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/09 09:48:28 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	long			value;
	int				index;
	bool			above_median;
	bool			cheapest;
	//bool			negativ;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

t_node	init_stack(long *values, t_node **a);

#endif
