/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:04:51 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 16:39:31 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	routine(size_t i)
{
	while (1)
	{
		pthread_mutex_lock(&get_philo()->p[i].is_done_mutex);
		if (get_philo()->p[i].is_done == FAIL)
			return (unlock_all(), FAIL);
		pthread_mutex_unlock(&get_philo()->p[i].is_done_mutex);
		pthread_mutex_lock(&get_philo()->routine_mutex);
		if (stil_alive() == FAIL)
			return (unlock_all(), FAIL);
		pthread_mutex_unlock(&get_philo()->routine_mutex);
		pthread_mutex_lock(&get_philo()->mutex);
		if (get_philo()->flag == FAIL)
			return (unlock_all(), FAIL);
		pthread_mutex_unlock(&get_philo()->mutex);
		if (ft_philosopher_eat(i) == FAIL)
			return (unlock_all(), FAIL);
		if (ft_philosopher_sleep(i) == FAIL)
			return (unlock_all(), FAIL);
		if (ft_philosopher_think(i) == FAIL)
			return (unlock_all(), FAIL);
	}
	return (0);
}
