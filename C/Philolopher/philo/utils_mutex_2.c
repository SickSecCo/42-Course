/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:50:25 by fforlini          #+#    #+#             */
/*   Updated: 2022/05/10 13:13:15 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_static_i(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_stats->lock_static_i);
	philo->philo_stats->counter++;
	pthread_mutex_unlock(&philo->philo_stats->lock_static_i);
}

int	check_static_i(t_philo *philo)
{
	int	a;

	pthread_mutex_lock(&philo->philo_stats->lock_static_i);
	a = philo->philo_stats->counter;
	pthread_mutex_unlock(&philo->philo_stats->lock_static_i);
	return (a);
}

