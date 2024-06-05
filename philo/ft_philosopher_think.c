/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_think.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:13:39 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/24 14:14:07 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philosopher_think(size_t i)
{
	if (stil_alive() == FAIL)
		return (unlock_all(), FAIL);
	print_state("is thinking", i);
	return (0);
}
