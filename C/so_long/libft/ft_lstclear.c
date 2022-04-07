/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:44:52 by fforlini          #+#    #+#             */
/*   Updated: 2022/01/20 14:36:01 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*x;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		x = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = x;
	}
	*lst = 0;
}
