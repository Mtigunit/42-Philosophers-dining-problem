/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:17:52 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 17:07:37 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philosophers(int ac, char **av)
{
	get_philo()->number_of_philosophers = ft_atoi(av[1]);
	get_philo()->time_to_die = ft_atoi(av[2]);
	get_philo()->time_to_eat = ft_atoi(av[3]);
	get_philo()->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		get_philo()->number_of_times_each_philosopher_must_eat = -1;
	else if (ac == 6)
		get_philo()->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

int	init_vars(int ac, char **av)
{
	size_t	i;

	init_philosophers(ac, av);
	get_philo()->birth_time = timestamp_in_ms();
	if (pthread_mutex_init(&get_philo()->lock_print, NULL)
		|| pthread_mutex_init(&get_philo()->mutex, NULL)
		|| pthread_mutex_init(&get_philo()->routine_mutex, NULL)
		|| pthread_mutex_init(&get_philo()->died, NULL)
		|| pthread_mutex_init(&get_philo()->meals_done_mutex, NULL))
		return (FAIL);
	get_philo()->p = malloc(sizeof(t_one_philosopher)
		* get_philo()->number_of_philosophers);
	if (!get_philo()->p)
		return (FAIL);
	i = 0;
	while (i < get_philo()->number_of_philosophers)
	{
		if (pthread_mutex_init(&get_philo()->p[i].is_done_mutex, NULL))
			return (FAIL);
		if (pthread_mutex_init(&get_philo()->p[i].fork, NULL))
			return (FAIL);
		i++;
	}
	return (0);
}
