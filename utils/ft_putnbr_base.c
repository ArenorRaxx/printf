/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:00:43 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/25 16:41:10 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbr_base(int num, char *base)
{
	static int	lenbase;

	if (!lenbase)
		while (base[++lenbase])
			;
	if (num / lenbase != 0)
		ft_putnbr_base(num / lenbase, base);
	ft_putchar(base[num % lenbase]);
}