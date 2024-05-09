/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/07 21:33:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philosopher *philo)
{
	size_t	time;
	print_msg(philo, "\033[33m is thinking\033[0m", philo->id);
	//my_usleep(5);
	/* printf("time_die %lu - curr %lu - last meal %lu - 20 = %lu\n", \
	philo->time_to_die, \
	set_curr_time() - philo->time_start, \
	philo->last_meal_time - philo->time_start, \
	philo->time_to_die - (set_curr_time() - philo->last_meal_time) - 20); */
	time = philo->time_to_die / 3;
	my_usleep(time);
}

void	rest(t_philosopher *philo)
{
	print_msg(philo, "\033[34m is sleeping\033[0m", philo->id);
	my_usleep(philo->time_to_sleep);
}

void	eat(t_philosopher *philo)
{
	if (philo->has_died == false)
	{
		/* pthread_mutex_lock(philo->fork_right);
		print_msg(philo, " has taken a fork", philo->id);
		pthread_mutex_lock(philo->fork_left);
		print_msg(philo, " has taken a fork", philo->id); */
		print_msg(philo, "\033[32m is eating\033[0m", philo->id);
		pthread_mutex_lock(philo->meal_lock);
		philo->nbr_eaten_meal++;
		philo->last_meal_time = set_curr_time();
		pthread_mutex_unlock(philo->meal_lock);
		my_usleep(philo->time_to_eat);
		//printf("philo[%i] eaten %i\n", philo->id, philo->nbr_eaten_meal);
		philo->is_eating = false;
		/* philo->can_eat = false;
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left); */
	}
}
