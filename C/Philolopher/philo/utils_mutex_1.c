/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:50:21 by fforlini          #+#    #+#             */
/*   Updated: 2022/05/10 13:12:28 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_stats->lock_fill_table);
	philo->philo_stats->start_eating = 1;
	pthread_mutex_unlock(&philo->philo_stats->lock_fill_table);
	return ;
}

int	check_start_eating(t_philo *philo)
{
	int	a;

	pthread_mutex_lock(&philo->philo_stats->lock_fill_table);
	a = philo->philo_stats->start_eating;
	pthread_mutex_unlock(&philo->philo_stats->lock_fill_table);
	return (a);
}

void	set_trigger_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_stats->lock_start_trigger);
	philo->philo_stats->trigger_last_meal = 1;
	pthread_mutex_unlock(&philo->philo_stats->lock_start_trigger);
	return ;
}

int	check_trigger_last_meal(t_philo *philo)
{
	int	a;

	pthread_mutex_lock(&philo->philo_stats->lock_start_trigger);
	a = philo->philo_stats->trigger_last_meal;
	pthread_mutex_unlock(&philo->philo_stats->lock_start_trigger);
	return (a);
}

void	mutex_util(t_parameters *parameter)
{
	pthread_mutex_init(&parameter->lock_died, NULL);
	pthread_mutex_init(&parameter->lock_writes, NULL);
	pthread_mutex_init(&parameter->lock_meal, NULL);
	pthread_mutex_init(&parameter->all_ate, NULL);
	pthread_mutex_init(&parameter->lock_all_eat, NULL);
	pthread_mutex_init(&parameter->lock_fill_table, NULL);
	pthread_mutex_init(&parameter->lock_ok, NULL);
	pthread_mutex_init(&parameter->lock_static_i, NULL);
	pthread_mutex_init(&parameter->lock_start_trigger, NULL);
	return ;
}
