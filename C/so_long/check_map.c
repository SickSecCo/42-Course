/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:46:34 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:46:36 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_walls(t_data v)
{
	int	i;
	int	code;

	code = 1;
	i = -1;
	while (++i < v.width)
	{
		if (v.matrix[0][i] != '1')
			return (error(code));
		if (v.matrix[v.height - 1][i] != '1')
			return (error(code));
	}
	i = 1;
	while (i < v.height - 1)
	{
		if (v.matrix[i][0] != '1')
			return (error(code));
		if (v.matrix[i][v.width - 1] != '1')
			return (error(code));
		i++;
	}
	return (true);
}

bool	check_rectangle(t_data v)
{
	int	i;
	int	j;
	int	code;

	code = 2;
	i = 0;
	j = 0;
	while (i < v.height)
	{
		j = 0;
		while (v.matrix[i][j] != '\0')
			j++;
		if (j != v.width)
			return (error(code));
		i++;
	}
	return (true);
}

bool	check_exit_and_player_bool(t_data *v)
{
	int	code;

	code = 3;
	check_exit_and_player(v);
	if (v->check_p != 1 || v->check_e < 1 || v->coin == 0)
		return (error(code));
	return (true);
}

void	check_exit_and_player(t_data *v)
{
	int	i;
	int	j;

	i = -1;
	while (++i < v->height)
	{
		j = -1;
		while (++j < v->width)
		{
			if (v->matrix[i][j] == 'P')
			{
				v->i = i;
				v->j = j;
				v->check_p++;
			}
			if (v->matrix[i][j] == 'M')
				v->monsters++;
			if (v->matrix[i][j] == 'E')
				v->check_e++;
			if (v->matrix[i][j] == 'C')
				v->coin++;
		}
	}
}

bool	check_different(t_data v)
{
	int	i;
	int	j;
	int	code;

	code = 4;
	i = -1;
	while (++i < v.height)
	{
		j = -1;
		while (++j < v.width)
		{
			if (v.matrix[i][j] != '1' && v.matrix[i][j] != 'C'
			&& v.matrix[i][j] != 'M' && v.matrix[i][j] != 'P'
			&& v.matrix[i][j] != 'E' && v.matrix[i][j] != '0')
				return (error(code));
		}
	}
	return (true);
}
