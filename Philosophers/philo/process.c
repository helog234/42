/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/07 17:39:33 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	life_check(t_philosopher *philo)
{
	if (philo->has_died == true)
		return (false);
	return (true);
}

void	get_forks(t_philosopher *philo)
{
	if (philo->has_died == false)
	{
		pthread_mutex_lock(philo->fork_right);
		print_msg(philo, " has taken a fork right", philo->id);
		pthread_mutex_lock(philo->fork_left);
		print_msg(philo, " has taken a fork left", philo->id);
		philo->is_eating = true;
	}
}

void	free_forks(t_philosopher *philo)
{
	//philo->can_eat = false;
	pthread_mutex_unlock(philo->fork_left);
	print_msg(philo, " has free a fork left", philo->id);
	pthread_mutex_unlock(philo->fork_right);
	print_msg(philo, " has free a fork right", philo->id);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	t_settings		**set;

	philo = (t_philosopher *)arg;
	set = philo->settings;
	if (philo->id % 2 == 0)
		my_usleep(1);	
	while (life_check(philo) == true && !(*set)->one_dead)
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
	pthread_t		monitor;

	i = 0;
	philo = settings->philo;
	j = settings->number_of_philosophers;
	if (pthread_create(&monitor, NULL, &garcon, settings) != 0)
		error_msg(&settings, 1);
	while (i < j && !settings->one_dead)
	{
		if (pthread_create(&philo[i]->thread, NULL, &routine, philo[i]) != 0)
			error_msg(&settings, 1);
		if (philo[i]->has_died == true)
			break;
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		error_msg(&settings, 2);
	while (philo[i])
	{
		if (pthread_join(philo[i]->thread, NULL) != 0)
			error_msg(&settings, 2);
		i++;
	}
}
