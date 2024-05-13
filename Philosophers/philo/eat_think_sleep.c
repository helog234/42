/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/13 13:51:40 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philosopher *philo)
{
	if (life_check(philo) == true)
		print_msg(philo, "\033[33m is thinking\033[0m", philo->id);
}

void	rest(t_philosopher *philo)
{
	if (life_check(philo) == true)
	{
		print_msg(philo, "\033[34m is sleeping\033[0m", philo->id);
		my_usleep(philo->settings->time_to_sleep);
	}
}

void	get_forks(t_philosopher *philo)
{
	if (life_check(philo) == true)
	{
		pthread_mutex_lock(philo->fork_right);
		print_msg(philo, " has taken a fork", philo->id);
		if (philo->fork_left != NULL)
		{
			pthread_mutex_lock(philo->fork_left);
			print_msg(philo, " has taken a fork", philo->id);
			pthread_mutex_lock(philo->meal_lock);
			philo->is_eating = true;
			pthread_mutex_unlock(philo->meal_lock);
		}
	}
}

void	free_forks(t_philosopher *philo)
{
	if (philo->fork_left != NULL)
		pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	eat(t_philosopher *philo)
{
	if (life_check(philo) == true && philo->fork_left != NULL)
	{
		print_msg(philo, "\033[32m is eating\033[0m", philo->id);
		philo->nbr_eaten_meal++;
		philo->last_meal_time = set_curr_time();
		my_usleep(philo->settings->time_to_eat);
		pthread_mutex_lock(philo->meal_lock);
		philo->is_eating = false;
		pthread_mutex_unlock(philo->meal_lock);
	}
}
