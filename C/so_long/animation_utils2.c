/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:49:45 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:53:10 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_animation(t_data *v)
{
	if (v->end == 0 && v->trigger_start != 0 && v->winner == 0)
	{
		player_animation(v);
		coin_animation(v);
		monster_animation(v);
		if (v->loop++ < 5000)
			return (0);
		v->loop = 0;
		mstr_move(v);
	}
	return (0);
}

void	images_3(t_data *v)
{	
	int	x;
	int	y;

	v->path[18] = "./image/coin_anm10.xpm";
	v->path[19] = "./image/coin_anm11.xpm";
	v->path[20] = "./image/player_anm0.xpm";
	v->path[21] = "./image/player_anm1.xpm";
	v->path[22] = "./image/player_anm2.xpm";
	v->path[23] = "./image/player_anm3.xpm";
	v->path[24] = "./image/win.xpm";
	v->path[25] = "./image/enemy_anm0.xpm";
	v->path[26] = "./image/enemy_anm1.xpm";
	v->path[27] = "./image/enemy_anm2.xpm";
	v->path[28] = "./image/enemy_anm3.xpm";
	v->img[18] = mlx_xpm_file_to_image(v->mlx, v->path[18], &x, &y);
	v->img[19] = mlx_xpm_file_to_image(v->mlx, v->path[19], &x, &y);
	v->img[20] = mlx_xpm_file_to_image(v->mlx, v->path[20], &x, &y);
	v->img[21] = mlx_xpm_file_to_image(v->mlx, v->path[21], &x, &y);
	v->img[22] = mlx_xpm_file_to_image(v->mlx, v->path[22], &x, &y);
	v->img[23] = mlx_xpm_file_to_image(v->mlx, v->path[23], &x, &y);
	v->img[24] = mlx_xpm_file_to_image(v->mlx, v->path[24], &x, &y);
	v->img[25] = mlx_xpm_file_to_image(v->mlx, v->path[25], &x, &y);
	v->img[26] = mlx_xpm_file_to_image(v->mlx, v->path[26], &x, &y);
	v->img[27] = mlx_xpm_file_to_image(v->mlx, v->path[27], &x, &y);
	v->img[28] = mlx_xpm_file_to_image(v->mlx, v->path[28], &x, &y);
}
