/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/06 18:13:38 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philosopher *philo)
{
	print_msg(philo, "\033[33m is thinking\033[0m", philo->id);
	//my_usleep(philo->last_meal_time + philo->time_to_die / 2);
}

void	rest(t_philosopher *philo)
{
	print_msg(philo, "\033[34m is sleeping\033[0m", philo->id);
	my_usleep(philo->time_to_sleep);
}

void	eat(t_philosopher *philo)
{
	if (philo->can_eat && philo->has_died == false)
	{
		pthread_mutex_lock(philo->fork_right);
		print_msg(philo, " has taken a fork", philo->id);
		pthread_mutex_lock(philo->fork_left);
		print_msg(philo, " has taken a fork", philo->id);
		pthread_mutex_lock(philo->meal_lock);
		philo->last_meal_time = set_curr_time();
		print_msg(philo, "\033[32m is eating\033[0m", philo->id);
		philo->is_eating = true;
		my_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->meal_lock);
		philo->nbr_eaten_meal++;
		philo->is_eating = false;
		philo->can_eat = false;
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
	}
}
