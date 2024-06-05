/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:08 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 16:40:47 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philosopher_one(size_t i)
{
	if (stil_alive() == FAIL)
		return (FAIL);
	if (get_philo()->number_of_philosophers == 1)
	{
		delay_ms(get_philo()->time_to_die);
		print_state("died", i);
		unlock_all();
		return (FAIL);
	}
	return (SUCCESS);
}
