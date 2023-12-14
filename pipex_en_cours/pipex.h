/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:34:46 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/13 10:13:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strstr(const char *hstack, const char *needle);
void	free_all(char **all);
void	error_message(int flag);
char	**get_env_path(char *envp[]);
char	*get_path(char *cmd, char *env_paths[]);
void	output_sterr(int i, char *cmd);
char	**check_quote(char *cmd);

#endif