/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:36:05 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/20 22:09:04 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(t_format *fmt, va_list args)
{
	if (fmt -> spec == 'd' || fmt -> spec == 'i')
		return (print_int(args, fmt));
	else if (fmt -> spec == 'c')
		return (print_char(args, fmt, 0));
	else if (fmt -> spec == 's')
		return (print_str(args, fmt));
	else if (fmt -> spec == 'p')
		return (print_ptr(args, fmt));
	else if (fmt -> spec == 'u')
		return (print_unint(args, fmt));
	else if (fmt -> spec == 'x')
		return (print_hex(args, "0123456789abcdef", fmt));
	else if (fmt -> spec == 'X')
		return (print_hex(args, "0123456789ABCDEF", fmt));
	else if (fmt -> spec == '%')
		return (print_percent(fmt));
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
			ft_bzero(&fmt, sizeof(t_format));
			i = parse_format(format, i + 1, &fmt, args);
			count += print_type(&fmt, args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
