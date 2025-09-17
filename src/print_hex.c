/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:17:51 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 20:23:52 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(va_list args, char *base)
{
	unsigned int		n;
	int					len;
	char				*num;

	n = va_arg(args, unsigned int);
	num = ft_itoa_base(n, base);
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
