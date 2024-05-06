/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:37:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/03 17:43:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_settings		*new_set;

	if (argc < 5)
		return (1);
	new_set = malloc(sizeof(t_settings));
	if (!new_set)
		return (1);
	new_set->philo = NULL;
	new_set->time_start = set_curr_time();
	new_set->one_dead = false;
	parsing(argc, argv, &new_set, 1);
	pthread_mutex_init(&new_set->dead_lock, NULL);
	pthread_mutex_init(&new_set->meal_lock, NULL);
	pthread_mutex_init(&new_set->write_lock, NULL);
	create_philosopher(&new_set);
	create_threads(new_set);
	return (0);
}
