/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:46:58 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:47:01 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_route(t_data *v, int k)
{
	if (v->i < v->mstr_y)
		move_mstr_up(v, k);
	if (v->j < v->mstr_x)
		move_mstr_left(v, k);
	if (v->i > v->mstr_y)
		move_mstr_down(v, k);
	if (v->j > v->mstr_x)
		move_mstr_right(v, k);
	return ;
}

void	move_mstr_right(t_data *v, int k)
{
	if (v->matrix[v->mstr_y][v->mstr_x + 1] == 'P')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		return (game_over(v, v->mstr_y, v->mstr_x + 1));
	}
	else if (v->matrix[v->mstr_y][v->mstr_x + 1] == '0')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		v->matrix[v->mstr_y][v->mstr_x + 1] = 'M';
		v->mstr_arr[k][1]++;
		mlx_put_image_to_window(v->mlx, v->win, v->img[0],
			v->mstr_x * 64, v->mstr_y * 64);
		mlx_put_image_to_window(v->mlx, v->win, v->img[25],
			(v->mstr_x + 1) * 64, v->mstr_y * 64);
		v->mstr_x++;
	}
	else
		return ;
}

void	move_mstr_left(t_data *v, int k)
{
	if (v->matrix[v->mstr_y][v->mstr_x - 1] == 'P')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		return (game_over(v, v->mstr_y, v->mstr_x - 1));
	}
	else if (v->matrix[v->mstr_y][v->mstr_x - 1] == '0')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		v->matrix[v->mstr_y][v->mstr_x - 1] = 'M';
		v->mstr_arr[k][1]--;
		mlx_put_image_to_window(v->mlx, v->win, v->img[0],
			v->mstr_x * 64, v->mstr_y * 64);
		mlx_put_image_to_window(v->mlx, v->win, v->img[25],
			(v->mstr_x - 1) * 64, v->mstr_y * 64);
		v->mstr_x--;
	}
	else
		return ;
}

void	move_mstr_up(t_data *v, int k)
{
	if (v->matrix[v->mstr_y - 1][v->mstr_x] == 'P')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		return (game_over(v, v->mstr_y - 1, v->mstr_x));
	}
	else if (v->matrix[v->mstr_y - 1][v->mstr_x] == '0')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		v->matrix[v->mstr_y - 1][v->mstr_x] = 'M';
		v->mstr_arr[k][0]--;
		mlx_put_image_to_window(v->mlx, v->win, v->img[0],
			v->mstr_x * 64, v->mstr_y * 64);
		mlx_put_image_to_window(v->mlx, v->win, v->img[25],
			v->mstr_x * 64, (v->mstr_y - 1) * 64);
		v->mstr_y--;
	}
	else
		return ;
}

void	move_mstr_down(t_data *v, int k)
{
	if (v->matrix[v->mstr_y + 1][v->mstr_x] == 'P')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		return (game_over(v, v->mstr_y + 1, v->mstr_x));
	}
	else if (v->matrix[v->mstr_y + 1][v->mstr_x] == '0')
	{
		v->matrix[v->mstr_y][v->mstr_x] = '0';
		v->matrix[v->mstr_y + 1][v->mstr_x] = 'M';
		v->mstr_arr[k][0]++;
		mlx_put_image_to_window(v->mlx, v->win, v->img[0],
			v->mstr_x * 64, v->mstr_y * 64);
		mlx_put_image_to_window(v->mlx, v->win, v->img[25],
			v->mstr_x * 64, (v->mstr_y + 1) * 64);
		v->mstr_y++;
	}
	else
		return ;
}
