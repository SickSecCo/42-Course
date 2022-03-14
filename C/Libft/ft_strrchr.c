/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:08:12 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/20 15:16:25 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*latest;

	latest = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			latest = ((char *)&str[i]);
		i++;
	}
	if ((char )c == str[i])
		return ((char *)&str[i]);
	return (latest);
}
