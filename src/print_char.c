/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 01:44:45 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/18 12:35:25 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnchar(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

int	print_char(va_list args, t_format *fmt, int isperc)
{
	char	c;

	if (isperc)
		c = '%';
	else
	{
		c = (char)va_arg(args, int);
		if (fmt -> width > 1)
		{
			if (fmt -> left_align)
			{
				write(1, &c, 1);
				ft_putnchar(' ', fmt -> width - 1);
			}
			else
			{
				ft_putnchar(' ', fmt -> width - 1);
				write(1, &c, 1);
			}
			return (fmt -> width);
		}
	}
	write(1, &c, 1);
	return (1);
}
