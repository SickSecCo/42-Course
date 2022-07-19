/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:43:17 by fforlini          #+#    #+#             */
/*   Updated: 2022/05/10 15:51:07 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitoring(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	while (1)
	{
		sem_wait(philo->sem_philos);
		sem_wait(philo->init_ph->sem_death);
		if (ft_get_time() - philo->last_meal > philo->init_ph->to_die)
		{
			if (check_eaten(philo))
			{
				sem_post(philo->sem_philos);
				sem_post(philo->init_ph->sem_death);
				return (NULL);
			}
			ft_printing(philo, "died");
			kill(0, SIGTERM);
			return (NULL);
		}
		sem_post(philo->init_ph->sem_death);
		sem_post(philo->sem_philos);
	}
}

void	ft_phi_eat(t_philo *philo)
{
	if (philo->init_ph->num_philo == 1)
	{
		ft_printing(philo, "Has Taken a Fork");
		while (1)
			usleep(100);
	}
	sem_wait(philo->init_ph->semfork);
	ft_printing(philo, "Has Taken a Fork");
	ft_printing(philo, "Has Taken a Fork");
	sem_wait(philo->sem_philos);
	ft_printing(philo, "is eating");
	philo->last_meal = ft_get_time();
	sem_post(philo->sem_philos);
	ft_smart_action(philo->init_ph->to_eat);
	philo->n_meals++;
	sem_post(philo->init_ph->semfork);
}

void	ft_routine(t_philo *philo)
{
	pthread_t			thread;

	if (philo->ph_id == philo->init_ph->num_philo)
		sem_post(philo->init_ph->semstop);
	sem_wait(philo->init_ph->semstop);
	sem_post(philo->init_ph->semstop);
	philo->init_ph->timestart = ft_get_time();
	philo->last_meal = ft_get_time();
	pthread_create(&thread, NULL, ft_monitoring, philo);
	while (1)
	{
		ft_phi_eat(philo);
		ft_printing(philo, "Is sleeping");
		ft_smart_action(philo->init_ph->to_sleep);
		ft_printing(philo, "Is thinking");
		if (philo->n_meals == philo->init_ph->n_toeat)
		{
			set_eaten(philo);
			break ;
		}
	}
	pthread_join(thread, NULL);
	return (exit(0));
}

void	set_eaten(t_philo *philo)
{
	sem_wait(philo->init_ph->eaten);
	philo->init_ph->eat_all = 1;
	sem_post(philo->init_ph->eaten);
}

int	check_eaten(t_philo *philo)
{
	int a;

	sem_wait(philo->init_ph->eaten);
	a = philo->init_ph->eat_all;
	sem_post(philo->init_ph->eaten);
	return (a);
}

int	ft_create_process(t_philo *philo)
{
	int					i;

	i = -1;
	sem_wait(philo->init_ph->semstop);
	while (++i < philo->init_ph->num_philo)
	{
		philo->init_ph->parent_pid = getpid();
		philo->init_ph->pid[i] = fork();
		if (philo->init_ph->pid[i] < 0)
		{
			printf("Error fork!.. Killing Process!\n");
			while (--i >= 0)
				kill(philo->init_ph->pid[i], SIGTERM);
			return (1);
		}
		else if (philo->init_ph->pid[i] == 0)
			ft_routine(&philo[i]);
	}
	return (wait_for_it(philo));
}

int	main(int argc, char **argv)
{
	t_init	init;
	t_philo	*philo;

	if (ft_check_input(argc, argv) != 0)
		return (1);
	if (!ft_init_philo(&init, argv, argc))
		return (0);
	philo = ft_fill_philo(&init);
	if (ft_create_process(philo))
		return (1);
	return (0);
}
