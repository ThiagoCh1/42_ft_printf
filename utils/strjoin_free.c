/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 02:43:35 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/21 02:55:47 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strjoin_free(char *pre, char *s)
{
	char	*new_s;

	if (!pre || !s)
		return (NULL);
	new_s = ft_strjoin(pre, s);
	free(s);
	return (new_s);
}
