/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:36:05 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 18:36:55 by thribeir         ###   ########.fr       */
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
	return (0);
}

int	ft_printf(char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += print_type(format[i + 1], args);
			i++;
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
