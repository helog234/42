/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:02:11 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/14 10:25:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <string.h>
#include <stdio.h> 
#include <errno.h>

void	output_sterr(int i, char *cmd)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(i);
}

void	error_message(int flag)
{
	if (flag == 1)
		perror("Not enough arguments\n");
	else if (flag == 2)
		perror("Could not create pipe\n");
	else if (flag == 3)
		perror("Could not fork\n");
	else if (flag == 4)
		perror("Error splitting the command\n");
	else if (flag == 5 || flag == 8)
		perror("Error getting env path\n");
	else if (flag == 6)
		perror("Error getting execute");
	else if (flag == 7)
		perror("Error getting exec split");
	exit(EXIT_FAILURE);
}
