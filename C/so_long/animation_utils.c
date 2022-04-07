/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:46:08 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:46:14 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_win(t_data *v)
{
	v->winner = 1;
	put_map(v);
}

void	game_over(t_data *v, int i, int k)
{
	v->end = 1;
	v->matrix[i][k] = 'M';
	put_map(v);
}

int	quit(t_data *v)
{
	free(v->path);
	free(v->img);
	free_matrix(v);
	free(v->matrix);
	free_mstr_matrix(v);
	free(v->mstr_arr);
	mlx_destroy_window(v->mlx, v->win);
	exit (0);
}

int	ft_delay(int *delay, int time)
{
	if (*delay <= time)
	{
		*delay += 1;
		return (1);
	}
	*delay = 0;
	return (0);
}

void	check_gameover(t_data *v, int x, int y)
{
	v->matrix[v->i][v->j] = '0';
	return (game_over(v, v->i + x, v->j + y));
}
