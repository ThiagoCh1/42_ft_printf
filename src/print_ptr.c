/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:37:51 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/18 11:33:04 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_len(unsigned long v)
{
	size_t	n;

	n = 0;
	while (v)
	{
		v >>= 4;
		n++;
	}
	return (n);
}

static char	*ptr_to_str(unsigned long v)
{
	const char	*hex = "0123456789abcdef";
	size_t		nd;
	char		*s;

	if (v == 0)
		return (ft_strdup("(nil)"));
	nd = hex_len(v);
	s = (char *)malloc(2 + nd + 1);
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = 'x';
	s[2 + nd] = '\0';
	while (nd > 0)
	{
		nd--;
		s[2 + nd] = hex[v & 0xF];
		v >>= 4;
	}
	return (s);
}

int	print_ptr(va_list args, t_format *fmt)
{
	void	*p;
	char	*s;
	int		len;

	p = va_arg(args, void *);
	s = ptr_to_str((unsigned long)p);
	if (!s)
		return (-1);
	fmt->zero_pad = 0;
	s = apply_width(s, fmt);
	if (!s)
		return (-1);
	len = (int)ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
