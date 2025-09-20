/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:36:05 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/20 06:25:26 by thribeir         ###   ########.fr       */
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

int	parse_format(const char *format, int i, t_format *fmt, va_list args)
{
	while (format[i] && !ft_strchr("dicspuxX%", format[i]))
	{
		if (format[i] == ' ')
			fmt -> space = 1;
		else if
			(format[i] == '0')
			fmt -> zero_pad = 1;
		else if (format[i] == '+')
			fmt -> plus = 1;
		else if (format[i] == '-')
			fmt -> left_align = 1;
		else if (format[i] == '.')
		{
			i++;
			fmt -> has_precision = 1;
			if (format[i] == '*')
				fmt -> precision = va_arg(args, int);
			else
			{
				fmt -> precision = 0;
				while (ft_isdigit(format[i]))
					fmt -> precision = fmt -> precision * 10
						+ (format[i++] - '0');
			}
		}
		else if (ft_isdigit(format[i]))
		{
			fmt -> width = 0;
			while (ft_isdigit(format[i]))
				fmt -> width = fmt -> width * 10 + (format[i++] - '0');
		}
		/*Need to split in 3 functions in another file
		its missing the # flag
		deal with * in widith
		separete in normal flags, width and precision
		*/
	}
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
