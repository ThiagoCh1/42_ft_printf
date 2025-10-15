/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 01:50:15 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/15 01:18:05 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_and_free(char *s)
{
	size_t	n;

	n = ft_strlen(s);
	write(1, s, n);
	free(s);
	return ((int)n);
}

int	print_str(va_list args, t_format *fmt)
{
	const char	*src;
	size_t		len;
	char		*out;

	src = va_arg(args, char *);
	if (!src)
	{
		if (fmt->has_precision && fmt->precision < 6)
			src = "";
		else
			src = "(null)";
	}
	len = ft_strlen(src);
	if (fmt->has_precision && (size_t)fmt->precision < len)
		len = (size_t)fmt->precision;
	out = (char *)malloc(len + 1);
	if (!out)
		return (-1);
	ft_memcpy(out, src, len);
	out[len] = '\0';
	fmt->zero_pad = 0;
	out = apply_width(out, fmt);
	if (!out)
		return (-1);
	return (write_and_free(out));
}
