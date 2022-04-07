/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:46:24 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:51:54 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_data *v)
{
	static int	x;

	if (x > 3)
		x = 0;
	if (ft_delay(&v->delay1, 1800) == 1)
		return ;
	mlx_put_image_to_window(v->mlx, v->win,
		v->img[20 + x], v->j * 64, v->i * 64);
	x += 1;
}

void	coin_animation(t_data *v)
{
	int			i;
	int			j;
	static int	x;

	i = -1;
	if (x > 11)
		x = 0;
	if (ft_delay(&v->delay, 1500) == 1)
		return ;
	while (++i < v->height)
	{
		j = -1;
		while (++j < v->width)
		{
			if (v->matrix[i][j] == 'C')
			{
				mlx_put_image_to_window(v->mlx, v->win,
					v->img[8 + x], j * 64, i * 64);
			}
		}
	}
	x += 1;
}

void	monster_animation(t_data *v)
{
	int			k;
	int			l;
	static int	x;

	k = 0;
	l = 0;
	if (x > 3)
		x = 0;
	if (ft_delay(&v->delay2, 1500) == 1)
		return ;
	while (v->monsters > k)
	{
		mlx_put_image_to_window(v->mlx, v->win, v->img[25 + x],
			v->mstr_arr[k][l + 1] * 64, v->mstr_arr[k][l] * 64);
		k++;
	}
	x += 2;
}

void	check_monster(t_data *v)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	l = 0;
	v->mstr_arr = malloc(sizeof(int *) * v->monsters);
	while (i < v->height)
	{
		j = 0;
		while (v->matrix[i][j] != '\0')
		{
			if (v->matrix[i][j] == 'M')
			{
				v->mstr_arr[k] = malloc(sizeof(int) * 2);
				v->mstr_arr[k][l] = i;
				v->mstr_arr[k][l + 1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	mstr_move(t_data *v)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (v->monsters > k)
	{
		v->mstr_y = v->mstr_arr[k][l];
		v->mstr_x = v->mstr_arr[k][l + 1];
		if (v->end == 0)
			find_route(v, k);
		k++;
	}
}
