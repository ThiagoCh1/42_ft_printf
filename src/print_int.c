/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:51:21 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/21 05:33:41 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_sign(int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return ('-');
	}
	return (0);
}

char	*apply_sign(char *s, char sign, t_format *fmt)
{
	if (sign)
		return (strjoin_free("-", s));
	else if (fmt -> plus)
		return (strjoin_free("+", s));
	else if (fmt -> space)
		return (strjoin_free(" ", s));
	return (s);
}

int	print_int(va_list args, t_format *fmt)
{
	int		n;
	char	sign;
	char	*num;
	int		len;

	n = va_arg(args, int);
	sign = get_sign(&n);
	num = ft_itoa(n);
	if (fmt -> has_precision)
	{
		num = apply_precision_num(num, fmt);
		fmt -> zero_pad = 0;
	}
	num = apply_sign(num, sign, fmt);
	num = apply_width(num, fmt);
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}

