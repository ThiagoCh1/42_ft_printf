/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:36:05 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/20 18:57:39 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (print_int(args));
	else if (c == 'c')
		return (print_char(args));
	else if (c == 's')
		return (print_str(args));
	else if (c == 'p')
		return (print_ptr(args));
	else if (c == 'u')
		return (print_unint(args));
	else if (c == 'x')
		return (print_hex(args, "0123456789abcdef"));
	else if (c == 'X')
		return (print_hex(args, "0123456789ABCDEF"));
	else if (c == '%')
	{
		write(1, &c, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	va_list		args;
	t_format	fmt;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			fmt = {0};
			i = parse_format(format, i + 1, &fmt, args);
			count += print_type(fmt, args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
