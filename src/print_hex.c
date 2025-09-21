/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:17:51 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/21 05:20:58 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (fmt -> hash && n != 0 && ft_strncmp(base, "0123456789abcdef", 16) == 0)
		num = strjoin_free("0x", num);
	else if (fmt -> hash && n != 0
		&& ft_strncmp(base, "0123456789ABCDEF", 16) == 0)
		num = strjoin_free("0X", num);
	num = apply_width(num, fmt);
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
