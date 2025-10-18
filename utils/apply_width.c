/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:18:46 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/18 11:36:46 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	right_pad_spaces(char *out, char *s, size_t pad)
{
	size_t	len;

	len = ft_strlen(s);
	ft_memcpy(out, s, len);
	ft_memset(out + len, ' ', pad);
}

static void	left_pad_copy(char *out, char *s, size_t pad, char c)
{
	size_t	len;

	len = ft_strlen(s);
	ft_memset(out, c, pad);
	ft_memcpy(out + pad, s, len);
}

static void	put_sign_and_zeros(char *dst, char *src, size_t pad)
{
	size_t	len;

	len = ft_strlen(src);
	dst[0] = src[0];
	ft_memset(dst + 1, '0', pad);
	ft_memcpy(dst + 1 + pad, src + 1, len - 1);
}

char	*apply_width(char *s, t_format *fmt)
{
	size_t	len;
	size_t	pad;
	char	pad_char;
	char	*out;

	len = ft_strlen(s);
	if (fmt->width <= (int)len)
		return (s);
	pad = fmt->width - len;
	pad_char = ' ';
	if (fmt->zero_pad && !fmt->has_precision && !fmt->left_align)
		pad_char = '0';
	out = (char *)malloc(fmt->width + 1);
	if (!out)
		return (NULL);
	if (fmt->left_align)
		right_pad_spaces(out, s, pad);
	else if (pad_char == '0' && (s[0] == '-' || s[0] == '+' || s[0] == ' '))
		put_sign_and_zeros(out, s, pad);
	else
		left_pad_copy(out, s, pad, pad_char);
	out[fmt->width] = '\0';
	free(s);
	return (out);
}
