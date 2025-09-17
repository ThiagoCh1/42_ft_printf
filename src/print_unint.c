/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:57:57 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 20:05:50 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unint(va_list args)
{
	unsigned int		n;
	int					len;
	char				*num;

	n = va_arg(args, unsigned int);
	num = ft_itoa_base(n, "0123456789");
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
