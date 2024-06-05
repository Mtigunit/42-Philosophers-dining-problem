/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:09:53 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 17:23:04 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	usage(void)
{
	write(2, "you must enter the following argements:", 39);
	write(2, "\n\t number_of_philosophers", 25);
	write(2, "\n\t time_to_die", 14);
	write(2, "\n\t time_to_eat", 14);
	write(2, "\n\t time_to_sleep", 16);
	write(2, "\n\t [number_of_times_each_philosopher_must_eat] -> optional\n", 59);
	write(2, "PS: All arguments must be positive numbers.\n", 44);
}
