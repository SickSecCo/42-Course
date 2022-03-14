/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:18 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:45:20 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	counter_moves(t_list **a, t_list **b, t_content bag)
{
	bag.stop = 2147483647;
	bag.new_cont_b = (*b)->cnt;
	bag.new_cont_a = (*a)->cnt;
	bag.stop = counter_moves_util(a, b, bag);
	return (bag.stop);
}

int	counter_moves_util(t_list **a, t_list **b, t_content bag)
{
	int	code;

	if (bag.stop > counter_how_many_ra(a, b, bag))
		bag.stop = counter_moves_ra(a, b, bag, &code);
	back_to_normal_util_1(a, b, bag);
	if (bag.stop > counter_how_many_rb(a, b, bag))
		bag.stop = counter_moves_rb(a, b, bag, &code);
	back_to_normal_util_1(a, b, bag);
	if (bag.stop > counter_how_many_rra(a, b, bag))
		bag.stop = counter_moves_rra(a, b, bag, &code);
	back_to_normal_util_1(a, b, bag);
	if (bag.stop > counter_how_many_rrb(a, b, bag))
		bag.stop = counter_moves_rrb(a, b, bag, &code);
	back_to_normal_util_1(a, b, bag);
	if (bag.stop > counter_how_many_rr(a, b, bag))
		bag.stop = counter_moves_rr(a, b, bag, &code);
	back_to_normal_util_1(a, b, bag);
	if (bag.stop > counter_how_many_rrr(a, b, bag))
		bag.stop = counter_moves_rrr(a, b, bag, &code);
	back_to_normal_util_1(a, b, bag);
	return (bag.stop);
}

int	counter_moves_rrb(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	*c = 6;
	back_to_normal1(a, b, bag, *c);
	temp = counter_how_many_rrb(a, b, bag);
	back_to_normal1(a, b, bag, *c);
	return (temp);
}

int	counter_how_many_rrr(t_list **a, t_list **b, t_content bag)
{
	t_list	*last_a;
	int		i;
	int		count;

	i = 0;
	last_a = ft_lstlast(*a);
	bag.ind_counter = 30;
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		rotate_reverse_a_b(a, b, false);
		i++;
		last_a = ft_lstlast(*a);
		if (!check_for_condition(a, b, bag))
			return (i);
		if (i > bag.ind_counter)
			return (501);
	}
	return (i);
}
