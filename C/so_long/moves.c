/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:47:07 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:47:09 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(int keycode, t_data *v)
{
	if (keycode == 36 && v->trigger_start == 0)
	{
		v->trigger_start = 1;
		put_map(v);
	}
	if (keycode == 53 || keycode == 12)
		quit(v);
	else if (v->trigger_start != 0)
	{
		if (v->end == 1 || v->winner == 1)
			return (0);
		if (keycode == 13 || keycode == 126)
			move_up(v);
		if (keycode == 0 || keycode == 123)
			move_left(v);
		if (keycode == 1 || keycode == 125)
			move_down(v);
		if (keycode == 2 || keycode == 124)
			move_right(v);
		return (1);
	}
	return (0);
}

void	move_right(t_data *v)
{
	if (v->matrix[v->i][v->j + 1] == '1' ||
		((v->matrix[v->i][v->j + 1] == 'E') && v->coin != 0))
		return ;
	else if (v->matrix[v->i][v->j + 1] == 'M')
		return (check_gameover(v, 0, 1));
	else if (v->matrix[v->i][v->j + 1] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j + 1] = 'P';
	}
	else if (v->matrix[v->i][v->j + 1] == 'E' && v->coin == 0)
	{
		v->matrix[v->i][v->j] = '0';
		return (game_win(v));
	}
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j + 1] = 'P';
	}
	v->count_step++;
	v->j++;
	put_map(v);
}

void	move_left(t_data *v)
{
	if (v->matrix[v->i][v->j - 1] == '1' ||
		((v->matrix[v->i][v->j - 1] == 'E') && v->coin != 0))
		return ;
	else if (v->matrix[v->i][v->j - 1] == 'M')
		return (check_gameover(v, 0, -1));
	else if (v->matrix[v->i][v->j - 1] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j - 1] = 'P';
	}
	else if (v->matrix[v->i][v->j - 1] == 'E' && v->coin == 0)
	{
		v->matrix[v->i][v->j] = '0';
		return (game_win(v));
	}
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j - 1] = 'P';
	}
	v->count_step++;
	v->j--;
	put_map(v);
}

void	move_up(t_data *v)
{
	if (v->matrix[v->i - 1][v->j] == '1' ||
		((v->matrix[v->i - 1][v->j] == 'E') && v->coin != 0))
		return ;
	else if (v->matrix[v->i - 1][v->j] == 'M')
		return (check_gameover(v, -1, 0));
	else if (v->matrix[v->i - 1][v->j] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i - 1][v->j] = 'P';
	}
	else if (v->matrix[v->i - 1][v->j] == 'E' && v->coin == 0)
	{
		v->matrix[v->i][v->j] = '0';
		return (game_win(v));
	}
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i - 1][v->j] = 'P';
	}
	v->count_step++;
	v->i--;
	put_map(v);
}

void	move_down(t_data *v)
{
	if (v->matrix[v->i + 1][v->j] == '1' ||
		((v->matrix[v->i + 1][v->j] == 'E') && v->coin != 0))
		return ;
	else if (v->matrix[v->i + 1][v->j] == 'M')
		return (check_gameover(v, 1, 0));
	else if (v->matrix[v->i + 1][v->j] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i + 1][v->j] = 'P';
	}
	else if (v->matrix[v->i + 1][v->j] == 'E' && v->coin == 0)
	{
		v->matrix[v->i][v->j] = '0';
		return (game_win(v));
	}
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i + 1][v->j] = 'P';
	}
	v->count_step++;
	v->i++;
	put_map(v);
}
