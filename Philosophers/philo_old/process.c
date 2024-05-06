/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/06 15:12:47 by hgandar          ###   ########.fr       */
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

int	create_threads(t_settings *settings)
{
	int				i;
	t_philosopher	**philo;
	// pthread_t		ctr;
	int				j;

	i = 0;
	philo = settings->philo;
	j = settings->number_of_philosophers;
	// if (pthread_create(&ctr, NULL, \
	// &ctr_loops, settings) != 0)
	// 	error_msg(&settings, 1);
	while (i < j && !settings->one_dead)
	{
		if (pthread_create(philo[i]->thread, NULL, &routine, philo[i]) != 0)
			error_msg(&settings, 1);
		// if (j % 2 == 0)
		// {
		// 	while (i < j)
		// 	{
		// 		printf("philo[%i] last meal %lu - curr time %lu = %lu and time to die %lu\n", \
		// 		i, \
		// 		philo[i]->last_meal_time - philo[i]->time_start, \
		// 		set_curr_time() - philo[i]->time_start, \
		// 		set_curr_time() - philo[i]->last_meal_time, \
		// 		settings->time_to_die);
		// 		if (pthread_create(philo[i]->thread, NULL, &routine, philo[i]) != 0)
		// 			error_msg(&settings, 1);
		if (philo[i]->has_died == true)
			settings->one_dead = true;
		// 		i += 2;
		// 	}
		// 	if (i % 2 == 0)
		// 		i = 0;	
		// }
		i++;
	}
	i = 0;
	if (settings->one_dead == true)
		return (1);
	// if (pthread_join(ctr, NULL) != 0)
	// 	error_msg(&settings, 2);
	while (philo[i])
	{
		if (pthread_join(*philo[i]->thread, NULL) != 0)
			error_msg(&settings, 2);
		i++;
	}
	return (0);
}
