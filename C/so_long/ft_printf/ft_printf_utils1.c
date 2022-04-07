/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:47:52 by fforlini          #+#    #+#             */
/*   Updated: 2022/02/04 12:59:33 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	total;

	if (str == NULL)
		return (ft_putstr("(null)"));
	total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		total += ft_putchar(str[i]);
		i++;
	}
	return (total);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putnbr_unsigned_int(unsigned int n)
{
	if (n < 0)
	{
		n = (4294967295 + n);
		ft_putnbr_unsigned_int(n);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_unsigned_int(n / 10);
		ft_putnbr_unsigned_int(n % 10);
	}
}

int	count_nbr(int n)
{
	unsigned int	i;

	i = 1;
	if (n == -2147483648)
	{
		i++;
		n = n + 1;
		n *= -1;
	}
	else if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
