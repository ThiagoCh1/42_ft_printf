/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:37:51 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/21 04:39:05 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_null(t_format *fmt)
{
	if (fmt -> has_precision)
	{
		write(1, "0x", 2);
		return (2);
	}
	write(1, "(nil)", 5);
	return (5);
}

int	print_ptr(va_list args, t_format *fmt)
{
	void	*ptr;
	int		len;
	char	*hex;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (check_null(fmt));
	hex = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	if (fmt -> has_precision)
	{
		hex = apply_precision_num(hex, fmt);
		fmt -> zero_pad = 0;
	}
	hex = strjoin_free("0x", hex);
	hex = apply_width(hex, fmt);
	len = ((int)ft_strlen(hex));
	write(1, hex, len);
	free(hex);
	return (len);
}
