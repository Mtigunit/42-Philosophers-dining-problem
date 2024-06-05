/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:11:31 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/25 13:55:33 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	unlock_all(void)
{
	size_t	i;

	i = 0;
	while (i < get_philo()->number_of_philosophers)
	{
		pthread_mutex_unlock(&get_philo()->p[i].is_done_mutex);
		pthread_mutex_unlock(&get_philo()->p[i].fork);
		i++;
	}
	pthread_mutex_unlock(&get_philo()->lock_print);
	pthread_mutex_unlock(&get_philo()->routine_mutex);
	pthread_mutex_unlock(&get_philo()->mutex);
	pthread_mutex_unlock(&get_philo()->died);
	pthread_mutex_unlock(&get_philo()->meals_done_mutex);
}
