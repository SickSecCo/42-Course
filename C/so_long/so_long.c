/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:47:14 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:53:28 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_data *var)
{
	var->mlx = NULL;
	var->win = NULL;
	var->img = NULL;
	var->path = NULL;
	var->map = NULL;
	var->matrix = NULL;
	var->count_moves = NULL;
	var->mstr_arr = NULL;
	var->dest = NULL;
	initialize_2(var);
}

void	initialize_2(t_data *var)
{
	var->coin = 0;
	var->check_e = 0;
	var->check_p = 0;
	var->count_step = 0;
	var->mstr_x = 0;
	var->mstr_y = 0;
	var->monsters = 0;
	var->j = 0;
	var->i = 0;
	var->height = 0;
	var->width = 0;
	var->x = 0;
	var->y = 0;
	var->bricks = 0;
	var->end = 0;
	var->winner = 0;
	var->trigger_start = 0;
	var->delay = 0;
	var->delay1 = 0;
	var->delay2 = 0;
	var->index1 = 0;
	var->loop = 0;
	var->stop_printing_coin = 0;
}

void	free_matrix(t_data *v)
{
	int	k;

	k = 0;
	while (k < v->height)
	{
		free(v->matrix[k]);
		k++;
	}
}

void	free_mstr_matrix(t_data *v)
{
	int	k;

	k = 0;
	while (k < v->monsters)
	{
		free(v->mstr_arr[k]);
		k++;
	}
}

int	main(int argc, char **argv)
{
	t_data	v;

	if (argc == 1)
		return (0);
	initialize(&v);
	v.map = argv[1];
	if (fill_matrix(&v) == 0)
		return (0);
	v.mlx = mlx_init();
	images(&v);
	v.win = mlx_new_window(v.mlx, v.width * 64, v.height * 64, "So_Long");
	put_map(&v);
	check_monster(&v);
	v.loop = 0;
	mlx_hook(v.win, 3, 1L << 1, check, &v);
	mlx_hook(v.win, 17, 0, quit, &v);
	mlx_loop_hook(v.mlx, loop_animation, &v);
	mlx_loop(v.mlx);
}
