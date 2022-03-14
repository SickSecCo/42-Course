/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:42:48 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:42:51 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	rotate_a_b(t_list **list, t_list **listb, bool allow)
{
	if (allow)
		write (1, "rr\n", 3);
	if (*list && *listb)
	{
		rotate_a(list, false);
		rotate_b(listb, false);
	}
	else
		return ;
}

char	**control(t_list *list, int index)
{
	char	**clear_arr;
	int		i;

	i = 0;
	clear_arr = malloc(sizeof(char *) * index);
	while (list)
	{
		clear_arr[i++] = list->str_temp;
		list = list->next;
	}
	return (clear_arr);
}

t_list	*clear_all(int ac, char **av, int *index)
{
	t_list			*list;
	t_list			*util;
	t_list			*clear_well_pointed;
	t_charr			*temp;
	int				i;

	list = malloc(sizeof(t_list));
	util = list;
	clear_well_pointed = list;
	i = 0;
	while (++i < ac)
	{
		temp = swap_split(av[i], ' ');
		if (!temp->arr[0])
			continue ;
		list = clear_argument(temp, list, index);
		free(temp->arr);
		free(temp);
	}
	if (list->str_temp == NULL)
		return (NULL);
	clear_well_pointed = clear_well_pointed->next;
	free(util);
	return (clear_well_pointed);
}

t_list	*clear_argument(t_charr *temp, t_list *list, int *index)
{
	int		i;
	t_list	*temp_lis;

	i = 0;
	while (i < temp->lenght)
	{
		temp_lis = ft_lstnew_char(temp->arr[i++]);
		list->next = temp_lis;
		list = temp_lis;
		(*index)++;
	}
	return (list);
}

void	fill_list(t_list *temp_list, int index)
{
	unsigned int	i;

	i = 0;
	while (i < index)
	{
		temp_list->cnt = ft_atoi(temp_list->str_temp);
		temp_list->index = i;
		temp_list = temp_list->next;
		i++;
	}
}
