/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2-5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:44:20 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:44:50 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	choose_how_to_sort(t_list **list, int index)
{
	t_list	*b;
	t_list	*temp_b;

	temp_b = calloc(sizeof(t_list), 1);
	b = temp_b->next;
	free(temp_b);
	if (index <= 2)
		solve_2(list);
	else if (index <= 3)
		solve_3(list);
	else if (index <= 5)
		solve_5(list, b, index);
	else
		solve_500(list, b, index);
}

void	solve_2(t_list **a)
{
	if ((*a)->cnt > (*a)->next->cnt)
		swap_a(*a, true);
}

void	solve_3(t_list **a)
{
	if ((*a)->cnt < (*a)->next->cnt
		&& (*a)->next->cnt < (*a)->next->next->cnt);
	else if ((*a)->cnt > (*a)->next->cnt
		&& (*a)->next->cnt > (*a)->next->next->cnt)
	{
		swap_a(*a, true);
		rotate_reverse_a(a, true);
	}
	else if ((*a)->cnt > (*a)->next->next->cnt
		&& (*a)->cnt < (*a)->next->cnt)
		rotate_reverse_a(a, true);
	else if ((*a)->cnt > (*a)->next->next->cnt)
		rotate_a(a, true);
	else if ((*a)->cnt < (*a)->next->next->cnt)
	{
		swap_a(*a, true);
		if ((*a)->next->cnt > (*a)->next->next->cnt
			|| (*a)->cnt > (*a)->next->next->cnt)
			rotate_a(a, true);
	}
}

void	solve_5(t_list **a, t_list *b, int index)
{
	int	i;
	int	x;

	x = index;
	while (index > 3)
	{
		i = control_i(*a, index, index, 0);
		if (i < 3)
		{
			while (--i > 0)
				rotate_a(a, true);
		}
		else
		{
			while (index - (i++) >= 0)
				rotate_reverse_a(a, true);
		}
		index--;
		push_b(&b, a, true);
	}
	solve_3(a);
	push_a(a, &b, true);
	push_a(a, &b, true);
}

int	control_i(t_list *list, int i, int index, int k)
{
	int		*arr;
	t_list	*temp;

	temp = list;
	arr = malloc(sizeof(int) * i);
	i = 0;
	while (temp)
	{
		arr[i++] = (temp->cnt);
		temp = temp->next;
	}
	i = 0;
	while (k < index)
	{
		if (arr[i] > arr[k])
		{
			i = k;
			k = 0;
			continue ;
		}
		k++;
	}
	free(arr);
	return (i + 1);
}
