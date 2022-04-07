/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:46:50 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 11:27:39 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_matrix(t_data *v)
{
	int		fd;
	char	*line;

	v->width = 0;
	v->end = 0;
	fd = open(v->map, O_RDONLY);
	line = get_next_line(fd);
	v->matrix = ft_split(line, '\n', v);
	while (v->matrix[0][v->width] != '\0')
		v->width++;
	if (!check_rectangle(*v) || !check_exit_and_player_bool(v)
		|| !check_walls(*v) || !check_different(*v))
	{
		free_matrix(v);
		free(v->matrix);
		exit (0);
	}
	close(fd);
	free(line);
	return (1);
}

void	put_map(t_data *v)
{
	int		i;
	int		j;

	if (v->coin == 0)
		check_exit(v);
	i = -1;
	while (++i < v->height)
	{
		j = -1;
		while (++j < v->width)
		{
			put_map2(v, i, j);
		}
	}
	put_map3(v);
	if (v->trigger_start != 0 && v->end == 0 && v->winner == 0)
		ft_printf("moves :%d\n", v->count_step);
}

void	put_map2(t_data *v, int i, int j)
{
	if (v->matrix[i][j] == '0')
		mlx_put_image_to_window(v->mlx,
			v->win, v->img[0], j * 64, i * 64);
	if (v->matrix[i][j] == '1')
		mlx_put_image_to_window(v->mlx, v->win,
			v->img[1], j * 64, i * 64);
	if (v->matrix[i][j] == 'C' && v->trigger_start == 0)
		mlx_put_image_to_window(v->mlx,
			v->win, v->img[8], j * 64, i * 64);
	if (v->matrix[i][j] == 'M')
		mlx_put_image_to_window(v->mlx, v->win, v->img[25],
			j * 64, i * 64);
	if (v->matrix[i][j] == 'P')
		mlx_put_image_to_window(v->mlx, v->win, v->img[20],
			j * 64, i * 64);
	if (v->matrix[i][j] == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v->img[4],
			j * 64, i * 64);
}

void	put_map3(t_data *v)
{
	char	*itoa;

	mlx_string_put(v->mlx, v->win, 10, 30, 0xFFFFFF, "moves :");
	itoa = ft_itoa(v->count_step);
	mlx_string_put(v->mlx, v->win, 90, 30, 0xFFFFFF, itoa);
	free (itoa);
	if (v->trigger_start == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->img[7],
			((v->width * 64) / 2) - 300, ((v->height * 64) / 2) - 225);
	else if (v->end == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->img[6],
			((v->width * 64) / 2) - 200, ((v->height * 64) / 2) - 103);
	else if (v->winner == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->img[24],
			((v->width * 64) / 2) - 150, ((v->height * 64) / 2) - 130);
}

void	check_exit(t_data *v)
{
	int	x;
	int	y;

	v->img[4] = mlx_xpm_file_to_image(v->mlx, v->path[5], &x, &y);
}
