/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/01 17:53:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	life_check(t_philosopher *philo)
{
	if (philo->has_died == true)
		return (false);
	return (true);
}

void	*routine(void *arg)
{
	t_settings		*settings;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (life_check(philo) == true)
	{
		eat(philo);
		sleep(philo);
		think(philo);
	}
}

int	creat_threads(t_settings **settings)
{
	int				i;
	t_philosopher	**philo;
	pthread_t		ctr;

	i = 0;
	philo = (*settings)->philo;
	if (pthread_create(&ctr, NULL, \
		&routine, philo[i]->thread) != 0)
	while (philo[i])
	{
		if (pthread_create(philo[i]->thread, NULL, \
		&routine, philo[i]->thread) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (philo[i])
	{
		if (pthread_join(philo[i]->thread, NULL) != 0)
			return (1);
		i++;
	}
}

void	start_process(t_settings **settings)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return ;
	
}

