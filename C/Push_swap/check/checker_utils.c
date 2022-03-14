/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:40:40 by fforlini          #+#    #+#             */
/*   Updated: 2022/03/14 17:40:46 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

bool	str_compare(char *str, char *str2)
{
	while (*str2 || *str)
	{
		if (*str != *str2)
			return (false);
		str++;
		str2++;
	}
	return (true);
}

void	do_it(t_list **list, char *output)
{
	t_list	*b;
	t_list	*temp_b;

	temp_b = calloc(sizeof(t_list), 1);
	b = temp_b->next;
	free(temp_b);
	check_commands(list, b, output);
	free(output);
	while (b != NULL)
	{
		temp_b = b;
		b = b->next;
		free(temp_b);
	}
	if (check_if_ordered_checker(*list))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	get_next_line_helper(char *buffer, int i, char **output)
{
	int	j;

	j = 0;
	while (j < i)
	{
		output[0][j] = buffer[j];
		j++;
	}
	output[0][j] = '\0';
}

int	get_next_line(char **output)
{
	int		i;
	int		rd_buff;
	char	buffer[500000];

	i = 0;
	rd_buff = read(0, &buffer[i], 1);
	while (rd_buff >= 0)
	{
		if (buffer[i] == '\n' || !buffer[i])
		{
			buffer[i] = '\0';
			*output = malloc(sizeof(char) * (i + 1));
			if (!*output)
				return (0);
			get_next_line_helper(buffer, i, output);
			if (rd_buff == 0)
				return (0);
			else
				return (1);
		}
		i++;
		rd_buff = read(0, &buffer[i], 1);
	}
	return (-1);
}
