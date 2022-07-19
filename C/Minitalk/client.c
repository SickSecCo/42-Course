/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:24:38 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:41 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	number;

	n = 1;
	number = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		n = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number * n);
}

void	confirm(int i)
{
	if (i == SIGUSR1)
		write(1, "received\n", 10);
	return ;
}

void	send_bits(char c, int pid, int i)
{
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	int		pid_server;
	char	*s;
	int		j;
	char	c;

	if (ac < 2)
		return (0);
	s = av[2];
	j = 0;
	pid_server = ft_atoi(av[1]);
	signal(SIGUSR1, confirm);
	while (s[j] != '\0')
	{
		c = s[j];
		send_bits(c, pid_server, 8);
		j++;
	}
	c = s[j];
	send_bits(c, pid_server, 8);
	pause();
	return (0);
}
