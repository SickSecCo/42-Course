/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:10:36 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/20 15:02:40 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	numcar;

	if (!s)
		return ;
	numcar = 0;
	while (s[numcar] != '\0')
	{
		ft_putchar_fd(s[numcar], fd);
		numcar++;
	}
}
