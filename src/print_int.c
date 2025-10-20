/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:51:21 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/20 22:06:37 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_sign(long long *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return ('-');
	}
	return (0);
}

static char	*apply_sign(char *s, char sign, t_format *fmt)
{
	const char	*prefix;
	char		*temp;

	prefix = NULL;
	if (sign)
		prefix = "-";
	else if (fmt->plus)
		prefix = "+";
	else if (fmt->space)
		prefix = " ";
	if (prefix)
	{
		temp = ft_strjoin(prefix, s);
		free(s);
		return (temp);
	}
	return (s);
}

int	print_int(va_list args, t_format *fmt)
{
	long long	n;
	char		sign;
	char		*num;
	int			len;

	n = (long long)va_arg(args, int);
	sign = get_sign(&n);
	num = ft_itoa_base(n, "0123456789");
	if (!num)
		return (-1);
	if (fmt->has_precision)
	{
		num = apply_precision_num(num, fmt);
		fmt->zero_pad = 0;
	}
	num = apply_sign(num, sign, fmt);
	num = apply_width(num, fmt);
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
