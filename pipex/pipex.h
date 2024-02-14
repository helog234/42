/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:34:46 by hgandar           #+#    #+#             */
/*   Updated: 2024/01/10 08:56:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_fd {
	int	out_file;
	int	tmp;
	int	pipe[2];
	int	pid;
	int	start;
}	t_fd;

char	*ft_strstr(const char *hstack, const char *needle);
void	free_all(char **all);
void	error_message(int flag);
char	**get_env_path(char *envp[]);
char	*get_path(char *cmd, char *env_paths[]);
void	output_sterr(int i, char *cmd);
char	**check_quote(char *cmd);
void	here_doc_process(int argc, char **argv, t_fd *fd);
void	gnl_argv(char *argv[], int output);
void	output_sterr(int i, char *cmd);
void	error_message(int flag);
int		wait_last(int last_pid);

#endif
