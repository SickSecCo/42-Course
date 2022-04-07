/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:57 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/19 13:55:06 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char			*string;
	unsigned long	count;

	string = (char *) src;
	count = 0;
	while (*string)
	{
		string++;
		count++;
	}
	if (dstsize != 0)
	{
		while (*src && dstsize - 1 > 0)
		{
			*dst = *src;
			src++;
			dst++;
			dstsize--;
		}
		*(dst) = '\0';
	}
	return (count);
}
