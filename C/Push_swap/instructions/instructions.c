/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:43:03 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:43:05 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	rotate_a(t_list **list, bool allow)
{
	t_list	*last;
	t_list	*head;

	if (allow)
		write (1, "ra\n", 3);
	if (!(*list) || !(*list)->next)
		return ;
	head = (*list);
	last = (*list);
	while (last->next)
		last = last->next;
	(*list) = head->next;
	last->next = head;
	head->next = NULL;
}

void	rotate_b(t_list **listb, bool allow)
{
	t_list	*last;
	t_list	*head;

	if (allow)
		write (1, "rb\n", 3);
	if (!(*listb) || !(*listb)->next)
		return ;
	last = (*listb);
	head = (*listb);
	while (last->next)
		last = last->next;
	(*listb) = head->next;
	last->next = head;
	head->next = NULL;
}

void	rotate_reverse_b(t_list **listb, bool allow)
{
	t_list	*last;
	t_list	*head;
	t_list	*pen;

	if (allow)
		write (1, "rrb\n", 4);
	if (!(*listb) || !(*listb)->next)
		return ;
	head = (*listb);
	last = (*listb);
	while (last->next)
	{
		if (!(last->next->next))
			pen = last;
		last = last->next;
	}
	last->next = head;
	*listb = last;
	pen->next = NULL;
}

void	rotate_reverse_a(t_list **list, bool allow)
{
	t_list	*last;
	t_list	*head;
	t_list	*pen;

	if (allow)
		write (1, "rra\n", 4);
	if (!(*list) || !(*list)->next)
		return ;
	head = (*list);
	last = (*list);
	while (last->next)
	{
		if (!(last->next->next))
			pen = last;
		last = last->next;
	}
	last->next = head;
	*list = last;
	pen->next = NULL;
}

void	rotate_reverse_a_b(t_list **list, t_list **listb, bool allow)
{
	if (allow)
		write (1, "rrr\n", 4);
	if (*list && *listb)
	{
		rotate_reverse_a(list, false);
		rotate_reverse_b(listb, false);
	}
	else
		return ;
}
