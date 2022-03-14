/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_howmany.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:11 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:45:12 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	counter_how_many_ra(t_list **a, t_list **b, t_content bag)
{
	t_list	*last_a;
	int		i;
	int		count;

	i = 0;
	last_a = ft_lstlast(*a);
	bag.ind_counter = 30;
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		rotate_a(a, false);
		i++;
		last_a = ft_lstlast(*a);
		if (!check_for_condition(a, b, bag))
			return (i);
		if (i > bag.ind_counter)
			return (501);
	}
	return (i);
}

int	counter_how_many_rra(t_list **a, t_list **b, t_content bag)
{
	t_list	*last_a;
	int		i;
	int		count;

	i = 0;
	last_a = ft_lstlast(*a);
	bag.ind_counter = 30;
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		rotate_reverse_a(a, false);
		i++;
		last_a = ft_lstlast(*a);
		if (!check_for_condition(a, b, bag))
			return (i);
		if (i > bag.ind_counter)
			return (501);
	}
	return (i);
}

int	counter_how_many_rb(t_list **a, t_list **b, t_content bag)
{
	t_list	*last_a;
	int		i;
	int		count;

	i = 0;
	last_a = ft_lstlast(*a);
	bag.ind_counter = 30;
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		rotate_b(b, false);
		i++;
		last_a = ft_lstlast(*a);
		if (!check_for_condition(a, b, bag))
			return (i);
		if (i > bag.ind_counter)
			return (501);
	}
	return (i);
}

int	counter_how_many_rrb(t_list **a, t_list **b, t_content bag)
{
	t_list	*last_a;
	int		i;
	int		count;

	i = 0;
	last_a = ft_lstlast(*a);
	bag.ind_counter = 30;
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		rotate_reverse_b(b, false);
		i++;
		last_a = ft_lstlast(*a);
		if (!check_for_condition(a, b, bag))
			return (i);
		if (i > bag.ind_counter)
			return (501);
	}
	return (i);
}

int	counter_how_many_rr(t_list **a, t_list **b, t_content bag)
{
	t_list	*last_a;
	int		i;
	int		count;

	i = 0;
	last_a = ft_lstlast(*a);
	bag.ind_counter = 30;
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		rotate_a_b(a, b, false);
		i++;
		last_a = ft_lstlast(*a);
		if (!check_for_condition(a, b, bag))
			return (i);
		if (i > bag.ind_counter)
			return (501);
	}
	return (i);
}
