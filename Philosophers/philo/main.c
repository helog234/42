/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/21 11:39:55 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_settings		*new_set;
	t_philosopher	**philo;
	int				i;

	new_set = malloc(sizeof(t_settings));
	if (argc < 5 || !new_set || init_dinner(argc, argv, new_set) == 1)
		error_msg(new_set, 0);
	create_threads(new_set);
	philo = new_set->philo;
	while (1)
	{
		if (check_for_deads(new_set) == 1 || ctr_limit_meal(new_set) == 1)
		{
			i = 0;
			while (i < new_set->number_of_philosophers && philo[i])
			{
				if (pthread_join(philo[i]->thread, NULL) != 0)
					error_msg(new_set, 2);
				i++;
			}
			break ;
		}
	}
	end_dinner(&new_set, new_set->philo);
	return (0);
}
