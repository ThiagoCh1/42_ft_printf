/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:22:18 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/16 00:53:28 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(unsigned long n, int base_len)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	int		base_len;
	int		len;
	char	*str;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = get_len(n, base_len);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
