/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:00:43 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/25 17:15:27 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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
	ft_putchar(base[num % lenbase]);
	if (sign)
	{
		ft_putchar('-');
		sign = 0;
	}
}