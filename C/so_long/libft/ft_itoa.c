/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:03:56 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/20 14:34:37 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	selection(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	unsigned int	a;
	char			*string;

	a = selection(n);
	number = n;
	if (n < 0)
	{
		number *= -1;
		a++;
	}
	string = malloc(sizeof(char) * (a + 1));
	if (!string)
		return (NULL);
	*(string + a) = '\0';
	while (a-- != 0)
	{
		*(string + a) = (number % 10) + '0';
		number = number / 10;
	}
	if (n < 0)
		*(string + 0) = '-';
	return (string);
}
