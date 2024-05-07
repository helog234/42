/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:37:45 by hgandar           #+#    #+#             */
/*   Updated: 2024/05/07 18:33:28 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_settings
{
	int						number_of_philosophers;
	size_t					time_start;	
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	int						number_of_times_each_philosopher_must_eat;
	pthread_mutex_t			dead_lock;
	pthread_mutex_t			meal_lock;
	pthread_mutex_t			write_lock;
	bool					one_dead;
	struct s_philosopher	**philo;
	pthread_t				thread;
}				t_settings;

typedef struct s_philosopher
{
	int				id;
	int				nbr_eaten_meal;
	size_t			time_start;	
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal_time;
	int				nbr_philo;
	bool			can_eat;
	bool			is_eating;
	bool			has_died;
	t_settings		**settings;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	pthread_t		thread;
}				t_philosopher;


// parsing.c
void	parsing(int argc, char **argv, t_settings **to_set, int i);
bool	ft_isdigit(char c);

// set_table.c
void	create_philosopher(t_settings **settings);

// process.c
bool	life_check(t_philosopher *philo);
void	*routine(void *arg);
void	create_threads(t_settings *settings);

//eat_think_sleep.c
void	think(t_philosopher *philo);
void	rest(t_philosopher *philo);
void	eat(t_philosopher *philo);

// dinner.c
void	*garcon(void *arg);
void	end_dinner(t_settings **set, t_philosopher **philo);
int		check_for_deads(t_settings *settings);
int		ctr_limit_meal(t_settings *settings);
void	*ctr_loops(void *arg);

// msg_and_free.c
void	print_msg(t_philosopher *philo, char *str, int id);
void	free_all(t_settings **settings, t_philosopher **philo);
void	error_msg(t_settings **settings, int flag);
void	destroy_mutex(t_settings **settings, t_philosopher **philo);

// utils.c
int		ft_strlen(const char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		my_usleep(size_t mscd);
size_t	set_curr_time(void);

#endif