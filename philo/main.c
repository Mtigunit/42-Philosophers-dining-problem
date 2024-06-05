/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:20:43 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/25 13:53:38 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosophers	*get_philo(void)
{
	static t_philosophers	p;

	return (&p);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (usage(), 1);
	if (((argc == 5) && (!ft_check_arg(argv[1]) || !ft_check_arg(argv[2])
				|| !ft_check_arg(argv[3]) || !ft_check_arg(argv[4])))
		|| ((argc == 6) && (!ft_check_arg(argv[1]) || !ft_check_arg(argv[2])
				|| !ft_check_arg(argv[3]) || !ft_check_arg(argv[4])
				|| !ft_check_arg(argv[5]))))
		return (usage(), 2);
	if (init_vars(argc, argv) == FAIL)
		return (3);
	if (start_simutalion() == FAIL)
		return (4);
	free (get_philo()->p);
	return (0);
}
