/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:24 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/01 13:40:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= 9)
		return (true);
	return (false);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	parsing(int argc, char **argv, t_settings **to_set, int i)
{
	int	n;

	n = 0;
	if (i >= argc)
		return ;
	if (argv[i])
		n = ft_atoi(argv[i]);
	if (n <= 0 && i < 5)
		return ;
	//faire un message d'erreur
	if (i == 1)
		(*to_set)->number_of_philosophers = n;
	else if (i == 2)
		(*to_set)->time_to_die = n;
	else if (i == 3)
		(*to_set)->time_to_eat = n;
	else if (i == 4)
		(*to_set)->time_to_sleep = n;
	else if (i == 5)
		(*to_set)->number_of_times_each_philosopher_must_eat = n;
	i++;
	parsing(argc, argv, to_set, i);
}
