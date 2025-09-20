/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:56:10 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/20 04:59:49 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../42_libft/libft.h"

int		ft_printf(char *format, ...);
char	*ft_itoa_base(unsigned long n, char *base);
int		print_int(va_list args);
int		print_char(va_list args);
int		print_str(va_list args);
int		print_ptr(va_list args);
int		print_unint(va_list args);
int		print_hex(va_list args, char *base);

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

#endif
