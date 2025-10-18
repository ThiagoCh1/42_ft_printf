/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:03:12 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/18 15:25:02 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	print_percent(t_format *fmt)
{
	char	*s;
	int		len;

	s = (char *)malloc(2);
	if (!s)
		return (-1);
	s[0] = '%';
	s[1] = '\0';
	fmt->zero_pad = 0;
	if (!s)
		return (-1);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}