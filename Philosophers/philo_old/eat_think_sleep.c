/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_think_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:10 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/06 15:44:15 by hgandar          ###   ########.fr       */
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
	if (philo->id < philo->nbr_philo - 1)
	{
		printf("retour %i\n", pthread_mutex_lock(philo->fork_right));
		if (pthread_mutex_lock(philo->fork_right) != 0)
			return ;
		print_msg(philo, " has taken a fork", philo->id);
		if (pthread_mutex_lock(philo->fork_left) != 0)
		{
			pthread_mutex_unlock(philo->fork_right);
			return ;
		}
		print_msg(philo, " has taken a fork", philo->id);
		// pthread_mutex_lock(philo->fork_right);
		// print_msg(philo, " has taken a fork", philo->id);
		// pthread_mutex_lock(philo->fork_left);
		// print_msg(philo, " has taken a fork", philo->id);
	}
	else
	{
		if (pthread_mutex_lock(philo->fork_left) != 0)
			return ;
		print_msg(philo, " has taken a fork", philo->id);
		if (pthread_mutex_lock(philo->fork_right) != 0)
		{
			pthread_mutex_unlock(philo->fork_left);
			return ;
		}
		print_msg(philo, " has taken a fork", philo->id);
		// pthread_mutex_lock(philo->fork_left);
		// print_msg(philo, " has taken a fork", philo->id);
		// pthread_mutex_lock(philo->fork_right);
		// print_msg(philo, " has taken a fork", philo->id);
	}
	/* pthread_mutex_lock(philo->fork_right);
	print_msg(philo, " has taken a fork", philo->id);
	pthread_mutex_lock(philo->fork_left);
	print_msg(philo, " has taken a fork", philo->id); */
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = set_curr_time();
	print_msg(philo, "\033[32m is eating\033[0m", philo->id);
	philo->is_eating = true;
	my_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->meal_lock);
	philo->nbr_eaten_meal++;
	philo->is_eating = false;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}
