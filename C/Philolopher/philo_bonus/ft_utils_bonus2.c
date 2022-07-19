/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:45:32 by fforlini          #+#    #+#             */
/*   Updated: 2022/05/10 12:45:34 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strcmp(char *s, char *str)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != str[i])
			return (1);
	}
	return (0);
}
