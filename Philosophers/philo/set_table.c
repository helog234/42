/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:34:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/03 16:29:01 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*add_philosopher(t_settings **settings, \
int i, pthread_mutex_t *fork)
{
	t_philosopher	*new;
	pthread_t		*new_t;

	new = malloc(sizeof(t_philosopher));
	new_t = malloc(sizeof(pthread_t));
	if (!new || !new_t)
		return (NULL);
	new->id = i;
	new->nbr_eaten_meal = 0;
	new->time_to_die = (*settings)->time_to_die;
	new->time_to_eat = (*settings)->time_to_eat;
	new->time_to_sleep = (*settings)->time_to_sleep;
	new->last_meal_time = set_curr_time();
	new->time_start = set_curr_time();
	new->nbr_philo = (*settings)->number_of_philosophers;
	new->has_died = false;
	new->is_eating = false;
	new->fork_left = &fork[i];
	new->dead_lock = &(*settings)->dead_lock;
	new->meal_lock = &(*settings)->meal_lock;
	new->write_lock = &(*settings)->write_lock;
	if (i > 0)
		new->fork_right = &fork[i -1];
	new->thread = new_t;
	return (new);
}

void	create_philosopher(t_settings **settings)
{
	int				i;
	t_philosopher	**new;
	pthread_mutex_t	fork[(*settings)->number_of_philosophers -1];

	i = 0;
	new = malloc(((*settings)->number_of_philosophers) * \
	sizeof(t_philosopher));
	if (!(new))
		error_msg(settings, 0);
	while (i < (*settings)->number_of_philosophers)
	{
		pthread_mutex_init(&fork[i], NULL);
		new[i] = add_philosopher(settings, i, fork);
		if (!new[i])
			error_msg(settings, 0);
		printf("philo[%i]\n", i);
		i++;
	}
	new[0]->fork_right = &fork[(*settings)->number_of_philosophers];
	new[i] = NULL;
	(*settings)->philo = new;
}
