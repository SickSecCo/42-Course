/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:05:10 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/19 16:28:28 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substring;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		substring = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (len > 0 && start <= ft_strlen(s))
	{
		substring[i] = s[start];
		start++;
		i++;
		len--;
	}
	substring[i] = '\0';
	return (substring);
}
