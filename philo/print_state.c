/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:10:41 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/26 10:56:53 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_state(const char *state, size_t i)
{
	if (stil_alive() == FAIL)
		return ;
	pthread_mutex_lock(&get_philo()->lock_print);
	printf("%-10ld%-4zu %s\n", timestamp_in_ms(), i + 1, state);
	pthread_mutex_unlock(&get_philo()->lock_print);
}
