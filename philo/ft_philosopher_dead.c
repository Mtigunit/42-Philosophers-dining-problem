/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:19:07 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/25 13:32:14 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philosopher_dead(size_t i)
{
	if (stil_alive() == FAIL)
		return (FAIL);
	pthread_mutex_lock(&get_philo()->died);
	if ((timestamp_in_ms() - get_philo()->p[i].last_meal_time)
		>= get_philo()->time_to_die)
	{
		pthread_mutex_unlock(&get_philo()->died);
		print_state("died", i);
		unlock_all();
		return (FAIL);
	}
	pthread_mutex_unlock(&get_philo()->died);
	return (SUCCESS);
}
