/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simutalion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:16:22 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 17:17:55 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	destroy_mutex(void)
{
	if (pthread_mutex_destroy(&get_philo()->lock_print)
		|| pthread_mutex_destroy(&get_philo()->mutex)
		|| pthread_mutex_destroy(&get_philo()->routine_mutex)
		|| pthread_mutex_destroy(&get_philo()->died)
		|| pthread_mutex_destroy(&get_philo()->meals_done_mutex))
		return (FAIL);
	return (SUCCESS);
}

int	start_simutalion(void)
{
	size_t	i;

	i = 0;
	while (i < get_philo()->number_of_philosophers)
	{
		if (pthread_create(&get_philo()->p[i].thread, NULL,
				(void *)routine, (size_t *)i))
			return (FAIL);
		i += 2;
	}
	delay_ms(get_philo()->time_to_eat);
	i = 1;
	while (i < get_philo()->number_of_philosophers)
	{
		if (pthread_create(&get_philo()->p[i].thread, NULL,
				(void *)routine, (size_t *)i))
			return (FAIL);
		i += 2;
	}
	i = 0;
	while (i < get_philo()->number_of_philosophers)
		if (pthread_join(get_philo()->p[i].thread, NULL)
			|| pthread_mutex_destroy(&get_philo()->p[i++].fork))
			return (FAIL);
	return (destroy_mutex());
}
