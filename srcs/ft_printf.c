/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:56:03 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/28 12:44:32 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	count(int mod)
{
	static int	count;

	if (mod == 0)
		count = 0;
	else if (mod > 0)
		count += mod;
	return (count);
}

int	is_in_set(char c, const char *charset)
{
	while (c != *charset++)
		if (!*charset)
			return (0);
	return (1);
}

void	ft_format(char c, va_list args)
{
	if (c == 'c')
		ft_putchar((char) va_arg(args, int));
	else if (c == 's')
	{
		ft_putstr((char *) va_arg(args, char *));
	}
	// else if (c == 'p')
	// 	ft_putnbr_base((long)addr, "0123456789abcdef");
	else if (c == 'd')
		ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%');
}

int	ft_print_format(const char c, va_list args)
{
	const char	*format_set = "cspdiuxX%";

	if (is_in_set(c, format_set))
		ft_format(c, args);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	count(0);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_print_format(*format, args) < 0)
				return (-1);
			format++;
			continue ;
		}
		ft_putchar(*format++);
	}
	va_end(args);
	return (count(-1));
}