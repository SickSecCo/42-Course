/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5-500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:44:45 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:44:47 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	solve_500(t_list **a, t_list *b, int index)
{
	t_lis		lis_list;
	t_content	bag;
	int			count;

	lis_list.arr_int = create_arr(*a, index);
	lis_list.lis_ar = lis(lis_list.arr_int, index, &count);
	lis_list.count = count;
	lis_list.clear_arr = calloc(sizeof(int), lis_list.count);
	lis_list.clear_arr = confront(lis_list, (index - 1));
	push_lis(a, &b, lis_list, index);
	free(lis_list.clear_arr);
	free(lis_list.lis_ar);
	free(lis_list.arr_int);
	bag.max_lis_a = max_list(*a);
	bag.min_lis_a = min_list(*a);
	bag.max_b = max_list(b);
	bag.min_b = min_list(b);
	control_how_to(a, &b, bag);
	re_order_a(a);
	free(b);
}

void	control_how_to(t_list **a, t_list **b, t_content bag)
{
	t_list	*last_a;
	float	c;
	int		i;
	int		k;
	int		safety;

	safety = 0;
	k = 2;
	c = 2.0;
	while (*b)
	{
		last_a = ft_lstlast(*a);
		while (check_for_condition(a, b, bag))
		{
			i = count_moves(a, b, bag);
			if (!((c / 2) - (k / 2)))
				safety = i;
			c++;
			k = c;
			check_safety(safety, &i);
			if (choose(a, b, i, bag))
				break ;
		}
		push_a(a, b, true);
	}
}

void	check_safety(int safety, int *i)
{
	if ((*i) == 1 && safety == 2)
		(*i) = 5;
	else if ((*i) == 2 && safety == 1)
		(*i) = 5;
	else if ((*i) == 3 && safety == 4)
		(*i) = 1;
	else if ((*i) == 4 && safety == 3)
		(*i) = 1;
	else if ((*i) == 5 && safety == 6)
		(*i) = 2;
	else if ((*i) == 6 && safety == 5)
		(*i) = 2;
}

bool	choose(t_list **a, t_list **b, int i, t_content bag)
{
	if (i == 1)
		rotate_a(a, true);
	else if (i == 2)
		rotate_reverse_a(a, true);
	else if (i == 3)
		rotate_a_b(a, b, true);
	else if (i == 4)
		rotate_reverse_a_b(a, b, true);
	else if (i == 5)
		rotate_b(b, true);
	else if (i == 6)
		rotate_reverse_b(b, true);
	if (check_for_condition(a, b, bag))
		return (false);
	else
		return (true);
}

bool	check_for_condition(t_list **a, t_list **b, t_content bag)
{
	int	temp_last;

	temp_last = ft_lstlast(*a)->cnt;
	if ((*b)->cnt == bag.max_b && (*b)->cnt > bag.max_lis_a)
	{
		if ((*a)->cnt == min_list(*a) && temp_last == max_list(*a))
			return (false);
		else
			return (true);
	}
	if ((*b)->cnt == bag.min_b && (*b)->cnt < bag.min_lis_a)
	{
		if ((*a)->cnt == min_list(*a) && temp_last == max_list(*a))
			return (false);
		else
			return (true);
	}
	else if (!((*a)->cnt > (*b)->cnt && temp_last < (*b)->cnt))
		return (true);
	else
		return (false);
}
