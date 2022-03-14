/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:46:13 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:46:15 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list {
	int				cnt;
	char			*str_temp;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct ar_utils{
	char				**arr;
	int					lenght;
}	t_charr;

typedef struct lis_utils{
	int	*lis_ar;
	int	*arr_int;
	int	*clear_arr;
	int	count;
	int	index;
}	t_lis;

typedef struct s_content{
	int	cont_a;
	int	cont_b;
	int	code;
	int	min_lis_a;
	int	max_lis_a;
	int	start_a;
	int	start_b;
	int	ind;
	int	counter;
	int	max_b;
	int	min_b;
	int	stop;
	int	new_cont_a;
	int	new_cont_b;
	int	combo;
	int	ind_counter;
	int	ind_combo;
	int	last_a;
}	t_content;

char		**control(t_list *list, int index);
t_list		*ft_lstnew(int content);
t_list		*ft_lstnew_char(char *content);
t_list		*clear_all(int ac, char **av, int *index);
t_list		*clear_argument(t_charr *temp, t_list *list, int *index);
t_list		*do_check(int *index, int ac, char **av, t_list **list);
t_list		*ft_lstlast(t_list *lst);
t_charr		*swap_split(char const *s, char c);
bool		choose(t_list **a, t_list **b, int i, t_content bag);
bool		check_this(char *str, int k);
bool		check_if_ordered(t_list *list, char **arr, int index);
bool		check_for_condition(t_list **a, t_list **b, t_content bag);
size_t		ft_strlen(const char *s);
long long	ft_atoi(const char *str);
int			count_offset(t_lis lis_list, int count, int index);
int			max_elements(int *lis, int n);
int			ft_putstr(char *str);
int			check_size(char **av, int argc);
int			check_double(char **av, int argc);
int			check_integers(char **av, int argc);
int			check_all(char **av, int argc);
int			charsep(char c, char del);
int			count_chars(char *str, char del);
int			control_i(t_list *list, int i, int index, int k);
int			*confront(t_lis lis_list, int index);
int			*create_arr(t_list *list, int i);
int			*fill_arr_lis(int *arr, int n);
int			*lis(int *arr, int n, int *count);
int			choose_how_to(t_list *list, int find);
int			max_list(t_list *a);
int			min_list(t_list *a);
void		fill_and_freestr(t_list *list, int index);
void		free_str_list(t_list *list);
void		fill_list(t_list *temp_list, int index);
void		write_oneword(char *dst, char *src, char del);
void		strsplitwrite(char **str2, char *str, char del);
void		swap_a(t_list *list, bool allow);
void		swap_b(t_list *list, bool allow);
void		swap_a_b(t_list *list, t_list *listb, bool allow);
void		push_a(t_list **list, t_list **listb, bool allow);
void		push_b(t_list **listb, t_list **list, bool allow);
void		rotate_a(t_list **list, bool allow);
void		rotate_b(t_list **listb, bool allow);
void		rotate_a_b(t_list **list, t_list **listb, bool allow);
void		rotate_reverse_a(t_list **list, bool allow);
void		rotate_reverse_b(t_list **listb, bool allow);
void		rotate_reverse_a_b(t_list **list, t_list **listb, bool allow);
void		choose_how_to_sort(t_list **list, int index);
void		solve_2(t_list **a);
void		solve_3(t_list **a);
void		solve_5(t_list **a, t_list *list, int index);
void		re_order_a(t_list **a);
void		solve_500(t_list **a, t_list *b, int index);
void		push_lis(t_list **a, t_list **b, t_lis lis_list, int index);
void		control_how_to(t_list **a, t_list **b, t_content bag);
int			count_moves_util(t_list **a, t_list **b, t_content bag);
int			count_moves(t_list **a, t_list **b, t_content bag);
int			how_many_rb(t_list **a, t_list **b, t_content bag);
int			how_many_rrb(t_list **a, t_list **b, t_content bag);
int			how_many_rrr(t_list **a, t_list **b, t_content bag);
int			how_many_rr(t_list **a, t_list **b, t_content bag);
int			how_many_ra(t_list **a, t_list **b, t_content bag);
int			how_many_rra(t_list **a, t_list **b, t_content bag);
int			count_moves_ra(t_list **a, t_list **b, t_content bag, int *c);
int			count_moves_rra(t_list **a, t_list **b, t_content bag, int *c);
int			count_moves_rr(t_list **a, t_list **b, t_content bag, int *c);
int			count_moves_rrr(t_list **a, t_list **b, t_content bag, int *c);
int			count_moves_rb(t_list **a, t_list **b, t_content bag, int *c);
int			count_moves_rrb(t_list **a, t_list **b, t_content bag, int *c);
int			counter_moves(t_list **a, t_list **b, t_content bag);
int			counter_moves_util(t_list **a, t_list **b, t_content bag);
int			counter_how_many_ra(t_list **a, t_list **b, t_content bag);
int			counter_how_many_rb(t_list **a, t_list **b, t_content bag);
int			counter_how_many_rra(t_list **a, t_list **b, t_content bag);
int			counter_how_many_rrb(t_list **a, t_list **b, t_content bag);
int			counter_how_many_rr(t_list **a, t_list **b, t_content bag);
int			counter_how_many_rrr(t_list **a, t_list **b, t_content bag);
int			counter_moves_ra(t_list **a, t_list **b, t_content bag, int *c);
int			counter_moves_rra(t_list **a, t_list **b, t_content bag, int *c);
int			counter_moves_rr(t_list **a, t_list **b, t_content bag, int *c);
int			counter_moves_rrr(t_list **a, t_list **b, t_content bag, int *c);
int			counter_moves_rb(t_list **a, t_list **b, t_content bag, int *c);
int			counter_moves_rrb(t_list **a, t_list **b, t_content bag, int *c);
int			combo_moves(t_list **a, t_list **b, t_content bag);
int			combo_moves_util(t_list **a, t_list **b, t_content bag);
int			combo_how_many_ra(t_list **a, t_list **b, t_content bag);
int			combo_how_many_rra(t_list **a, t_list **b, t_content bag);
int			combo_how_many_rb(t_list **a, t_list **b, t_content bag);
int			combo_how_many_rrb(t_list **a, t_list **b, t_content bag);
int			combo_how_many_rr(t_list **a, t_list **b, t_content bag);
int			combo_how_many_rrr(t_list **a, t_list **b, t_content bag);
int			combo_moves_ra(t_list **a, t_list **b, t_content bag);
int			combo_moves_rra(t_list **a, t_list **b, t_content bag);
int			combo_moves_rr(t_list **a, t_list **b, t_content bag);
int			combo_moves_rrr(t_list **a, t_list **b, t_content bag);
int			combo_moves_rb(t_list **a, t_list **b, t_content bag);
int			combo_moves_rrb(t_list **a, t_list **b, t_content bag);
void		back_to_normal_util(t_list **a, t_list **b, t_content bag);
void		back_to_normal_util_1(t_list **a, t_list **b, t_content bag);
void		back_to_normal_util_2(t_list **a, t_list **b, t_content bag);
void		back_to_normal(t_list **a, t_list **b, t_content bag, int code);
void		back_to_normal1(t_list **a, t_list **b, t_content bag, int code);
void		check_safety(int safety, int *i);
bool		check_if_ordered_checker(t_list *list);
bool		check_if_ok_checker(t_list *list, char **arr, int index);
void		check_commands(t_list **list, t_list *b, char *output);
bool		is_command(t_list **a, t_list **b, char *output);
void		get_next_line_helper(char *buffer, int i, char **output);
int			get_next_line(char **output);
bool		str_compare(char *str, char *str2);
void		do_it(t_list **list, char *output);
#endif