/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:34:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/01 18:03:34 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*add_philosopher(t_settings **settings, \
int i, pthread_mutex_t *fork)
{
	int				j;
	t_philosopher	*new;

	j = 0;
	new = malloc(sizeof(t_philosopher));
	if (!new)
		return (NULL);
	new->id = i;
	new->nbr_eaten_meal = 0;
	new->time_to_die = set_curr_time();
	new->time_to_eat = set_curr_time();
	new->time_to_sleep = set_curr_time();
	new->last_meal_time = set_curr_time();
	new->time_start = (*settings)->time_start;
	new->has_died = false;
	new->is_eating = false;
	new->fork_left = &fork[i];
	if (i > 0)
		new->fork_right = &fork[i -1];
	new->thread = NULL;
}

void	create_philosopher(t_settings **settings, pthread_mutex_t *fork)
{
	int				i;
	t_philosopher	**new;

	i = 1;
	new = malloc(((*settings)->number_of_philosophers + 1) * \
	sizeof(t_philosopher));
	if (!(new))
		return (NULL);
	while (i <= (*settings)->number_of_philosophers)
	{
		pthread_mutex_init(&fork[i], NULL);
		new[i] = add_philosopher(settings, i, fork);
		if (!new[i])
			return ;
		i++;
	}
	new[0]->fork_right = &fork[(*settings)->number_of_philosophers];
	new[i] = NULL;
	(*settings)->philo = new;
}
