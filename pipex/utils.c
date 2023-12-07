/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:50 by hgandar           #+#    #+#             */
/*   Updated: 2023/12/07 09:41:10 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <string.h>
#include <stdio.h> 

char	*ft_strstr(const char *hstack, const char *needle)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (needle[i] == 0 || needle[j] == 0)
		return ((char *)hstack);
	if (hstack == NULL)
        return NULL;
	while (hstack[i])
	{
		j = 0;
		while (needle[j] && needle[j] == hstack[i + j])
			j++;
		if (needle[j] == 0)
			return ((char *)&hstack[i]);
		i++;
	}
	return (0);
}

void	free_all(char **all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all[i])
		i++;
	while (j < i)
	{
		free(all[j]);
		j++;
	}
	free(all);
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
	else if (flag == 5)
		perror("Error getting env path\n");
	else if (flag == 6)
		perror("Error getting execute");
	else if (flag == 7)
		perror("Error getting exec split");
	else if (flag == 8)
		perror("Error getting env PATH");
	else if (flag == 9)
		perror("Error getting PATH");
	exit(EXIT_FAILURE);
}
