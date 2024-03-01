/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:46:04 by hgandar           #+#    #+#             */
/*   Updated: 2024/03/01 17:18:43 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>

typedef struct	s_word
{
	char	*data;
}				t_word;

typedef struct s_file
{
	int		fd;
	char	*name;
}				t_file;

typedef struct s_redir
{
	int	fd_in;
	int	fd_out;
}				t_redir;

typedef struct s_arg
{
	char	*data;
	int		index;
	s_arg	*prev;
	s_arg	*next;
}				t_arg;

typedef struct s_cmd
{
	int		fd;
	char	*data;
	t_arg	*first_arg;
}				t_cmd;

typedef struct s_token
{
	void	*type;
	int		index;
	s_token	*prev;
	s_token	*next;
}				t_token;


#endif
