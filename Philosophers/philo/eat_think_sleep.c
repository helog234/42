/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/01 17:47:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philosopher *philo)
{
	printf("%i %i is thinking\n", \
	set_curr_time - philo->time_start, philo->id);
}

void	sleep(t_philosopher *philo)
{
	printf("%i %i is sleeping\n", \
	set_curr_time - philo->time_start, philo->id);
	my_usleep(philo->time_to_sleep);
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_right);
	printf("%i %i has taken a fork\n", \
	set_curr_time - philo->time_start, philo->id);
	pthread_mutex_lock(philo->fork_left);
	printf("%i %i has taken a fork\n", \
	set_curr_time - philo->time_start, philo->id);
	printf("%i %i is eating\n", \
	set_curr_time - philo->time_start, philo->id);
	philo->is_eating = true;
	my_usleep(philo->time_to_eat);
	philo->last_meal_time = set_curr_time();
	philo->nbr_eaten_meal++;
	philo->is_eating = false;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}
