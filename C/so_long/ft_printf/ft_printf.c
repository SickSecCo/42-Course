/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fforlini <fforlini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:47:59 by fforlini          #+#    #+#             */
/*   Updated: 2022/02/04 12:59:33 by fforlini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_ptr(unsigned long int a)
{
	int		total;
	char	*str;

	total = 0;
	str = "0123456789abcdef";
	if (a > 15)
	{
		total += total + ft_putnbr_hex_ptr(a / 16);
	}
	total += write(1, &str[a % 16], 1);
	return (total);
}

int	ft_putnbr_hex_x(unsigned int a)
{
	int		total;
	char	*str;

	total = 0;
	str = "0123456789abcdef";
	if (a > 15)
	{
		total += total + ft_putnbr_hex_x(a / 16);
	}
	total += write(1, &str[a % 16], 1);
	return (total);
}

int	ft_putnbr_hex_upper(unsigned long long int a)
{
	int		total;
	char	*str;

	total = 0;
	str = "0123456789ABCDEF";
	if (a > 15)
	{
		total += total + ft_putnbr_hex_upper(a / 16);
	}
	total += write(1, &str[a % 16], 1);
	return (total);
}

int	is_string(char c, int *counter, va_list ap)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		total += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		total += temp(va_arg(ap, int));
	else if (c == 'u')
		total += temp_u(va_arg(ap, unsigned int));
	else if (c == 'p')
		total += ft_putptrnbr(va_arg(ap, unsigned long int));
	else if (c == 'X')
		total += ft_putnbr_hex_upper(va_arg(ap, unsigned int));
	else if (c == 'x')
		total += ft_putnbr_hex_x(va_arg(ap, unsigned int));
	else if (c == '%')
		total += ft_putchar('%');
	*counter += 2;
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	int		*counter;
	int		pos;

	va_start(ap, format);
	pos = 0;
	counter = &pos;
	total = 0;
	while (format[*counter] != '\0')
	{
		if (format[*counter] == '%')
		{
			total += is_string(format[*counter + 1], counter, ap);
			if (!total && format[*counter] == '\0')
				break ;
			else if (total)
				continue ;
		}
		total += ft_putchar(format[*counter]);
		(*counter)++;
	}
	return (total);
}
