/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp_in_ms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:03:41 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/26 11:04:51 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	timestamp_in_ms(void)
{
	struct timeval	time;
	time_t			curr_time;

	gettimeofday(&time, NULL);
	curr_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (curr_time - get_philo()->birth_time);
}
