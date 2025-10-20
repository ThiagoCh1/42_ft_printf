/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:57:57 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/20 21:51:54 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unint(va_list args, t_format *fmt)
{
	unsigned int		n;
	int					len;
	char				*num;

	n = va_arg(args, unsigned int);
	num = ft_itoa_base(n, "0123456789");
	if (!num)
		return (-1);
	if (fmt -> has_precision)
	{
		num = apply_precision_num(num, fmt);
		fmt -> zero_pad = 0;
	}
	num = apply_width(num, fmt);
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
