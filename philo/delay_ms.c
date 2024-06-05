/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay_ms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:06:36 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 16:39:56 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	delay_ms(time_t ms)
{
	time_t	t_final;

	t_final = timestamp_in_ms() + ms;
	while (timestamp_in_ms() < t_final)
		usleep(100);
}
