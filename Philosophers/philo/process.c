/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/06 18:21:29 by hgandar          ###   ########.fr       */
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

	eat(philo);
	rest(philo);
	think(philo);
	return (NULL);
}

void	create_threads(t_settings *settings)
{
	int				i;
	t_philosopher	**philo;
	int				j;
	pthread_t		monitor;

	i = 0;
	philo = settings->philo;
	j = settings->number_of_philosophers;
	if (pthread_create(&monitor, NULL, \
	&garcon, settings) != 0)
		error_msg(&settings, 1);
	while (i < j)
	{
		while (i < j)
		{
			if (pthread_create(philo[i]->thread, NULL, &routine, philo[i]) != 0)
				error_msg(&settings, 1);
			i += 2;
		}
		if (i % 2 == 0)
		{
			usleep(settings->time_to_eat / 2);
			i = 1;
		}
	}
	if (j % 2 != 0)
	{
		if (pthread_create(philo[j - 1]->thread, NULL, &routine, philo[j - 1]) != 0)
				error_msg(&settings, 1);
	}
	if (pthread_join(monitor, NULL) != 0)
		error_msg(&settings, 2);
	i = 0;
	while (philo[i])
	{
		if (pthread_join(*philo[i]->thread, NULL) != 0)
			error_msg(&settings, 2);
		i++;
	}
}
