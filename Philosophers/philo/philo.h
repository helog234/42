/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:37:45 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/01 18:02:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO.H
# define PHILO.H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_settings
{
	int			number_of_philosophers;
	int			time_start;	
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	t_philosopher	**philo;
}				t_settings;

typedef struct s_philosopher
{
	int				id;
	int				nbr_eaten_meal;
	int				time_start;	
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				last_meal_time;
	bool			is_eating;
	bool			has_died;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*dead_lock;
	pthread_t		*thread;
}				t_philosopher;


// parsing.c
void	parsing(int argc, char **argv, t_settings **to_set, int i);
bool	ft_isdigit(char c);

// set_table.c
void	create_philosopher(t_settings **settings, pthread_mutex_t *fork);

//eat_think_sleep.c
void	think(t_philosopher *philo);
void	sleep(t_philosopher *philo);
void	eat(t_philosopher *philo);

// utils.c
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		my_usleep(size_t mscd);
size_t	set_curr_time(void);

#endif