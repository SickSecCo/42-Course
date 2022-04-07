/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:47:27 by fforlini          #+#    #+#             */
/*   Updated: 2022/04/05 10:50:49 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_data {
	void	**img;
	void	**path;
	void	*mlx;
	void	*win;
	void	*map;
	char	**matrix;
	char	**dest;
	char	*count_moves;
	int		j;
	int		i;
	int		height;
	int		width;
	int		coin;
	int		check_e;
	int		check_p;
	int		count_step;
	int		mstr_x;
	int		mstr_y;
	int		monsters;
	int		**mstr_arr;
	int		bricks;
	int		end;
	int		winner;
	int		trigger_start;
	int		delay;
	int		delay1;
	int		delay2;
	int		index1;
	int		x;
	int		y;
	int		loop;
	int		stop_printing_coin;
}				t_data;

char	**ft_split(char const *s, char c, t_data *v);
char	*get_next_line(int fd);
int		ft_delay(int *delay, int time);
int		check(int keycode, t_data *v);
int		check_size(t_data *v);
int		loop_animation(t_data *v);
int		fill_matrix(t_data *v);
int		loop_animation(t_data *v);
bool	check_rectangle(t_data v);
bool	check_walls(t_data v);
bool	error(int i);
bool	check_exit_and_player_bool(t_data *v);
void	check_exit_and_player(t_data *v);
bool	check_different(t_data var);
int		quit(t_data *v);
void	game_over(t_data *v, int i, int k);
void	game_win(t_data *v);
void	player_animation(t_data *v);
void	move_up(t_data *v);
void	move_down(t_data *v);
void	move_right(t_data *v);
void	move_left(t_data *v);
void	check_map(t_data v);
void	check_exit(t_data *v);
void	images(t_data *v);
void	put_map(t_data *v);
void	put_map2(t_data *v, int i, int j);
void	put_map3(t_data *v);
void	check_monster(t_data *v);
void	mstr_move(t_data *v);
void	find_route(t_data *v, int k);
void	move_mstr_right(t_data *v, int k);
void	move_mstr_left(t_data *v, int k);
void	move_mstr_up(t_data *v, int k);
void	move_mstr_down(t_data *v, int k);
void	coin_animation(t_data *v);
void	player_animation(t_data *v);
void	free_matrix(t_data *v);
void	free_mstr_matrix(t_data *v);
void	initialize(t_data *var);
void	initialize_2(t_data *var);
void	images_2(t_data *v);
void	check_gameover(t_data *v, int x, int y);
void	monster_animation(t_data *v);
void	images_3(t_data *v);

#endif