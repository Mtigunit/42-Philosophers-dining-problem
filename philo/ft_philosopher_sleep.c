/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_sleep.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:14:18 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 14:14:50 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philosopher_sleep(size_t i)
{
	if (stil_alive() == FAIL)
		return (unlock_all(), FAIL);
	print_state("is sleeping", i);
	delay_ms(get_philo()->time_to_sleep);
	return (0);
}
