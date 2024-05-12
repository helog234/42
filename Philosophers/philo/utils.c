/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:44:14 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/10 15:23:33 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		if (*str1 == 0)
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

int	my_usleep(size_t mscd)
{
	size_t	start;

	start = set_curr_time();
	while (set_curr_time() - start < mscd)
		usleep(500);
	return (0);
}

size_t	set_curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		printf("Error in gettimeofday\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
