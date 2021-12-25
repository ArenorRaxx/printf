/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:56:03 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/25 15:59:40 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		is_in_set(char c, const char *charset)
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
		ft_putstr((char *) va_arg(args, char *));
	else if (c == 'p')
		;//ft_putpointer(va_arg(args, void *), "0123456789ABCDEF")
	else if (c == 'd')
		;//ft_putnbr_base(va_arg(args, int), "0123456789")
	else if (c == 'i')
		;//ft_putnbr_base(va_arg(args, int), "0123456789")
	else if (c == 'u')
		;//ft_putnbr_base(va_arg(args, unsigned int), "0123456789")
	else if (c == 'x')
		;//ft_putnbr_base(va_arg(args, int), "0123456789abcdef")
	else
		;//ft_putnbr_base(va_arg(args, unsigned int), "0123456789")
}
int	ft_print_format(const char **format, va_list args)
{
	const char *format_set = "cspdiuxX%";
	if (is_in_set(**format, format_set))
		ft_format(**format, args);
	else
		return (-1);
	return (0);
}

int 	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_print_format(&format, args) < 0)
				return (-1);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (0);
}

int main (void)
{
	ft_printf("%c", 'a');
	return (0);
}