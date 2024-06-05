/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_eat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:15:12 by mtigunit          #+#    #+#             */
/*   Updated: 2023/03/26 10:24:25 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	get_id(size_t i)
{
	size_t	id;

	if (i == 0)
		id = get_philo()->number_of_philosophers - 1;
	else
		id = i - 1;
	return (id);
}

static int	ft_philosopher_eat_help(size_t i)
{
	pthread_mutex_lock(&get_philo()->p[get_id(i)].fork);
	print_state("has taken a fork", i);
	pthread_mutex_lock(&get_philo()->lock_print);
	get_philo()->p[i].last_meal_time = timestamp_in_ms();
	pthread_mutex_unlock(&get_philo()->lock_print);
	pthread_mutex_lock(&get_philo()->lock_print);
	get_philo()->p[i].number_of_meals++;
	pthread_mutex_unlock(&get_philo()->lock_print);
	print_state("is eating", i);
	delay_ms(get_philo()->time_to_eat);
	pthread_mutex_unlock(&get_philo()->p[get_id(i)].fork);
	pthread_mutex_unlock(&get_philo()->p[i].fork);
	return (0);
}

int	ft_philosopher_eat(size_t i)
{
	pthread_mutex_lock(&get_philo()->lock_print);
	if (get_philo()->p[i].number_of_meals
		== get_philo()->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_unlock(&get_philo()->lock_print);
		pthread_mutex_lock(&get_philo()->meals_done_mutex);
		get_philo()->meals_done++;
		pthread_mutex_unlock(&get_philo()->meals_done_mutex);
	}
	pthread_mutex_unlock(&get_philo()->lock_print);
	print_state("has taken a fork", i);
	pthread_mutex_lock(&get_philo()->p[i].fork);
	if (ft_philosopher_one(i) == FAIL)
		return (unlock_all(), FAIL);
	pthread_mutex_lock(&get_philo()->meals_done_mutex);
	if (get_philo()->meals_done == get_philo()->number_of_philosophers)
		return (pthread_mutex_lock(&get_philo()->mutex),
			get_philo()->flag = FAIL, unlock_all(), FAIL);
	pthread_mutex_unlock(&get_philo()->meals_done_mutex);
	pthread_mutex_lock(&get_philo()->routine_mutex);
	if (ft_philosopher_dead(i) == FAIL)
		return (pthread_mutex_lock(&get_philo()->p[i].is_done_mutex),
			get_philo()->p[i].is_done = FAIL, unlock_all(), FAIL);
	pthread_mutex_unlock(&get_philo()->routine_mutex);
	return (ft_philosopher_eat_help(i));
}

// int	ft_philosopher_eat(size_t i)
// {
// 	pthread_mutex_lock(&get_philo()->lock_print);
// 	if (get_philo()->p[i].number_of_meals
// 		== get_philo()->number_of_times_each_philosopher_must_eat)
// 	{
// 		pthread_mutex_unlock(&get_philo()->lock_print);
// 		pthread_mutex_lock(&get_philo()->meals_done_mutex);
// 		get_philo()->meals_done++;
// 		pthread_mutex_unlock(&get_philo()->meals_done_mutex);
// 	}
// 	pthread_mutex_unlock(&get_philo()->lock_print);
// 	print_state("has take the left fork", i);
// 	pthread_mutex_lock(&get_philo()->p[i].fork);
// 	if (ft_philosopher_one(i) == FAIL)
// 		return (unlock_all(), FAIL);
// 	pthread_mutex_lock(&get_philo()->meals_done_mutex);
// 	if (get_philo()->meals_done == get_philo()->number_of_philosophers)
// 	{
// 		pthread_mutex_lock(&get_philo()->mutex);
// 		get_philo()->flag = FAIL;
// 		unlock_all();
// 		return (FAIL);
// 	}
// 	pthread_mutex_unlock(&get_philo()->meals_done_mutex);
// 	pthread_mutex_lock(&get_philo()->routine_mutex);
// 	if (ft_philosopher_dead(i) == FAIL)
// 	{
// 		pthread_mutex_lock(&get_philo()->p[i].is_done_mutex);
// 		get_philo()->p[i].is_done = FAIL;
// 		unlock_all();
// 		return (FAIL);
// 	}
// 	pthread_mutex_unlock(&get_philo()->routine_mutex);
// 	pthread_mutex_lock(&get_philo()->p[get_id(i)].fork);
// 	print_state("has take the right fork", i);
// 	pthread_mutex_lock(&get_philo()->lock_print);
// 	get_philo()->p[i].last_meal_time = timestamp_in_ms();
// 	pthread_mutex_unlock(&get_philo()->lock_print);
// 	pthread_mutex_lock(&get_philo()->lock_print);
// 	get_philo()->p[i].number_of_meals++;
// 	pthread_mutex_unlock(&get_philo()->lock_print);
// 	print_state("is eating", i);
// 	delay_ms(get_philo()->time_to_eat);
// 	pthread_mutex_unlock(&get_philo()->p[get_id(i)].fork);
// 	pthread_mutex_unlock(&get_philo()->p[i].fork);
// 	return (0);
// }