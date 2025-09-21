/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:29:36 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/21 05:27:47 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		count1, count2;
	char	c = 'A';
	char	*str = "Hello, 42!";
	char	*null_str = NULL;
	void	*ptr = str;
	int		num = 42;
	unsigned int big = 3000000000u;

	/* %c and %% */
	count1 = ft_printf("ft: |%c| |%%|\n", c);
	count2 = printf("og: |%c| |%%|\n", c);
	printf("ret ft=%d og=%d\n\n", count1, count2);

	/* %c with '\0' and width */
	count1 = ft_printf("ft: |%5c|\n", '\0');
	count2 = printf("og: |%5c|\n", '\0');
	printf("ret ft=%d og=%d\n\n", count1, count2);

	/* %s with normal string */
	count1 = ft_printf("ft: |%s| |%.5s| |%10s| |%.0s|\n", str, str, str, str);
	count2 = printf("og: |%s| |%.5s| |%10s| |%.0s|\n", str, str, str, str);
	printf("ret ft=%d og=%d\n\n", count1, count2);

	/* %s with NULL string (system printf is undefined, so only show ft) */
	count1 = ft_printf("ft: |%s|\n", null_str);
	printf("ret ft=%d (og skipped: undefined for %%s NULL)\n\n", count1);

	/* %d / %i */
	count1 = ft_printf("ft: |%d| |%i| |%10d| |%.5d| |%+d| |% d|\n", num, num, num, num, num, num);
	count2 = printf("og: |%d| |%i| |%10d| |%.5d| |%+d| |% d|\n", num, num, num, num, num, num);
	printf("ret ft=%d og=%d\n\n", count1, count2);

	/* %u */
	count1 = ft_printf("ft: |%u| |%10u| |%.8u|\n", big, big, big);
	count2 = printf("og: |%u| |%10u| |%.8u|\n", big, big, big);
	printf("ret ft=%d og=%d\n\n", count1, count2);

	/* %x / %X with # */
	count1 = ft_printf("ft: |%x| |%X| |%#x| |%#X| |%10x| |%.8x|\n", num, num, num, num, num, num);
	count2 = printf("og: |%x| |%X| |%#x| |%#X| |%10x| |%.8x|\n", num, num, num, num, num, num);
	printf("ret ft=%d og=%d\n\n", count1, count2);

	/* %p with valid pointer */
	count1 = ft_printf("ft: |%p| |%20p|\n", ptr, ptr);
	count2 = printf("og: |%p| |%20p|\n", ptr, ptr);
	printf("ret ft=%d og=%d\n\n", count1, count2);

	/* %p with NULL pointer and precision (workaround with %.*p for system printf) */
	count1 = ft_printf("ft: |%p| |%.0p|\n", NULL, NULL);
	//count2 = printf("og: |%p| |%.*p|\n", NULL, 0, NULL);
	printf("ret ft=%d og=%d\n\n", count1, count2);

	return (0);
}

