/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:14:29 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/27 17:32:39 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

#define TEST_C 9

#define PRINT(n, ...) {printf("\n--- TEST %d ---\n", n);\
	printf("Expected : ");\
	int a = printf(__VA_ARGS__);\
	puts("");\
	ft_printf("     Got : ");\
	int b = ft_printf(__VA_ARGS__);\
	puts("");\
	if (a == ++b) {printf(" %d ==> %d : OK\n", a, b); ok_count++;} else printf("%d ==> %d : KO\n", a, b);}

static int ok_count = 0;

void	final_grade(int total)
{
	printf("\nOK Count : %d / %d | %s\n", ok_count, total, (ok_count == TEST_C \
	? "\033[0;32mOK\033[0m" \
	: "\033[0;31mKO\033[0m"));
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Lis la doc mdr");
		return (-1);
	}
	if (*argv[1] == 'c')
	{
		PRINT(1, "%c", '0');
		PRINT(2, " %c ", '0');
		PRINT(3, " %c", '0' - 256);
		PRINT(4, "%c ", '0' + 256);
		PRINT(5, " %c %c %c ", '0', 0, '1');
		PRINT(6, " %c %c %c ", ' ', ' ', ' ');
		PRINT(7, " %c %c %c ", '1', '2', '3');
		PRINT(8, " %c %c %c ", '2', '1', 0);
		PRINT(9, " %c %c %c ", 0, '1', '2');
		final_grade(TEST_C);
	}
	return (0);
}