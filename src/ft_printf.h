/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:56:10 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/21 05:18:17 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../42_libft/libft.h"

typedef struct s_format
{
	int		width;
	int		precision;
	int		has_precision;
	int		left_align;
	int		zero_pad;
	int		plus;
	int		space;
	int		hash;
	char	spec;
}	t_format;

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(unsigned long n, char *base);
int		print_int(va_list args, t_format *fmt);
int		print_char(va_list args, t_format *fmt, int isperc);
int		print_str(va_list args, t_format *fmt);
int		print_ptr(va_list args, t_format *fmt);
int		print_unint(va_list args, t_format *fmt);
int		print_hex(va_list args, char *base, t_format *fmt);
char	*apply_precision_num(char *s, t_format *fmt);
char	*apply_precision_str(char *s, t_format *fmt);
char	*apply_width(char *s, t_format *fmt);
char	*strjoin_free(char *pre, char *s);
int		parse_format(const char *format, int i, t_format *fmt, va_list args);

#endif
