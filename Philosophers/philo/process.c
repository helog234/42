/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/21 11:29:19 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	life_check(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->settings->dead_lock);
	pthread_mutex_lock(&philo->settings->meal_lock);
	if (philo->has_died == true || (set_curr_time() - philo->last_meal_time >= \
		philo->settings->time_to_die && philo->is_eating == false))
	{
		pthread_mutex_unlock(&philo->settings->dead_lock);
		pthread_mutex_unlock(&philo->settings->meal_lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->settings->dead_lock);
	pthread_mutex_unlock(&philo->settings->meal_lock);
	return (true);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	t_settings		*set;

	philo = (t_philosopher *)arg;
	set = philo->settings;
	if (philo->id % 2 == 0)
		my_usleep(1);
	while (life_check(philo) == true && !set->one_dead && !set->end)
	{
		get_forks(philo);
		eat(philo);
		free_forks(philo);
		rest(philo);
		think(philo);
	}
	return (philo);
}

void	create_threads(t_settings *settings)
{
	int				i;
	t_philosopher	**philo;
	int				j;

	i = 0;
	philo = settings->philo;
	j = settings->number_of_philosophers;
	while (i < j && !settings->one_dead && !settings->end)
	{
		if (pthread_create(&philo[i]->thread, NULL, &routine, philo[i]) != 0)
			error_msg(settings, 1);
		if (philo[i]->has_died == true || settings->one_dead || settings->end)
			break ;
		i++;
	}
}
