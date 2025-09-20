/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:00:17 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/20 21:11:57 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision_num(char *s, t_format *fmt)
{
	int		len;
	char	*pad;
	char	*new_s;

	if (fmt->has_precision && fmt->precision == 0
		&& s[0] == '0' && s[1] == '\0')
	{
		free(s);
		return (ft_strdup(""));
	}
	len = (int)ft_strlen(s);
	if (len < fmt -> precision)
	{
		pad = ft_calloc((fmt -> precision - len) + 1, 1);
		ft_memset(pad, '0', fmt -> precision - len);
		new_s = ft_strjoin(pad, s);
		free(s);
		free(pad);
		return (new_s);
	}
	return (s);
}

char	*apply_precision_str(char *s, t_format *fmt)
{
	int		len;
	char	*new_s;

	len = (int)ft_strlen(s);
	if (len > fmt -> precision)
	{
		new_s = ft_substr(s, 0, fmt -> precision);
		free(s);
		return (new_s);
	}
	return (s);
}
