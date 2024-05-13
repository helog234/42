/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:34:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/13 15:50:16 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*add_philosopher(t_settings *settings, \
int i, pthread_mutex_t *fork)
{
	t_philosopher	*new;

	new = malloc(sizeof(t_philosopher));
	if (!new)
		return (NULL);
	new->id = i + 1;
	new->nbr_eaten_meal = 0;
	new->last_meal_time = set_curr_time();
	new->has_died = false;
	new->is_eating = false;
	new->fork_right = &fork[i];
	new->settings = settings;
	if (i > 0)
		new->fork_left = &fork[i - 1];
	new->thread = (pthread_t){0};
	return (new);
}

int	create_philosopher(t_settings **settings)
{
	int				i;
	t_philosopher	**new;
	pthread_mutex_t	*fork;

	i = 0;
	new = malloc(((*settings)->number_of_philosophers + 1) * \
	sizeof(t_philosopher *));
	fork = malloc(((*settings)->number_of_philosophers + 1) * \
	sizeof(pthread_mutex_t));
	if (!new || !fork)
		return (1);
	while (i < (*settings)->number_of_philosophers)
	{
		pthread_mutex_init(&fork[i], NULL);
		new[i] = add_philosopher(*settings, i, fork);
		if (!new[i])
			return (1);
		i++;
	}
	if ((*settings)->number_of_philosophers > 1)
		new[0]->fork_left = &fork[(*settings)->number_of_philosophers];
	else
		new[0]->fork_left = NULL;
	new[i] = NULL;
	return ((*settings)->philo = new, 0);
}
