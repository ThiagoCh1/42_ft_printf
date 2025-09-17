/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:29:36 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/17 02:13:47 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	f;

	i = ft_printf("um simples %c teste %s %s", 'a', "isso eh uma string", "oi");
	f = printf("um simples %c teste %s %s", 'a', "isso eh uma string", "oi");
	ft_printf("%d", i);
	printf("%d", f);
}
