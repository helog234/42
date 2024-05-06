/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/03 17:54:05 by hgandar          ###   ########.fr       */
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
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (life_check(philo) == true)
	{
		eat(philo);
		rest(philo);
		think(philo);
	}
	return (NULL);
}

void	create_threads(t_settings *settings)
{
	int				i;
	t_philosopher	**philo;
	pthread_t		ctr;
	int				j;

	i = 0;
	philo = settings->philo;
	j = settings->number_of_philosophers;
	if (pthread_create(&ctr, NULL, \
	&ctr_loops, settings) != 0)
		error_msg(&settings, 1);
	while (i < j && !settings->one_dead)
	{
		if (pthread_create(philo[i]->thread, NULL, &routine, philo[i]) != 0)
			error_msg(&settings, 1);
		i++;
	}
	i = 0;
	if (pthread_join(ctr, NULL) != 0)
		error_msg(&settings, 2);
	while (philo[i])
	{
		if (pthread_join(*philo[i]->thread, NULL) != 0)
			error_msg(&settings, 2);
		i++;
	}
}
