/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:14:29 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/27 14:48:50 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

#define PRINT(...) {printf("Expected : ");\
	int a = printf(__VA_ARGS__);\
	puts("");\
	ft_printf("Got : ");\
	int b = ft_printf(__VA_ARGS__);\
	puts("");\
	if (a == b) {printf("%d ==> %d : OK", a, b); ok_count++;} else printf("%d ==> %d : KO", a, b);}

static int ok_count = 0;

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Lis la doc mdr");
		return (-1);
	}
	if ()
		PRINT("%d  %d", 10, 20);
	printf("\n%d", ok_count);
}