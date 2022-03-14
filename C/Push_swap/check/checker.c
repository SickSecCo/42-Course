/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:42:40 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:47:36 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

bool	is_command(t_list **a, t_list **b, char *output)
{
	if (str_compare("pa", output))
		push_a(a, b, false);
	else if (str_compare("pb", output))
		push_b(b, a, false);
	else if (str_compare("sa", output))
		swap_a(*a, false);
	else if (str_compare("sb", output))
		swap_b(*b, false);
	else if (str_compare("ss", output))
		swap_a_b(*a, *b, false);
	else if (str_compare("ra", output))
		rotate_a(a, false);
	else if (str_compare("rra", output))
		rotate_reverse_a(a, false);
	else if (str_compare("rb", output))
		rotate_b(b, false);
	else if (str_compare("rrb", output))
		rotate_reverse_b(b, false);
	else if (str_compare("rr", output))
		rotate_a_b(a, b, false);
	else if (str_compare("rrr", output))
		rotate_reverse_a_b(a, b, false);
	else
		return (false);
	return (true);
}

void	check_commands(t_list **list, t_list *b, char *output)
{
	int	i;

	i = 0;
	while (get_next_line(&output) > 0)
	{
		if (!(is_command(list, &b, output)))
		{
			ft_putstr("Error\n");
			return ;
		}
		free(output);
		output = NULL;
		i++;
	}
}

bool	check_if_ok_checker(t_list *list, char **arr, int index)
{
	t_list	*temp;

	temp = list;
	if (check_all(arr, index) == 0)
		return (false);
	fill_and_freestr(temp, index);
	return (true);
}

bool	check_if_ordered_checker(t_list *list)
{
	while (list->next)
	{
		if (list->cnt < list->next->cnt)
			list = list->next;
		else
			return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	char			**arr;
	t_list			*list;
	t_list			*temp;
	int				index;
	char			*output;

	output = NULL;
	if (do_check(&index, ac, av, &list) == NULL)
		return (0);
	arr = control(list, index);
	if (check_if_ok_checker(list, arr, index) == false)
		return (0);
	free(arr);
	do_it(&list, output);
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}
