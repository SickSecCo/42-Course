/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:46:41 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:46:43 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_charset(char str, char c)
{
	if (str == c || str == '\0')
		return (1);
	else
		return (0);
}

static int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_charset(str[i], c) == 0)
		i++;
	return (i);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, c) == 1)
			str++;
		i = ft_wordlen(str, c);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_strdupp(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c, t_data *v)
{
	char		**dest;
	int			i;
	int			j;

	i = -1;
	if (!s)
		return (0);
	v->height = ft_wordcount((char *)s, c);
	dest = malloc((v->height + 1) * sizeof(char *));
	if (!dest || !s)
		return (0);
	while (++i < v->height)
	{
		while (ft_is_charset((char)*s, c))
			s++;
		j = ft_wordlen((char *)s, c);
		dest[i] = ft_strdupp((char *)s, j);
		s += j;
	}
	dest[v->height] = 0;
	return (dest);
}
