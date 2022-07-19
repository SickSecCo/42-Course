/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:50:08 by fforlini          #+#    #+#             */
/*   Updated: 2022/05/10 12:58:33 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_if_dead(t_philo *philo)
{
	int		i;

	while (!have_all_ate(philo))
	{
		i = -1;
		while (++i < philo->philo_stats->num_of_philos)
		{
			pthread_mutex_lock(&philo->philo_stats->lock_meal);
			if (get_time() - philo[i].last_meal > philo->philo_stats->to_die)
			{
				print_action(&philo[i], "died");
				philo->philo_stats->all_eat = 1;
				set_someone_died(philo);
				pthread_mutex_unlock(&philo->philo_stats->lock_meal);
				break ;
			}
			pthread_mutex_unlock(&philo->philo_stats->lock_meal);
		}
	}
	return ;
}

void	choose_what_to_sleep(t_philo *philo)
{
	if (philo->philo_stats->num_of_philos <= 8)
		usleep(250);
	else if (philo->philo_stats->num_of_philos <= 16)
		usleep(550);
	else if (philo->philo_stats->num_of_philos <= 24)
		usleep(800);
	else if (philo->philo_stats->num_of_philos <= 32)
		usleep(1050);
	else if (philo->philo_stats->num_of_philos <= 40)
		usleep(1350);
	else if (philo->philo_stats->num_of_philos <= 50)
		usleep(1650);
	else if (philo->philo_stats->num_of_philos <= 65)
		usleep(2000);
	else if (philo->philo_stats->num_of_philos <= 85)
		usleep(2700);
	else if (philo->philo_stats->num_of_philos <= 120)
		usleep(3700);
	else if (philo->philo_stats->num_of_philos <= 160)
		usleep(5000);
	else if (philo->philo_stats->num_of_philos <= 200)
		usleep(6500);
	else
		usleep(50000);
}

void	*routine_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	eat_mutex_handler(philo);
	if (philo->ph_id % 2)
	{
		choose_what_to_sleep(philo);
	}
	while (!is_someone_died(philo))
	{
		if (check_for_meals_eaten(philo))
			break;
		print_action(philo, "Is sleeping");
		action(philo->philo_stats->to_sleep, philo);
		print_action(philo, "Is thinking");
		if (philo->n_meals == philo->philo_stats->times_to_eat)
			return (NULL);
	}
	return (NULL);
}

int	make_threads(t_philo *philo, t_parameters *init)
{
	int			i;
	pthread_t	*th;

	i = -1;
	th = malloc(sizeof(pthread_t) * philo->philo_stats->num_of_philos);
	if (!th)
		return (printf("Error: pthread_t not allocated!!\n"));
	if (philo->philo_stats->num_of_philos == 1)
		return (one_philo(philo, th, init));
	while (++i < philo->philo_stats->num_of_philos)
		if (pthread_create(&th[i], NULL, routine_thread, &philo[i]))
			return (printf("Error: Thread not created!!\n"));
	while (!check_trigger_last_meal(philo))
		usleep(100);
	check_if_dead(philo);
	i = -1;
	while (++i < philo->philo_stats->num_of_philos)
		if (pthread_join(th[i], NULL))
			return (printf("Error: Thread not Joined!!\n"));
	if (free_all(th, philo, init))
		return (printf("Error: Something not freed correctly!!\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_parameters	init;
	t_philo			*philo;

	if (check_imput(argc, argv))
		return (0);
	if (!init_parameters(&init, argv, argc))
		return (0);
	philo = fill_philo(&init);
	if (make_threads(philo, &init))
	{
		free(init.fork);
		free(philo);
	}
	return (0);
}
