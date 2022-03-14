/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:46:08 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:46:09 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	main(int ac, char **av)
{
	char			**arr;
	t_list			*list;
	t_list			*temp;
	int				index;

	if (do_check(&index, ac, av, &list) == NULL)
		return (0);
	arr = control(list, index);
	if (check_if_ordered(list, arr, index) == false)
		return (0);
	choose_how_to_sort(&list, index);
	free(arr);
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}
