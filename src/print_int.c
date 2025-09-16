/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:51:21 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/16 20:10:05 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
	char	*num;
	int		len;
	int		n;

	n = va_arg(args, int);
	num = ft_itoa(n);
	len = (int)ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
