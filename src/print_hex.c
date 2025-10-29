/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:17:51 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/20 22:33:37 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	subtract_width(t_format *fmt, unsigned int n)
{
	if (fmt->hash && n != 0
		&& fmt->zero_pad && !fmt->left_align
		&& !fmt->has_precision && fmt->width > 0)
	{
		if (fmt->width > 2)
			return (fmt->width - 2);
		else
			return (0);
	}
	return (fmt->width);
}

int	print_hex(va_list args, char *base, t_format *fmt)
{
	unsigned int		n;
	int					len;
	char				*num;

	n = va_arg(args, unsigned int);
	num = ft_itoa_base(n, base);
	if (fmt -> has_precision)
	{
		num = apply_precision_num(num, fmt);
		fmt -> zero_pad = 0;
	}
	fmt->width = subtract_width(fmt, n);
	num = apply_width(num, fmt);
	if (fmt -> hash && n != 0 && ft_strncmp(base, "0123456789abcdef", 16) == 0)
		num = strjoin_free("0x", num);
	if (!num)
		return (-1);
	else if (fmt -> hash && n != 0
		&& ft_strncmp(base, "0123456789ABCDEF", 16) == 0)
		num = strjoin_free("0X", num);
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
