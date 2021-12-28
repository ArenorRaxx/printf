/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:14:29 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/28 13:45:38 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ft_printf.h"

#define PRINT(n, ...) {printf("\n--- TEST %d ---\n", n);\
	printf("Expected : ");\
	int a = printf(__VA_ARGS__);\
	puts("");\
	ft_printf("     Got : ");\
	int b = ft_printf(__VA_ARGS__);\
	puts("");\
	if (a == b) {printf(" %d ==> %d : OK\n", a, b); ok_count++;} else printf("%d ==> %d : KO\n", a, b);}

static int ok_count = 0;

void	final_grade(int total)
{
	printf("\nOK Count : %d / %d | %s\n", ok_count, total, (ok_count == total \
	? "\033[0;32mOK\033[0m" \
	: "\033[0;31mKO\033[0m"));
}

int	main(void)
{
	int i;
	int n;

	n = 0;
	srand(time(0));
	for(i = 0; i != 100; i++)
	{
		n = rand();
		PRINT(i, "%x", n);
	}
	final_grade(i);
	return (0);
}