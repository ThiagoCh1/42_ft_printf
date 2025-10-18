/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:40:29 by thribeir          #+#    #+#             */
/*   Updated: 2025/10/18 14:12:38 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int j = ft_printf("%5%\n");
    int i = printf("%5%\n");
	printf ("ft = %d  print = %d", j, i);
    return 0;
}