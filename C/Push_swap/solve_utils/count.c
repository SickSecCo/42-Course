/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:07 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:45:08 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	count_moves(t_list **a, t_list **b, t_content bag)
{
	bag.counter = 2147483647;
	bag.cont_b = (*b)->cnt;
	bag.cont_a = (*a)->cnt;
	bag.last_a = ft_lstlast(*a)->cnt;
	bag.code = count_moves_util(a, b, bag);
	return (bag.code);
}

int	count_moves_util(t_list **a, t_list **b, t_content bag)
{
	int	code;

	if (bag.counter > how_many_ra(a, b, bag))
		bag.counter = count_moves_ra(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rb(a, b, bag))
		bag.counter = count_moves_rb(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rra(a, b, bag))
		bag.counter = count_moves_rra(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rrb(a, b, bag))
		bag.counter = count_moves_rrb(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rr(a, b, bag))
		bag.counter = count_moves_rr(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rrr(a, b, bag))
		bag.counter = count_moves_rrr(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	return (code);
}

int	count_moves_rrb(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 6;
	back_to_normal(a, b, bag, *c);
	temp = how_many_rrb(a, b, bag);
	back_to_normal(a, b, bag, *c);
	return (temp);
}

int	how_many_rrr(t_list **a, t_list **b, t_content bag)
{
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 100000;
	bag.ind = 40;
	while (!((*a)->cnt > (*b)->cnt && bag.last_a < (*b)->cnt))
	{
		rotate_reverse_a_b(a, b, false);
		i++;
		bag.last_a = ft_lstlast(*a)->cnt;
		if (!check_for_condition(a, b, bag) || i > bag.ind)
		{
			if (count > i)
				return (i);
			else
				return (count);
		}
		temp = counter_moves(a, b, bag);
		if (count > (temp + i))
			count = temp + i;
		if (count <= 5)
			return (count);
	}
}

void	re_order_a(t_list **a)
{
	while ((*a)->cnt != min_list(*a))
	{
		if (choose_how_to(*a, min_list(*a)))
			rotate_a(a, true);
		else
			rotate_reverse_a(a, true);
	}
}
