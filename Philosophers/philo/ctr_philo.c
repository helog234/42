/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctr_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:03 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/03 17:54:36 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_for_deads(t_settings **settings)
{
	t_philosopher	**philo;
	int				i;

	philo = (*settings)->philo;
	i = 0;
	while (i < (*settings)->number_of_philosophers)
	{
		pthread_mutex_lock(philo[i]->dead_lock);
		printf("philo[%i] last meal %lu - curr time %lu = %lu and time to die %lu\n", \
		i, philo[i]->last_meal_time, set_curr_time(), \
		set_curr_time() - philo[i]->last_meal_time, (*settings)->time_to_die);
		if (set_curr_time() - philo[i]->last_meal_time >= (*settings)->time_to_die && \
		philo[i]->is_eating == false)
		{
			philo[i]->has_died = true;
			print_msg(*(*settings)->philo, "\033[31m died\033[0m", philo[i]->id);
			(*settings)->one_dead = true;
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
	while (i < (*settings)->number_of_philosophers)
	{
		pthread_mutex_lock(philo[i]->meal_lock);
		if (philo[i]->nbr_eaten_meal == \
		(*settings)->number_of_times_each_philosopher_must_eat)
			ctr++;
		pthread_mutex_unlock(philo[i]->meal_lock);
	}
	if (ctr == (*settings)->number_of_times_each_philosopher_must_eat)
		return (1);
	return (0);
}

void	*ctr_loops(void *arg)
{
	t_settings		*settings;

	settings = (t_settings *)arg;
	while (1)
	{
		printf("la\n");
		if (check_for_deads(&settings) == 1 || ctr_limit_meal(&settings) == 1)
		{
			printf("ici\n");
			break ;
			/* free_all(&settings, settings->philo);
			return (NULL); */
		}
	}
	return (arg);
}
