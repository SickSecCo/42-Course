/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:47:20 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:51:26 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*line(char *a, int i)
{
	char	*new_a;

	new_a = malloc(i + 1);
	i = 0;
	while (a[i])
	{
		new_a[i] = a[i];
		i++;
	}
	new_a[i] = '\0';
	return (new_a);
}

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\0')
			break ;
		i++;
	}
	new_a = line(a, i);
	return (new_a);
}

void	images(t_data *v)
{
	int		x;
	int		y;

	v->path = (void **)malloc(sizeof(void **) * 100);
	v->img = (void **)malloc(sizeof(void **) * 100);
	v->path[0] = "./image/background.xpm";
	v->path[1] = "./image/wall.xpm";
	v->path[4] = "./image/exit.xpm";
	v->path[5] = "./image/open_exit.xpm";
	v->path[6] = "./image/end.xpm";
	v->path[7] = "./image/start.xpm";
	v->img[0] = mlx_xpm_file_to_image(v->mlx, v->path[0], &x, &y);
	v->img[1] = mlx_xpm_file_to_image(v->mlx, v->path[1], &x, &y);
	v->img[4] = mlx_xpm_file_to_image(v->mlx, v->path[4], &x, &y);
	v->img[5] = mlx_xpm_file_to_image(v->mlx, v->path[5], &x, &y);
	v->img[6] = mlx_xpm_file_to_image(v->mlx, v->path[6], &x, &y);
	v->img[7] = mlx_xpm_file_to_image(v->mlx, v->path[7], &x, &y);
	images_2(v);
}

void	images_2(t_data *v)
{	
	int	x;
	int	y;

	v->path[8] = "./image/coin_anm0.xpm";
	v->path[9] = "./image/coin_anm1.xpm";
	v->path[10] = "./image/coin_anm2.xpm";
	v->path[11] = "./image/coin_anm3.xpm";
	v->path[12] = "./image/coin_anm4.xpm";
	v->path[13] = "./image/coin_anm5.xpm";
	v->path[14] = "./image/coin_anm6.xpm";
	v->path[15] = "./image/coin_anm7.xpm";
	v->path[16] = "./image/coin_anm8.xpm";
	v->path[17] = "./image/coin_anm9.xpm";
	v->img[8] = mlx_xpm_file_to_image(v->mlx, v->path[8], &x, &y);
	v->img[9] = mlx_xpm_file_to_image(v->mlx, v->path[9], &x, &y);
	v->img[10] = mlx_xpm_file_to_image(v->mlx, v->path[10], &x, &y);
	v->img[11] = mlx_xpm_file_to_image(v->mlx, v->path[11], &x, &y);
	v->img[12] = mlx_xpm_file_to_image(v->mlx, v->path[12], &x, &y);
	v->img[13] = mlx_xpm_file_to_image(v->mlx, v->path[13], &x, &y);
	v->img[14] = mlx_xpm_file_to_image(v->mlx, v->path[14], &x, &y);
	v->img[15] = mlx_xpm_file_to_image(v->mlx, v->path[15], &x, &y);
	v->img[16] = mlx_xpm_file_to_image(v->mlx, v->path[16], &x, &y);
	v->img[17] = mlx_xpm_file_to_image(v->mlx, v->path[17], &x, &y);
	images_3(v);
}

bool	error(int i)
{
	if (i == 1)
		ft_printf("Error\n(hint).. check if walls surround the map.\n");
	if (i == 2)
		ft_printf("Error\n(hint).. check if the map is a rectangle.\n");
	if (i == 3)
	{
		ft_printf("Error\n(hint).. check ther'");
		ft_printf("re at least 1 exit, 1 collectible, 1 starting position.\n");
	}
	if (i == 4)
		ft_printf("Error\n(hint).. check if ther're some miswritten letters.\n");
	return (false);
}
