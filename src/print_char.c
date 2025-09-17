/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 01:44:45 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 01:49:58 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write (1, &c, 1);
	return (1);
}
