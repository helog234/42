/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/10 16:02:35 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philosopher *philo)
{
	print_msg(philo, "\033[33m is thinking\033[0m", philo->id);
}

void	rest(t_philosopher *philo)
{
	print_msg(philo, "\033[34m is sleeping\033[0m", philo->id);
	my_usleep(philo->time_to_sleep);
}

void	eat(t_philosopher *philo)
{
	if (philo->has_died == false && philo->fork_left != NULL)
	{
		print_msg(philo, "\033[32m is eating\033[0m", philo->id);
		pthread_mutex_lock(philo->meal_lock);
		philo->nbr_eaten_meal++;
		philo->last_meal_time = set_curr_time();
		pthread_mutex_unlock(philo->meal_lock);
		my_usleep(philo->time_to_eat);
		philo->is_eating = false;
	}
}
