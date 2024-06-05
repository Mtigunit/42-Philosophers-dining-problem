/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stil_alive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:46 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/25 13:53:53 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	stil_alive(void)
{
	size_t	i;

	i = 0;
	while (i < get_philo()->number_of_philosophers)
	{
		pthread_mutex_lock(&get_philo()->p[i].is_done_mutex);
		if (get_philo()->p[i].is_done == FAIL)
		{
			pthread_mutex_unlock(&get_philo()->p[i].is_done_mutex);
			break ;
		}
		pthread_mutex_unlock(&get_philo()->p[i].is_done_mutex);
		i++;
	}
	pthread_mutex_lock(&get_philo()->p[i].is_done_mutex);
	if (get_philo()->p[i].is_done == FAIL)
	{
		pthread_mutex_unlock(&get_philo()->p[i].is_done_mutex);
		return (FAIL);
	}
	pthread_mutex_unlock(&get_philo()->p[i].is_done_mutex);
	return (SUCCESS);
}
