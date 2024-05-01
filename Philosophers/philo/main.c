/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:37:12 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/01 17:08:24 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_settings		*new_set;
	pthread_mutex_t	*fork;

	if (argc < 5)
		return (1);
	new_set = malloc(sizeof(t_settings));
	if (!new_set)
		return (1);
	new_set->philo = NULL;
	new_set->time_start = set_curr_time();
	parsing(argc, argv, new_set, 1);
	create_philosopher(&new_set, fork);
	
	free(new_set);
	return (0);
}
