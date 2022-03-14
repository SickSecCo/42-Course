/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:24 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:45:26 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

long long	ft_atoi(const char *str)
{
	long long	n;
	long long	number;

	n = 1;
	number = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+' )
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	if (*str != '\0')
		return (0);
	return (number * n);
}

t_list	*do_check(int *index, int ac, char **av, t_list **list)
{
	*index = 0;
	if (ac == 1)
		return (NULL);
	*list = clear_all(ac, av, index);
	if (*list == NULL)
		return (NULL);
	return (*list);
}

void	free_str_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		free(temp->str_temp);
		temp = temp->next;
	}
}

bool	check_if_ordered(t_list *list, char **arr, int index)
{
	t_list	*temp;

	temp = list;
	if (check_all(arr, index) == 0)
		return (false);
	fill_and_freestr(temp, index);
	while (temp->next)
	{
		if (temp->cnt < temp->next->cnt)
			temp = temp->next;
		else
			return (true);
	}
	return (false);
}

void	fill_and_freestr(t_list *list, int index)
{
	t_list	*temp;

	temp = list;
	fill_list(temp, index);
	free_str_list(temp);
}
