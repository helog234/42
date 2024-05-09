/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:18:08 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/09 10:00:16 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philosopher *philo, char *str, int id)
{
	t_settings	**set;

	set = philo->settings;

	pthread_mutex_lock(philo->write_lock);
	if ((*set)->one_dead)
	{
		//printf("%lu %i %s\n", set_curr_time() - philo->time_start, id, str);
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_destroy(philo->write_lock);
	}
	else
	{
		if (philo && id >= 0)
			printf("%lu %i %s\n", set_curr_time() - philo->time_start, id, str);
		else
			printf("%s\n", str);
		pthread_mutex_unlock(philo->write_lock);
	}
}

void	free_all(t_settings **settings, t_philosopher **philo)
{
	int	i;

	i = (*settings)->number_of_philosophers;
	//printf("ICIIIIIIIIIIIIIIIIII\n");
	if ((*settings)->end)
	{
		printf("la\n");
		pthread_mutex_destroy(&(*settings)->write_lock);
	}
	//pthread_mutex_destroy(&(*settings)->write_lock);
	pthread_mutex_destroy((*philo)->fork_right);
	pthread_mutex_destroy(&(*settings)->dead_lock);
	pthread_mutex_destroy(&(*settings)->meal_lock);
	while (philo && philo[i] && i >= 0)
	{
		free((*philo)->fork_right);
		free(philo[i]->thread);
		philo[i]->thread = NULL;
		free(philo[i]);
		philo[i] = NULL;
		i--;
	}
	free((*philo));
	philo = NULL;
	free((*settings));
	settings = NULL;
}

void	error_msg(t_settings **settings, int flag)
{
	if (flag == 0 && !(*settings)->philo)
		printf("error malloc\n");
	else if (flag == 0)
		print_msg(NULL, "error malloc", -1);
	else if (flag == 1)
		print_msg(*(*settings)->philo, "error creating mutex", -1);
	else if (flag == 2)
		print_msg(*(*settings)->philo, "error creating mutex", -1);
	else if (flag == 3)
		print_msg(*(*settings)->philo, "error joining mutex", -1);
	if (flag >= 0)
		free_all(settings, (*settings)->philo);
	exit(EXIT_FAILURE);
}
