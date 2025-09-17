/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:29:36 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 19:32:56 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int		f;
	int		value;
	int		*ptr;
	char	*test;

	value = 42;
	ptr = &value;
	test = NULL;
	i = ft_printf("um simples %p teste %s %s", (void *)ptr, test, "oi");
	f = printf("um simples %p teste %s %s", (void *)ptr, test, "oi");
	ft_printf("%d", i);
	printf("%d", f);
}
