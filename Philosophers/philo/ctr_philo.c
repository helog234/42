/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctr_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:03 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/01 18:06:33 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_for_deads(t_settings **settings)
{
	t_philosopher	**philo;
	int				i;

	philo = (*settings)->philo;
	i = 0;
	while (i <= (*settings)->number_of_philosophers)
	{
		pthread_mutex_lock(philo[i]->dead_lock);
		if (philo[i]->last_meal_time >= (*settings)->time_to_eat && \
		philo[i]->is_eating == false)
		{
			philo[i]->has_died = true;
			printf("%i %i died\n", \
			set_curr_time - (*settings)->time_start, philo[i]->id);
			pthread_mutex_lock(philo[i]->dead_lock);
			return (1);
		}
		pthread_mutex_unlock(philo[i]->dead_lock);
		i++;
	}
	return (0);
}

void	ctr_loops(t_settings *settings)
{
	//appeller check_for deads ici
}
