/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:37:51 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 19:16:09 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(va_list args)
{
	void	*ptr;
	int		len;
	char	*hex;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	hex = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	len = ((int)ft_strlen(hex));
	write(1, hex, len);
	free(hex);
	return (len + 2);
}
