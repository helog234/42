/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:09:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/12 09:47:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_for_deads(t_settings *settings)
{
	t_philosopher	**philo;
	int				i;

	philo = settings->philo;
	i = 0;
	while (philo && i < settings->number_of_philosophers \
	&& !settings->one_dead && !settings->end)
	{
		pthread_mutex_lock(philo[i]->dead_lock);
		if (set_curr_time() - philo[i]->last_meal_time >= \
		settings->time_to_die && \
		philo[i]->is_eating == false)
		{
			philo[i]->has_died = true;
			print_msg(*settings->philo, "\033[31m died\033[0m", philo[i]->id);
			settings->one_dead = true;
			pthread_mutex_unlock(philo[i]->dead_lock);
			return (1);
		}
		pthread_mutex_unlock(philo[i]->dead_lock);
		i++;
	}
	return (0);
}

int	ctr_limit_meal(t_settings **settings)
{
	t_philosopher	**philo;
	int				i;
	int				ctr;

	philo = (*settings)->philo;
	i = 0;
	ctr = 0;
	if ((*settings)->number_of_times_each_philosopher_must_eat == 0)
		return (0);
	while (i < (*settings)->number_of_philosophers)
	{
		if (philo[i]->nbr_eaten_meal >= 7)
			sleep(1);
		pthread_mutex_lock(philo[i]->meal_lock);
		if (philo[i]->nbr_eaten_meal >= \
		(*settings)->number_of_times_each_philosopher_must_eat)
			ctr++;
		pthread_mutex_unlock(philo[i]->meal_lock);
		i++;
	}
	if (ctr == (*settings)->number_of_philosophers)
		return ((*settings)->end = true, 1);
	return (0);
}

void	end_dinner(t_settings **set, t_philosopher **philo)
{
	if (!set && !philo)
		return ;
	free_all(set, philo);
}
