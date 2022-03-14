/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:43:07 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:43:08 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	swap_a(t_list *list, bool allow)
{
	int	temp;

	if (allow)
		write(1, "sa\n", 3);
	if (!list)
		return ;
	else if (!list->next)
		return ;
	temp = list->cnt;
	list->cnt = list->next->cnt;
	list->next->cnt = temp;
}

void	swap_b(t_list *list, bool allow)
{
	int	temp;

	if (allow)
		write(1, "sb\n", 3);
	if (!list)
		return ;
	else if (!list->next)
		return ;
	temp = list->cnt;
	list->cnt = list->next->cnt;
	list->next->cnt = temp;
}

void	swap_a_b(t_list *list, t_list*listb, bool allow)
{
	if (allow)
		write(1, "ss\n", 3);
	if (list && listb)
	{
		swap_a(list, false);
		swap_b(listb, false);
	}
	else
		return ;
}

void	push_a(t_list **list, t_list **listb, bool allow)
{
	t_list	*temp;

	if (allow)
		write(1, "pa\n", 3);
	if (*listb)
	{
		temp = *listb;
		*listb = (*listb)->next;
		temp->next = *list;
		*list = temp;
	}
	else
		return ;
}

void	push_b(t_list **listb, t_list **list, bool allow)
{
	t_list	*temp;

	if (allow)
		write(1, "pb\n", 3);
	if (*list)
	{
		temp = *list;
		*list = (*list)->next;
		temp->next = *listb;
		*listb = temp;
	}
	else
		return ;
}
