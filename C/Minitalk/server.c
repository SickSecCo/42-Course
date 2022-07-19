/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:24:49 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:51 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	signal_consumer(int i)
{
	static int				bit_counter;
	static unsigned char	c;

	c |= (i == SIGUSR1);
	bit_counter++;
	if (bit_counter == 8 && c == '\0')
	{
		write(1, "\n", 1);
		c = 0;
		bit_counter = 0;
		return (0);
	}
	else if (bit_counter == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_counter = 0;
	}
	else
		c <<= 1;
	return (1);
}

void	signal_handler(int i, siginfo_t *sigstruct, void *k)
{
	if (signal_consumer(i) == 1)
		;
	else
	{
		usleep(500);
		kill(sigstruct->si_pid, SIGUSR1);
	}
	(void)k;
}

int	main(void)
{
	struct sigaction	mysig;

	mysig.sa_flags = SA_SIGINFO;
	sigemptyset(&mysig.sa_mask);
	mysig.sa_sigaction = signal_handler;
	ft_printf("PID: %i\nWaiting...\n", getpid());
	sigaction(SIGUSR1, &mysig, NULL);
	sigaction(SIGUSR2, &mysig, NULL);
	while (pause())
		;
	return (0);
}
