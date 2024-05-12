/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:22:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/12 09:43:35 by hgandar          ###   ########.fr       */
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
		print_msg(philo, " has taken a fork", philo->id);
		if (philo->fork_left != NULL)
		{
			pthread_mutex_lock(philo->fork_left);
			print_msg(philo, " has taken a fork", philo->id);
			philo->is_eating = true;
		}
	}
}

void	free_forks(t_philosopher *philo)
{
	if (philo->fork_left != NULL)
		pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	t_settings		**set;

	philo = (t_philosopher *)arg;
	set = philo->settings;
	if (philo->id % 2 == 0)
		my_usleep(1);
	while (life_check(philo) == true && !(*set)->one_dead && !(*set)->end)
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

	i = 0;
	philo = settings->philo;
	j = settings->number_of_philosophers;
	while (i < j && !settings->one_dead && !settings->end)
	{
		if (pthread_create(&philo[i]->thread, NULL, &routine, philo[i]) != 0)
			error_msg(&settings, 1);
		if (philo[i]->has_died == true || settings->one_dead || settings->end)
			break ;
		i++;
	}
}
