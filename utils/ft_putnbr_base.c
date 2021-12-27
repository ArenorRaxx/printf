/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:00:43 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/27 10:57:31 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_base(long num, char *base)
{
	static int		sign;	
	static size_t	lenbase;

	if (!lenbase)
		while (base[++lenbase])
			;
	if (num < 0 && sign == 0)
	{
		num *= -1;
		sign = 1;
	}
	if (num / lenbase != 0)
		ft_putnbr_base(num / lenbase, base);
	if (sign)
	{
		ft_putchar('-');
		sign = 0;
	}
	ft_putchar(base[num % lenbase]);
}