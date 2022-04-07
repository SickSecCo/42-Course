/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:06:58 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/20 15:15:46 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*string;
	size_t	i;

	i = 0;
	string = malloc(count * size);
	if (!string)
		return (NULL);
	while (i < (count * size))
	{
		string[i] = '\0';
		i++;
	}
	return (string);
}
