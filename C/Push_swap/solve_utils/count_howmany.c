/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_howmany.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:00 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:45:01 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	how_many_ra(t_list **a, t_list **b, t_content bag)
{
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 100000;
	bag.ind = 40;
	while (!((*a)->cnt > (*b)->cnt && bag.last_a < (*b)->cnt))
	{
		rotate_a(a, false);
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

int	how_many_rra(t_list **a, t_list **b, t_content bag)
{
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 100000;
	bag.ind = 40;
	while (!((*a)->cnt > (*b)->cnt && bag.last_a < (*b)->cnt))
	{
		rotate_reverse_a(a, false);
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

int	how_many_rb(t_list **a, t_list **b, t_content bag)
{
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 100000;
	bag.ind = 40;
	while (!((*a)->cnt > (*b)->cnt && bag.last_a < (*b)->cnt))
	{
		rotate_b(b, false);
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

int	how_many_rrb(t_list **a, t_list **b, t_content bag)
{
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 100000;
	bag.ind = 40;
	while (!((*a)->cnt > (*b)->cnt && bag.last_a < (*b)->cnt))
	{
		rotate_reverse_b(b, false);
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

int	how_many_rr(t_list **a, t_list **b, t_content bag)
{
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 100000;
	bag.ind = 40;
	while (!((*a)->cnt > (*b)->cnt && bag.last_a < (*b)->cnt))
	{
		rotate_a_b(a, b, false);
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
