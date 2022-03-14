/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:38 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/20 14:50:44 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	int		i;

	dst1 = (char *) dst;
	src1 = (char *) src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int) len - 1;
		while (i >= 0)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < (int)len)
			((char *) dst)[i] = ((char *) src)[i];
	}
	return (dst);
}
