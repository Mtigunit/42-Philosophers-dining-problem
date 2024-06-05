/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:22:14 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 16:51:20 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FAIL		1
# define SUCCESS	1337

typedef struct s_one_philosopher
{
	int				is_done;
	pthread_mutex_t	is_done_mutex;
	pthread_t		thread;
	pthread_mutex_t	fork;
	time_t			last_meal_time;
	long			number_of_meals;
}	t_one_philosopher;

typedef struct s_philosophers
{
	int					flag;
	time_t				birth_time;
	size_t				number_of_philosophers;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	size_t				meals_done;
	long				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t		meals_done_mutex;
	pthread_mutex_t		flag_mutex;
	pthread_mutex_t		lock_print;
	pthread_mutex_t		mutex;
	pthread_mutex_t		routine_mutex;
	pthread_mutex_t		died;
	t_one_philosopher	*p;
}	t_philosophers;

t_philosophers	*get_philo(void);
int				ft_philosopher_sleep(size_t i);
int				ft_philosopher_eat(size_t i);
int				ft_philosopher_think(size_t i);
int				routine(size_t i);
int				init_vars(int ac, char **av);
int				start_simutalion(void);
int				ft_philosopher_dead(size_t i);
int				stil_alive(void);
int				ft_philosopher_one(size_t i);
time_t			timestamp_in_ms(void);
int				ft_check_arg(const char *str);
void			usage(void);
time_t			timestamp_in_ms(void);
void			delay_ms(time_t ms);
void			print_state(const char *state, size_t i);
void			unlock_all(void);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);

#endif