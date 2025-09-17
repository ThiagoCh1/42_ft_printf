/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:56:10 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 20:22:24 by thribeir         ###   ########.fr       */
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

#endif
