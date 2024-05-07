/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/07 16:18:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_settings		*new_set;
	//int				i;

	if (argc < 5)
		return (1);
	new_set = malloc(sizeof(t_settings));
	if (!new_set)
		return (1);
	//i = 0;
	new_set->philo = NULL;
	new_set->time_start = set_curr_time();
	new_set->one_dead = false;
	parsing(argc, argv, &new_set, 1);
	pthread_mutex_init(&new_set->dead_lock, NULL);
	pthread_mutex_init(&new_set->meal_lock, NULL);
	pthread_mutex_init(&new_set->write_lock, NULL);
	create_philosopher(&new_set);
	create_threads(new_set);
	garcon(&new_set);
	/* while (1)
	{
		if (!new_set->philo[i]->is_eating && set_curr_time() - new_set->philo[i]->last_meal_time >= new_set->philo[i]->time_to_die / 3)
   			 new_set->philo[i]->can_eat = true;
		my_usleep(100);
		if (new_set->philo[i]->has_died || check_for_deads(&new_set) == 1 || ctr_limit_meal(&new_set) == 1)
		{
			end_dinner(&new_set, new_set->philo);
			break ;
		}
		i++;
		if (i == new_set->number_of_philosophers - 1)
			i = 0;
	} */
	return (0);
}
