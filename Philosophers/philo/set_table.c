/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:34:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/21 10:54:40 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*add_philosopher(t_settings *settings, \
int i)
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
	pthread_mutex_init(&new->fork_right, NULL);
	new->fork_left = NULL;
	new->settings = settings;
	new->thread = (pthread_t){0};
	return (new);
}

int	create_philosopher(t_settings **settings)
{
	int				i;
	t_philosopher	**new;

	i = 0;
	new = malloc(((*settings)->number_of_philosophers) * \
	sizeof(t_philosopher *));
	if (!new)
		return (1);
	while (i < (*settings)->number_of_philosophers)
	{
		new[i] = add_philosopher(*settings, i);
		if (!new[i])
			return (1);
		if (i > 0)
			new[i]->fork_left = &new[i - 1]->fork_right;
		i++;
	}
	if ((*settings)->number_of_philosophers > 1)
		new[0]->fork_left = \
		&new[(*settings)->number_of_philosophers - 1]->fork_right;
	return ((*settings)->philo = new, 0);
}
