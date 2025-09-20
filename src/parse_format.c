/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:53:25 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/20 18:57:22 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(const char *format, int i, t_format *fmt)
{
	if (format[i] == ' ')
		fmt -> space = 1;
	else if (format[i] == '0')
		fmt -> zero_pad = 1;
	else if (format[i] == '+')
		fmt -> plus = 1;
	else if (format[i] == '-')
		fmt -> left_align = 1;
	else if (format[i] == '#')
		fmt -> hash = 1;
	i++;
	return (i);
}

int	parse_precision(const char *format, int i, t_format *fmt, va_list args)
{
	i++;
	fmt -> has_precision = 1;
	if (format[i] == '*')
	{
		fmt -> precision = va_arg(args, int);
		if (fmt -> precision < 0)
			fmt -> has_precision = 0;
		i++;
	}
	else
	{
		fmt -> precision = 0;
		while (ft_isdigit(format[i]))
			fmt -> precision = fmt -> precision * 10 + (format[i++] - '0');
	}
	return (i);
}

int	parse_width(const char *format, int i, t_format *fmt, va_list args)
{
	if (format[i] == '*')
	{
		fmt -> width = va_arg(args, int);
		if (fmt -> width < 0)
		{
			fmt -> left_align = 1;
			fmt -> width = -fmt -> width;
		}
		i++;
	}
	else
	{
		fmt -> width = 0;
		while (ft_isdigit(format[i]))
			fmt -> width = fmt -> width * 10 + (format[i++] - '0');
	}
	return (i);
}

int	parse_format(const char *format, int i, t_format *fmt, va_list args)
{
	while (format[i] && !ft_strchr("dicspuxX%", format[i]))
	{
		if (ft_strchr(" 0+-#", format[i]))
			i = parse_flags(format, i, fmt);
		else if (format[i] == '.')
			i = parse_precision(format, i, fmt, args);
		else if (ft_strchr("*123456789", format[i]))
			i = parse_width(format, i, fmt, args);
		else
			i++;
	}
	fmt -> spec = format[i];
	return (i);
}
